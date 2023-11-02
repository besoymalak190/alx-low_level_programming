#include <stdlib.h>
#include <stdio.h>

/**
 * strtow - Splits a string into words.
 * @str: The input string to be split.
 *
 * Return: A pointer to an array of strings (words).
 *         Each element of this array contains a single word, null-terminated.
 *         The last element of the returned array is NULL.
 *         Returns NULL if str is NULL or an empty string.
 */
char **strtow(char *str) {
    if (str == NULL || str[0] == '\0') {
        return NULL;
    }

    int word_count = 0;
    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            word_count++;
            in_word = 1;
        } else if (str[i] == ' ') {
            in_word = 0;
        }
    }

    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    int word_index = 0;
    int word_start = -1;
    in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            word_start = i;
            in_word = 1;
        } else if (str[i] == ' ') {
            if (in_word) {
                int word_length = i - word_start;
                words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
                if (words[word_index] == NULL) {
                    for (int j = 0; j < word_index; j++) {
                        free(words[j]);
                    }
                    free(words);
                    return NULL;
                }
                for (int j = 0; j < word_length; j++) {
                    words[word_index][j] = str[word_start + j];
                }
                words[word_index][word_length] = '\0';
                word_index++;
                in_word = 0;
            }
        }
    }

    if (in_word) {
        int word_length = strlen(str) - word_start;
        words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
        if (words[word_index] == NULL) {
            for (int j = 0; j <= word_index; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }
        for (int j = 0; j < word_length; j++) {
            words[word_index][j] = str[word_start + j];
        }
        words[word_index][word_length] = '\0';
        word_index++;
    }

    words[word_index] = NULL;

    return words;
}

