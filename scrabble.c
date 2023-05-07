#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Compute and return score for string
int compute_score(string word)
{
    int score = 0;
    for(int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}tr

// The strlen function is calculating the length of the string stored in "word".
// On line 42 each case will generate an index in the POINTS[] array.
// For example, if you typed the word "Hi": word[0] = 'H' = 72. 'A' = 65.
// In each execution of the loop a subtraction is done: POINTS[word[i] - 'A' == POINTS[word[0] - 'A'] ==
// == POINTS['O' - 'A'] == POINTS[72 - 65] == POINTS[7]
// Then the score will become "score = POINTS[7]"
// The next character is 'i', which will cause the program to perform the sum in "islower".
// POINTS[word[i] - 'a'] == POINTS[word[1] - 'a'] == POINTS['i' - 'a'] == POINTS[105 - 97] == POINTS[ 8]
// So score1 = POINTS[7] + POINTS[8] == score1 = 2 + 4 == score1 = 6.
