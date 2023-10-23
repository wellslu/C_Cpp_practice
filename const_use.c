#include <stdio.h>
#include <string.h>

int main(void) {
    int a=3;
    const int b=3;

    a = 4; //(O)
    //b = 4; //(X)

    printf("%d\n", a);
    printf("%d\n", b);

    char w1[] = "test";
    char *w2 = "test";
    const char *w3 = "test";

    w1[0] = 'T'; //(O)
    // w2[0] = 'T'; //(X) 未定義行為
    // w3[0] = 'T'; //(X)

    printf("%s\n", w1);
    printf("%s\n", w2);
    printf("%s\n", w3);

    // w1 = w2; //(X)
    // w1 = w3; //(X)
    w2 = w1; //(O)
    // w2 = w3; //(X)
    w3 = w1; //(O)
    w3 = w2; //(O)

    char source[5] = "test";
    char destination[5];
    strcpy(destination, source);
    printf("%s\n", destination);

    return 0;
}