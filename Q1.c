#include <stdio.h>

int main() {
    int length = 5, idx = 0;
    int array[length];
    for (int i = 0; i < length; i++) {
        printf("Input element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    int smallest, secondSmallest;
    if (array[0] < array[1]) {
        smallest = array[0];
        secondSmallest = array[1];
    } else {
        smallest = array[1];
        secondSmallest = array[0];
    }
    for (int i = 2; i < length; i++) {
        if (array[i] < smallest) {
            int temp = smallest;
            smallest = array[i];
            secondSmallest = temp;
        } else if (array[i] < secondSmallest && array[i] != smallest) {
            secondSmallest = array[i];
        }
    }
    printf("The Second smallest element in the list is: %d\n", secondSmallest);
    return 0;
}