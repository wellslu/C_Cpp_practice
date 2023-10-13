#include <stdio.h>
int main(void) {
    int count = 9;
    int *countAddr = &count;
    int result = *countAddr; 
    printf("%d, %d, %d\n", count, *countAddr, result); // 9, 9, 9
    *countAddr = 10;
    printf("%d, %d, %d\n", count, *countAddr, result);

    // int a;
    // int *b;

    // a = count; // (O)
    // // b = count; // (X)

}