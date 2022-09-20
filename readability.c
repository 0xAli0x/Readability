#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Functions prototypes.
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int text_number = count_letters(text);
    int words_number = count_words(text);
    int sentences_number = count_sentences(text);
    float L = (float) text_number / (float) words_number * 100;
    float S = (float) sentences_number / (float) words_number * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf(" Grade %i\n", index);
    }
//printf("%i letters\n", text_number);
//printf("%i words\n", words_number);
//printf("%i sentences\n", sentences_number);
}
// Implementing functions:
// Counting letters in the text.
int count_letters(string text)
{
    int letters = 0;
    int i = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))

        {
            letters++;
        }
    }

    return letters;

}
// Counting words in the text.
int count_words(string text)
{
    int words = 1;
    int i = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))

        {
            words++;
        }
    }

    return words;
}
// Counting Sentences in the text.
int count_sentences(string text)
{
    int sentences = 0;
    int i = 0;
    for (i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')

        {
            sentences++;
        }
    }

    return sentences;
}


