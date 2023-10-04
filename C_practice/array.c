#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    int counter_array[6] = {0, 0, 0, 0, 0, 0};
    // // 最少指定一個，不指定自動為0
    // int counter_array[6] = {0};
    // // 省略個數會自動抓元素個數
    // int counter_array[] = {0, 0, 0, 0, 0, 0};
    int i;
    for (i=1; i<=6000; ++i) {
        int dice = rand() % 6;
        counter_array[dice]++;
    }
    for (i=0; i<sizeof(counter_array) / sizeof(counter_array[0]); ++i) {
        printf("%d\n", counter_array[i]);
    }
    return 0;
}