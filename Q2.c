#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Input the string: ");
    fgets(input, sizeof(input), stdin);
    int length = strlen(input);
    int frequency[27] = {0};
    int printedFlag[27] = {0};

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            frequency[26]++;
        } else {
            frequency[input[i] - 'a']++;
        }
    }

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            if (!printedFlag[26]) {
                printf("'%c' : %d\n", input[i], frequency[26]);
                printedFlag[26]++;
            }
        } else if (!printedFlag[input[i] - 'a']) {
            printf("'%c' : %d\n", input[i], frequency[input[i] % 97]);
            printedFlag[input[i] - 'a']++;
        }
    }

    return 0;
}