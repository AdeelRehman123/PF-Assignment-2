#include <stdio.h>

int main() {
    int data[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &data[i]);
    }
    
    int total = 4;
    printf("Horizontal Histogram\n");
    for (int i = 0; i < total; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < data[i]; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    printf("Vertical Histogram\n");
    int highest = data[0];
    for (int i = 0; i < 4; i++) {
        if (data[i] > highest && data[i] != highest) {
            highest = data[i];
        }
    }
    
    for (int i = highest; i > 0; i--) {
        for (int j = 0; j < total; j++) {
            if (data[j] >= i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}