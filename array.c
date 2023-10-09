#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void increase_array(int arg_v[]);
int length(int v[]);

int max_num(int arg_v[], int n) {
    int i, max_num = arg_v[0];
    for (i=1; i<n; ++i){
        if (arg_v[i] > max_num) {
            max_num = arg_v[i];
        }
    }
    return max_num;
};

int main(void) {
    // srand(time(0));
    // int counter_array[6] = {0, 0, 0, 0, 0, 0};
    // // // 最少指定一個，不指定自動為0
    // // int counter_array[6] = {0};
    // // // 省略個數會自動抓元素個數
    // // int counter_array[] = {0, 0, 0, 0, 0, 0};
    // int i;
    // for (i=1; i<=6000; ++i) {
    //     int dice = rand() % 6;
    //     counter_array[dice]++;
    // }
    // for (i=0; i < sizeof(counter_array) / sizeof(counter_array[0]); ++i) {
    //     printf("%d\n", counter_array[i]);
    // }
    // return 0;

    // int i, n, v[3][3];
    // // {{1,2,3}, {4,5,6}, {7,8,9}}
    // for (i=0; i<3; ++i){
    //     for (n=0; n<3; ++n){
    //         v[i][n] = 3 * i + n + 1;
    //     }
    // }
    // for (i=0; i<3; ++i){
    //     for (n=0; n<3; ++n){
    //         printf("%d\n", v[i][n]);
    //     }
    // }
    // return 0;

    // srand(time(0));
    // int i, n[10];
    // for (i=0; i<10; ++i) {
    //     n[i] = rand() % 10;
    // }
    // // int v = n; // (X)
    // int v[10];
    // for (i=0; i<10; ++i){
    //     v[i] = n[i];
    // }
    // return 0;

    // // 陣列是指向位址，所以在function裏改變後main print 出的值也會改變
    // int i, v[10] = {0,1,2,3,4,5,6,7,8,9};
    // printf("%d\n", v[10]); //未定義行為，但不會出錯
    // printf("%zu, %zu\n", sizeof(v), sizeof(*v));
    // increase_array(v);
    // for (i=0; i<10; ++i){
    //     printf("%d\n", v[i]);
    // }
    // printf("%d\n", max_num(v, 10));

    // 利用保留值算array長度
    int v[5] = {1,2,3,4,-1};
    printf("%d\n", length(v));
}

void increase_array(int arg_v[]) {
    int i;
    printf("%zu\n", sizeof(arg_v));// 不是宣告的array, 而是一個位址
    for (i=0; i<10; ++i){
        arg_v[i]++;
    }
    // return arg_v; // (X)
}

int length(int v[]) {
    int i;
    while (v[i]!=-1){
        i++;
    }
    return i;
}