# Restricions to negative numbers or strings
while True:
    try:
        change = float(input("Change owed: "))
        if change >= 0:
            break
    except:
        print("", end="")

# Logic to calculate minimum number of coins
quarters = int(change // 0.25)
change = round(change - (quarters * 0.25), 2)
dimes = int(change // 0.10)
change = round(change - (dimes * 0.10), 2)
nickels = int(change // 0.05)
change = round(change - (nickels * 0.05), 2)
pennies = int(change // 0.01)
total_coins = quarters + dimes + nickels + pennies
print(total_coins)