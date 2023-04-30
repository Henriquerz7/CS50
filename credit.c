// Program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of // each’s format here in.

#include <cs50.h>
#include <stdio.h>

int main(void)

//  Get the card number
{
    long card;
    do
    {
        card = get_long("Insert card number: ");
    }
    while (card < 0);

//  Count algarisms
    int number_digits = 0;
    for (long i = card; i > 0; i /= 10)  //  i = i /10
    {
        number_digits++;
    }

//  If to check pattern
    if (number_digits < 13 || number_digits > 16 || number_digits == 14)
    {
        printf("INVALID\n");
        return 0;
    }

//  1 - Checksum (starting with penultimate)
    int checksum = 0;

    for (long i = card / 10; i > 0; i /=100)  //  i = i/100
    {
        int digit = i % 10;
        if (digit * 2 < 10)
        {
            checksum += (digit * 2);  //  checksum = checksum + (digit * 2);
        }
        else
        {
            checksum += ((digit * 2) % 10) + 1;  //  checksum = checksum + ((digit * 2) % 10) + 1;
        }
    }

//  2 - Checksum (starting with the last, just sum the digits)
    for (long i = card; i > 0; i /= 100)
    {
        int digit = i % 10;
        checksum += digit;
    }

//  Check if the last digit of the sum is equal to zero
    if (checksum % 10 != 0)  //  != is not iqual to (opposite of ==)
    {
        printf("INVALID\n");
        return 0;
    }

//  Take the 2 first digits
    long first_digits = card;
    for (int i = number_digits - 2; i > 0; i--)
    {
        first_digits /= 10;  //  first_digits = first_digits / 10;
    }

//  Check for American Express (AMEX)
    if ((number_digits == 15) && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }

//  Check for Master Card
    if ((number_digits == 16) && (first_digits > 50 && first_digits < 56))
    {
        printf("MASTERCARD\n");
        return 0;
    }

//  Check for VISA
    if ((number_digits == 13 || number_digits == 16) && (first_digits / 10 == 4))
    {
        printf("VISA\n");
        return 0;
    }
    printf ("INVALID\n");
}
