#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 5
#define MAX_LEN 32

// Character replacement
char mutate_char(char c)
{
        switch (tolower(c))
        {
        case 'a':
                return '@';
        case 'e':
                return '3';
        case 'i':
                return '!';
        case 'l':
                return '1';
        case 'o':
                return '0';
        case 's':
                return '$';
        case 't':
                return '7';
        default:
                return c;
        }
}

// Word mutation: replacement + part in capital letters
void mutate_word(char *word, char *result)
{
        size_t len = strlen(word);
        for (size_t i = 0; i < len && i < MAX_LEN - 1; ++i)
        {
                char c = mutate_char(word[i]);
                result[i] = (i % 2 == 0) ? toupper(c) : c; // чередуем регистр
        }
        result[len] = '\0';
}

// Generating a random number and character
void append_random_tail(char *password)
{
        const char symbols[] = "!@#$%^&*()_+-=|";
        int number = rand() % 90 + 10; // 10–99
        char symbol = symbols[rand() % (sizeof(symbols) - 1)];

        char tail[8];
        sprintf(tail, "%d%c", number, symbol);
        strcat(password, tail);
}

int main()
{
        srand((unsigned int)time(NULL));

        char *words[MAX_WORDS];
        char buffer[MAX_LEN];
        int word_count;

        printf("How many words to use (1–%d): ", MAX_WORDS);
        scanf("%d", &word_count);

        while (getchar() != NULL)
                ; // clear the input buffer

        if (word_count < 1 || word_count > MAX_WORDS)
        {
                printf("Incorrect number of words\n");
                return 1;
        }

        for (int i = 0; i < word_count; ++i)
        {
                printf("Word %d: ", i + 1);
                fgets(buffer, MAX_LEN, stdin);
                buffer[strcspn(buffer, "\n")] = '\0'; // remove newline character

                words[i] = strdup(buffer); // allocate memory and copy the string
        }

        char password[256] = "";

        for (int i = 0; i < word_count; ++i)
        {
                char mutated[MAX_LEN];
                mutate_word(words[i], mutated);
                strcat(password, mutated);

                // Adding a separator between words
                if (i < word_count - 1)
                {
                        const char separators[] = "!#%^|";
                        char sep[2] = {separators[rand() % (sizeof(separators) - 1)], '\0'};
                        strcat(password, sep);
                }
        }

        append_random_tail(password);

        printf("\nGenerated password: %s\n", password);

        // freeing allocated memory for words
        for (int i = 0; i < word_count; ++i)
        {
                free(words[i]);
        }

        return 0;
}
