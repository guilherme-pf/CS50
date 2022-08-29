#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}
// Fucntion to ask how many cents is owed
int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("How many cents owed? ");
    }
    while (cents < 0);
    // Returning and keeping the amount owed (CENTS)
    return cents;
}
// First step of the solution is to find out how many quarters can you "fit" inside the amount owed, so you set the variable quarters to 0, and start a loop where you add 1 to the variable quarters everytime you subtract a quarter (25 cents) from the amount owed and the result is still higher than 25 cents. When the variable cents is lower than 25 you stop the loop and go to next function (dimes).
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters += 1;
    }

    return quarters;
}
// The logic here is the same, after subtracting all of of the quarters possible from the amount owed, we apply the same logic with dimes
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes += 1;
    }
    return dimes;
}
// Same logic with nickels, after subtracting all of the quarters and dimes possible from the amount owed
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickels += 1;
    }
    return nickels;
}
// Finally, after subtracting all of the quarters, dimes and nickels possible, the amount of pennies is the same as the cents left
int calculate_pennies(int cents)
{
    int pennies = 0;
    if (cents >= 1)
    {
        pennies = cents;
    }
    return pennies;
}
