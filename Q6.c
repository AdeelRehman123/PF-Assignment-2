#include <stdio.h>

int matchOutcome(int sticks);

int matchOutcome(int sticks) {
    if (sticks % 5 == 0) {
        return -1;
    } else {
        return sticks % 5;
    }
}

int main() {
    int matchCount;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &matchCount);
    printf("%d\n", matchOutcome(matchCount));
    return 0;
}