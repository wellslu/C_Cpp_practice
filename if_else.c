#include <stdio.h> 
#include <iso646.h>
// int main() {
//     int number;
//     int total;
//     scanf("%d", &number);
//     total = number * 300;
//     if (number * 300 > 3000) {
//         total = total * 0.8;
//     }
//     printf("%d\n", total);
//     return 0;
// }

// int main() {
//     int grade;
//     scanf("%d", &grade);
//     if (grade >= 60) {
//         printf("Pass\n");
//     } else if (grade >= 50) {
//         printf("Probably Pass\n");
//     } else {
//         printf("Fail\n");
//     }
//     return 0;
// }

int main() {
    int a, b;
    float answer = 0;
    char op;
    scanf("%d%c%d", &a, &op, &b);
    switch (op) {
        case 'p':
        case '+':
            answer = a + b;
            break;
        case '-':
            answer = a - b;
            break;
        case '*':
            answer = a * b;
            break;
        case '/':
            answer = a / b;
            break;
        default:
            printf("failed\n");
            break;
    }
    printf("%f\n", answer);
    return 0;
}