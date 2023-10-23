#include <stdio.h>

void swap(int *, int *);
void sort(int *, int *);

int main(void) {
    // int count = 9;
    // int *countAddr = &count; // type * -> 指標, & -> 取址
    // int result = *countAddr; // * -> 間接運算子
    // printf("%d, %d, %d\n", count, *countAddr, result); // 9, 9, 9
    // *countAddr = 10;
    // printf("%d, %d, %d\n", count, *countAddr, result);

    // int a;
    // int *b;

    // a = count; // (O)
    // // b = count; // (X)

    int a = 5, b = 3;
    sort(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    int v[5] = {1,2,3,4,5};
    &v[0] + 1 == &v[1];
    &v[2] - 1 == & v[1];
    &v[2] - &v[1] == 1;
    // &v[0] + &v[1]; (X)
    0[v] == v[0]; // a[b] == *(a+b), 0[v] == *(0+v)

    int *n;
    n = v; // 隱性轉型陣列第一個元素記憶體位址, n = &v[0];
    n == &v[0]; // n == &v
    printf("%d\n", *n);
    n+1 == &v[0]+1; // *(n+1) == v[1]
    printf("%d\n", *(n+1));
    n[0] == *n; // n[0] == *v
    n[1] == *(n+1); // n[1] == *(v+1)

    int v2[5];
    int *p;
    for (p=v2; p!=v[5]; p++) {
        *p = 0;
    }
    while (p != v+5) {
        *p++ = 0; // *(p++) = 0
    }
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a =  *b;
    *b = t;
}

void sort(int *a, int *b) {
    if (*b < *a) {
        swap(a, b);
    }
}