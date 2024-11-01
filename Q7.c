#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int points = 0;
char grid[6][5];
char gridTransposed[5][6];
char rollNumber[5];
char searchTerm[6];

char promptInput();
void displayGrid();
void checkWord(char searchTerm[]);
void transposeGrid(char grid[6][5]);

int main() {
    printf("Enter your (4-digit) roll number: ");
    scanf("%4s", rollNumber);
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    displayGrid();
    do {
        promptInput();
        checkWord(searchTerm);
    } while (strcasecmp(searchTerm, "END") != 0);
    return 0;
}

void displayGrid() {
    printf("PRESS(q): quit\n");
    srand(time(0));
    for (int i = 0; i < 6; i++) {
        printf("---------------------\n");
        for (int j = 0; j < 5; j++) {
            if (i == 5 && (j < 4)) {
                grid[5][j] = rollNumber[j];
            } else {
                grid[i][j] = 'A' + rand() % 26;
            }
            printf("| %c ", grid[i][j]);
        }
        printf("|\n");
    }
    printf("---------------------\n");
}

char promptInput() {
    printf("string: ");
    scanf("%s", searchTerm);
    strupr(searchTerm);
    return searchTerm[0];
}

void transposeGrid(char grid[6][5]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            gridTransposed[j][i] = grid[i][j];
        }
    }
}

void checkWord(char searchTerm[]) {
    int len = strlen(searchTerm);
    int found = 0;
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 5 - len; j++) {
            if (strncasecmp(&grid[i][j], searchTerm, len) == 0) {
                printf("%s is Present. Score %d\n", searchTerm, ++points);
                found = 1;
            }
        }
    }
    
    if (!found) {
        transposeGrid(grid);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j <= 6 - len; j++) {
                if (strncasecmp(&gridTransposed[i][j], searchTerm, len) == 0) {
                    printf("%s is Present. Score %d\n", searchTerm, ++points);
                    found = 1;
                }
            }
        }
    }
    
    if (!found) {
        printf("%s is not Present. Score %d\n", searchTerm, --points);
    }
}