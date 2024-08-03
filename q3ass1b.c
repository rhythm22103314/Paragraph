#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_PARAGRAPH_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

int findWordIndex(WordFreq words[], int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH];
    WordFreq words[MAX_WORDS];
    int numWords = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t,.!?;:");
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }

        int index = findWordIndex(words, numWords, token);
        if (index != -1) {
            words[index].count++;
        } else {
            strcpy(words[numWords].word, token);
            words[numWords].count = 1;
            numWords++;
        }

        token = strtok(NULL, " \n\t,.!?;:");
    }

    printf("Word frequencies:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}
