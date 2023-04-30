// Well, suppose that a cashier owes a customer some change and in that cashier’s drawer are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢). The problem to be solved is to // decide which coins and how many of each to hand to the customer.
// In cash.c, the user is prompted for the number of cents a customer owes and then prints the smallest number of coins with which this change can be made.

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    float dollar;
    do
    {
        dollar = get_float("Change owed: ");
    }
    while(dollar <= 0);

    int cents = round(dollar * 100);
    int coins = 0;

    while (cents > 24)
    {
        cents -= 25; // cents = cents - 25;
        coins ++;
    }

    while (cents > 9)
    {
        cents -= 10; // cents = cents - 10;
        coins ++;
    }

    while (cents > 4)
    {
        cents -= 5; // cents = cents - 5;
        coins ++;
    }

    while (cents > 0)
    {
        cents -= 1; // cents = cents - 1;
        coins ++;
    }

    printf("Você irá precisar de %i moedas\n", coins);
    return 0;
}
