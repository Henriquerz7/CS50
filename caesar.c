/* The Caesar cipher is a substitution cipher where each letter in the plaintext is shifted a certain number of positions down or up the alphabet. The number of positions to shift is known as the "key" or "cipher key." For example, with a key of 3, "A" would be encrypted as "D," "B" as "E," and so on. If the shift reaches the end of the alphabet, it wraps around to the beginning.

The decryption process simply involves shifting the letters in the opposite direction by the same key. By using the same key, the original plaintext can be recovered from the ciphertext.

While the Caesar cipher is straightforward, it is considered highly insecure for modern cryptography. It can be easily broken using brute-force or frequency analysis techniques. However, it serves as an essential foundation for understanding more complex encryption algorithms. */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if the user entered the correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if the key consists of only digits
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key from string to integer
    int key = atoi(argv[1]);

    // Prompt the user to input the plaintext
    string plaintext = get_string("Plaintext: ");

    int n = strlen(plaintext);

    // Apply the Caesar cipher to each character in the plaintext
    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (islower(plaintext[i]))
            {
                // Encrypt lowercase character
                plaintext[i] = ((plaintext[i] - 'a') + key) % 26 + 'a';
            }
            else
            {
                // Encrypt uppercase character
                plaintext[i] = ((plaintext[i] - 'A') + key) % 26 + 'A';
            }
        }
    }

    // Print the ciphertext in a single line
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
