#include <stdio.h>
#include <stdlib.h>

int main() {
    int* numbers = 0; // 0 空指標(NULL)
    int length = 0;
    while (1) {
        int input;
        scanf("%d", &input);
        if (input == 0) break;
        // // int larger[length+1]; //大誇胡結束後，larger所指向的list會被釋放(區域變數)，因此變成numbers指向一處未定義行為
        // int* larger = malloc(sizeof(int) * (length+1)); //不斷使用沒釋放的記憶體最後會倒是memory leak
        // for (int i=0; i<length; i++) larger[i] = numbers[i];
        // free(numbers); //先釋放前一輪的list
        // numbers = larger;
        numbers = realloc(numbers, sizeof(int) * (length+1)); // 用realloc簡化上面4行code
        numbers[length] = input;
        length++;
    }
    printf("Number: ");
    for (int i=0; i<length; i++) printf("%d ", numbers[i]);
    printf("\n");
    return 0;
}