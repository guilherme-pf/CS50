import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    user_id = session["user_id"]

    transactions_db = db.execute(
        "SELECT symbol, SUM(shares) AS shares, price FROM transactions WHERE user_id = ? GROUP BY symbol", user_id)
    cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    cash = float(cash_db[0]["cash"])

    return render_template("index.html", database=transactions_db, cash=cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol")
        # Turning user input str to int
        try:
            shares = float(request.form.get("shares"))
        except ValueError:
            return apology("Number of shares must be a positive integer number")

        if symbol == "":
            return apology("Symbol can't be blank")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Stock doesn't exist")

        if shares < 0:
            return apology("Number of shares must be a positive integer number")

        if shares > 1 and shares % 2 != 0:
            return apology("Number of shares must be a positive integer number")

        buy_value = shares * stock["price"]

        # checking if the user has enough money to the transaction
        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash < buy_value:
            return apology("Transaction value exceeds avaiable cash!")

        new_cash = user_cash - buy_value
        # update the cash avaiable from the user
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        date = datetime.datetime.now()

        # updating the table transactions
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], shares, stock["price"], date)

        flash("Transaction Complete")

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    user_id = session["user_id"]
    transactions_db = db.execute("SELECT * FROM transactions WHERE user_id = ?", user_id)
    return render_template("history.html", transactions=transactions_db)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":

        symbol = request.form.get("symbol")

        if symbol == "":
            return apology("Symbol can't be blank")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Stock doesn't exist")

        return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    # Register user
    if (request.method == "POST"):
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        hash_password = generate_password_hash(password)

        if username == "":
            return apology("Username can't be blank")

        if password == "":
            return apology("Password can't be blank")

        if confirmation == "":
            return apology("Confirm Password can't be blank")

        if password != confirmation:
            return apology("Passwords don't match!")
        # Checking if the username exists ("CREATE UNIQUE INDEX username on users (username))
        try:
            db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash_password)
            return render_template("login.html")
        except:
            return apology("Username not avaiable")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    if request.method == "GET":
        user_id = session["user_id"]
        symbols_avaiable = db.execute(
            "SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)
        return render_template("sell.html", symbols=[i["symbol"] for i in symbols_avaiable])
    else:
        symbol = request.form.get("symbol")
        # Turning user input str to int
        try:
            shares = float(request.form.get("shares"))
        except ValueError:
            return apology("Number of shares must be a positive integer number")

        # restrictions to input symbol and number of shares
        if symbol == "":
            return apology("Symbol can't be blank")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Stock doesn't exist")

        if shares < 0:
            return apology("Number of shares must be a positive integer number")

        if shares > 1 and shares % 2 != 0:
            return apology("Number of shares must be a positive integer number")

        user_id = session["user_id"]

        shares_avaiable_db = db.execute(
            "SELECT SUM(shares) AS shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)
        shares_avaiable = shares_avaiable_db[0]["shares"]

        if shares > shares_avaiable:
            return apology("Amount of shares not avaiable to sell")

        sell_value = shares * stock["price"]

        user_cash_db = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash_db[0]["cash"]

        new_cash = user_cash + sell_value
        # update the cash avaiable from the user
        db.execute("UPDATE users SET cash = ? WHERE id = ?", new_cash, user_id)

        date = datetime.datetime.now()

        # updating the table transactions
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES(?, ?, ?, ?, ?)",
                   user_id, stock["symbol"], (-1)*shares, stock["price"], date)

        flash("Transaction Complete")

        return redirect("/")
