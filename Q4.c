#include <stdio.h>
#include <string.h>

int main() {
    char inputWords[6][4];
    char sortedWords[6][4], tempChar;
    char originalWords[6][4];
    int totalWords = 6;
    
    for (int i = 0; i < totalWords; i++) {
        printf("String %d: ", i + 1);
        scanf("%s", inputWords[i]);
    }

    for (int i = 0; i < totalWords; i++) {
        strcpy(originalWords[i], inputWords[i]);
    }

    for (int i = 0; i < totalWords; i++) {
        for (int j = 0; j < 3 - 1; j++) {
            for (int k = 0; k < 3 - 1 - j; k++) {
                if (inputWords[i][k] > inputWords[i][k + 1]) {
                    tempChar = inputWords[i][k];
                    inputWords[i][k] = inputWords[i][k + 1];
                    inputWords[i][k + 1] = tempChar;
                }
            }
        }
        strcpy(sortedWords[i], inputWords[i]);
    }

    int groupedWords[6] = {0};
    
    for (int i = 0; i < totalWords; i++) {
        if (!groupedWords[i]) {
            printf("[");
            for (int j = 0; j < totalWords; j++) {
                if (strcmp(sortedWords[i], sortedWords[j]) == 0 && !groupedWords[j]) {
                    printf("%s ", originalWords[j]);
                    groupedWords[j] = 1;
                }
            }
            printf("]\n");
        }
    }

    return 0;
}