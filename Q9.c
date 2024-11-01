#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char matrix[5][5];
void showGrid();
char getDirection();
char playerMove();

int main() {
    srand(time(NULL)); 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int randomValue = rand() % 10;
            if (randomValue < 2) {
                matrix[i][j] = 'X';
            } else if (randomValue < 5) {
                matrix[i][j] = ' ';
            } else {
                matrix[i][j] = 'I';
            }
        }
    }
    matrix[4][4] = 'P';
    
    int playerX = 4, playerY = 4, score = 0;
    showGrid();
    char direction;
    
    do {
        direction = playerMove();
        system("clear"); // system("cls") for Windows
        
        switch (direction) {
            case 'w':
                if (playerX > 0 && matrix[playerX - 1][playerY] != 'X') {
                    matrix[playerX][playerY] = ' ';
                    playerX--;
                    if (matrix[playerX][playerY] == 'I') {
                        score++;
                    }
                    matrix[playerX][playerY] = 'P';
                } else {
                    printf("Can't go there!\n");
                }
                break;
            case 'a':
                if (playerY > 0 && matrix[playerX][playerY - 1] != 'X') {
                    matrix[playerX][playerY] = ' ';
                    playerY--;
                    if (matrix[playerX][playerY] == 'I') {
                        score++;
                    }
                    matrix[playerX][playerY] = 'P';
                } else {
                    printf("Can't go there!\n");
                }
                break;
            case 's':
                if (playerX < 4 && matrix[playerX + 1][playerY] != 'X') {
                    matrix[playerX][playerY] = ' ';
                    playerX++;
                    if (matrix[playerX][playerY] == 'I') {
                        score++;
                    }
                    matrix[playerX][playerY] = 'P';
                } else {
                    printf("Can't go there!\n");
                }
                break;
            case 'd':
                if (playerY < 4 && matrix[playerX][playerY + 1] != 'X') {
                    matrix[playerX][playerY] = ' ';
                    playerY++;
                    if (matrix[playerX][playerY] == 'I') {
                        score++;
                    }
                    matrix[playerX][playerY] = 'P';
                } else {
                    printf("Can't go there!\n");
                }
                break;
            case 'q':
                printf("Quit!\n");
                printf("Your score is: %d\n", score);
                return 0;
            default:
                printf("Invalid move. Try again.\n");
        }
        showGrid();
        printf("Score: %d\n", score);
    } while (direction != 'q');
    
    return 0;
}

char getDirection() {
    char direction;
    printf("w: up, s: down, a: left, d: right, q: quit\n");
    scanf(" %c", &direction);
    return direction;
}

void showGrid() {
    printf("---------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("|");
        for (int j = 0; j < 5; j++) {
            printf(" %c |", matrix[i][j]);
        }
        printf("\n---------------------\n");
    }
}

char playerMove() {
    char move;
    do {
        move = getDirection();
    } while (move != 'w' && move != 's' && move != 'a' && move != 'd' && move != 'q');
    return move;
}