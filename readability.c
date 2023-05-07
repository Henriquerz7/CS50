#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    string text = get_string("Text: ");

    {
        for(int i = 0, n = strlen(text); i < n; i++)
        {
            if (isalpha(text[i]))
            letters++;

            else if (text[i] == ' ')
            words++;

            else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
        }
    }

    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int grade = (0.0588 * L) - (0.296 * S) - 15.8;

    if (grade > 15)
    printf("Grade 16+\n");

    else if (grade < 1)
    printf("Before Grade 1\n");

    else
    printf("Grade %i\n", grade);
}

// According to Scholastic, E.B. White’s Charlotte’s Web is between a second- and fourth-grade reading level, and Lois Lowry’s The Giver is between an eighth- and twelfth-grade reading level. What does it mean, though, for a book to be at a particular reading level?

// Well, in many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most appropriate. But an algorithm could likely figure that out too!

// So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too.

// A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level that is needed to understand some text. The formula is

// index = 0.0588 * L - 0.296 * S - 15.8

// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

// This program takes a text and determines its reading level.