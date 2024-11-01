#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int BinToDec(int binNum) {
    int decNum = 0, base = 1, digit;
    while (binNum > 0) {
        digit = binNum % 10;
        if (digit != 0 && digit != 1) {
            printf("Invalid binary input.\n");
            return -1;
        }
        decNum += digit * base;
        binNum /= 10;
        base *= 2;
    }
    return decNum;
}

int DecToBin(int decNum) {
    int binNum = 0, base = 1;
    while (decNum > 0) {
        binNum += (decNum % 2) * base;
        decNum /= 2;
        base *= 10;
    }
    return binNum;
}

void DecToHex(int decNum) {
    if (decNum < 0) {
        printf("Invalid decimal input.\n");
        return;
    }
    char hexNum[100];
    int i = 0;
    while (decNum != 0) {
        int rem = decNum % 16;
        if (rem < 10) hexNum[i++] = rem + '0';
        else hexNum[i++] = rem - 10 + 'A';
        decNum /= 16;
    }
    for (int j = i - 1; j >= 0; j--) printf("%c", hexNum[j]);
    printf("\n");
}

void HexToDec(char hexNum[]) {
    int length = strlen(hexNum);
    int base = 1, decNum = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9') decNum += (hexNum[i] - '0') * base;
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') decNum += (hexNum[i] - 'A' + 10) * base;
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f') decNum += (hexNum[i] - 'a' + 10) * base;
        else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }
    printf("%d\n", decNum);
}

void BinToHex(int binNum) {
    int decNum = BinToDec(binNum);
    if (decNum == -1) return;
    DecToHex(decNum);
}

void HexToBin(char hexNum[]) {
    int decNum = 0;
    int length = strlen(hexNum);
    int base = 1;
    for (int i = length - 1; i >= 0; i--) {
        if (hexNum[i] >= '0' && hexNum[i] <= '9') decNum += (hexNum[i] - '0') * base;
        else if (hexNum[i] >= 'A' && hexNum[i] <= 'F') decNum += (hexNum[i] - 'A' + 10) * base;
        else if (hexNum[i] >= 'a' && hexNum[i] <= 'f') decNum += (hexNum[i] - 'a' + 10) * base;
        else {
            printf("Invalid hexadecimal input.\n");
            return;
        }
        base *= 16;
    }
    printf("%d\n", DecToBin(decNum));
}

int main() {
    int option, number;
    char hexNum[100];
    while (1) {
        printf("\n--- Number Conversion Program ---\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Hexadecimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Binary to Hexadecimal\n");
        printf("6. Hexadecimal to Binary\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        if (option == 1) {
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Decimal: %d\n", BinToDec(number));
        } else if (option == 2) {
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Binary: %d\n", DecToBin(number));
        } else if (option == 3) {
            printf("Enter a decimal number: ");
            scanf("%d", &number);
            printf("Hexadecimal: ");
            DecToHex(number);
        } else if (option == 4) {
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            printf("Decimal: ");
            HexToDec(hexNum);
        } else if (option == 5) {
            printf("Enter a binary number: ");
            scanf("%d", &number);
            printf("Hexadecimal: ");
            BinToHex(number);
        } else if (option == 6) {
            printf("Enter a hexadecimal number: ");
            scanf("%s", hexNum);
            printf("Binary: ");
            HexToBin(hexNum);
        } else if (option == 7) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}