// I/O
#include <stdio.h>
// string process
#include <string.h>
// math operate
#include <math.h>
//memory management
#include <stdlib.h>
//
#include <time.h>

// global variable
int i;

int function_f(int);
int f(int);
int recurrence(int);

int function_t (int x) {
 return x + 5;
}

int c_standard_function_int (int x) {
    printf("sqrt %d = %f\n", x, sqrt(x));
    return 0;
}

int main (void) {
    // // local variable
    // int i = 3;
    // {
    //     int i = 4;
    //     printf("%d\n", i);
    // }
    // printf("%d\n", function_f(3));
    // printf("%d\n", function_t(3));
    // c_standard_function_int(3);
    // return 0;

    // //設定時間亂數軸，讓rand隨機seed
    // srand(time(0));
    // int i;
    // for (i = 1; i<=5; ++i) {
    //     int dice = rand() % 6 + 1;
    //     printf("%d\n", dice);
    // }

    // f(0);
    // return 0;

    int n;
    scanf("%d", &n);
    printf("%d\n", recurrence(n));
    return 0;
}

int function_f(int x) {
 return x + 4;
}

int f(int i) {
    if(i < 10) {
        printf("%d\n", i);
        return f(++i);
        // // 會0無限遞回，因為i++是傳i值到下一步，++i是傳i+1到下一步
        // return f(i++);
    } else {
        return i;
    }
}

int recurrence(int n) {
    if (n <= 2) {
        return n;
    }
    return recurrence(n-1) + recurrence(n-2);
}