#include <stdio.h>
#include <string.h>

char* simplify(char text[]) {
    int deletions = 0, k = 0;
    int length = strlen(text);
    char compressed[length + 1];
    
    for (int i = 0; i < length; i++) {
        if (i < length - 1 && text[i] == text[i + 1]) {
            deletions++;
        } else {
            compressed[k] = text[i];
            k++;
        }
    }
    compressed[k] = '\0';
    printf("%s with %d deletions\n", compressed, deletions);
    return compressed;
}

int main() {
    simplify("coooleh");
    simplify("wwwwwwwwwwwwwwoooooooooowwwwwwwwwww");
    simplify("yooooooooooyooooooooooooo");
    return 0;
}