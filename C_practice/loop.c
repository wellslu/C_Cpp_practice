#include <stdio.h>
int main() {
    int answer, guess, count;
    scanf("%d", &answer);
    // printf("Please guess a number:\n");
    // scanf("%d", &guess);
    // count = 0;
    // while (count == 0 || guess != answer) {
    //     printf("Please guess a number:\n");
    //     scanf("%d", &guess);
    //     count+=1;
    //     if (guess > answer) {
    //         printf("please guess smaller\n");
    //     } else {
    //         printf("please guess larger\n");
    //     }
    //     // printf("Please guess a number:\n");
    //     // scanf("%d", &guess);
    // }
    
    // count = 0;
    // do {
    //     printf("Please guess a number:\n");
    //     scanf("%d", &guess);
    //     count+=1;
    //     if (guess > answer) {
    //         printf("please guess smaller\n");
    //     } else if (guess < answer) {
    //         printf("please guess larger\n");
    //     }
    //     // printf("Please guess a number:\n");
    //     // scanf("%d", &guess);
    // } while (guess != answer);
    // printf("correct! %d\n", count);

    for (count = 0; count == 0 || answer != guess; ++count) {
        printf("Please guess a number:\n");
        scanf("%d", &guess);
        if (guess > answer) {
            printf("please guess smaller\n");
        } else if (guess < answer) {
            printf("please guess larger\n");
        }
    }
    printf("correct! %d\n", count);
}