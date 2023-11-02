#include <stdio.h>
#include <string.h>

int main() {
    // char strA[3][4] = {"How", "are", "you"};
    // const char *strB[3] = {"How", "are", "you"};
    // strA[2][0] = 'Y'; //(O)
    // // strA[0] = "What"; //(X)
    // // strB[2][0] = 'Y'; //(X)
    // strB[0] = "What"; //(O)

    // char strA[3][4] = {"How", "are", "you"};
    // char *strB[3] = {strA[0], strA[1], strA[2]};
    // strB[2][0] = 'Y'; //(O)
    // char strC[5] = "What";
    // strB[0] = strC; //(O)
    // strB[0][0] = 'w'; //(O)

    char raw[5000];
    char *str[100];
    char input[50];
    int size = 0, len = 0;
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "end") == 0) break;
        str[len] = raw + size;
        strcpy(str[len], input);
        size+=strlen(input)+1;
        ++len;
    }
    printf("---------\n");
    int i;
    for (i=0; i<len; i++) {
        printf("%s ", str[i]);
    }
    printf("\n(%d, %d)\n", len, size);
}