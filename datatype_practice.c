#include <stdio.h>
#include <limits.h>

// int main() {
//     // int integer1;
//     // int integer2;
//     // int sum;
//     int integer1, integer2, sum;
//     printf("Please enter the first integer: ");
//     ////////////////////////////////
//     //scanf(input, var address)
//     // %d 讀十進位整數
//     // &integer1 => 取址運算子，取得integer1在記憶體中的位址編號
//     ////////////////////////////////
//     scanf("%d", &integer1);
//     printf("Please enter the second integer: ");
//     scanf("%d", &integer2);
//     sum = integer1 + integer2;
//     printf("Sum is %d. \n", sum);
//     return 0;
// }

int main() {
    // //無號整數超過d有號可表示範圍：會overflow(無號應以無號表示)
    // unsigned int num = 3000000000;
    int c = 1000000000000;
    // printf("int: %d. \n", num); // int: -1294967296.
    // printf("int: %u. \n", num); // int: 3000000000.
    // printf("%d\n", INT_MIN); // -2147483648
    // printf("%d\n", INT_MAX); // 2147483647
    printf("%u\n", c);// 3567587328 = c % (UINT_MAX+1)
    printf("%u\n", UINT_MAX); // 4294967295

    // // float 與 double 因為bit為01儲存而存在精度的差別
    // float a = 123.45;
    // double b = 123.45;
    // printf("%f\n", a); // 123.449997
    // printf("%f\n", b); // 123.450000

    // // int +-*/ int = int
    // // 123 -> int, long int; 123.45 -> double; 123.45f -> float
    // double c = 10 / 3;
    // double d = 10 / 3.;
    // double e = 10 / (double) 3;
    // printf("%f\n", c); // 3.0000
    // printf("%f\n", d); // 3.3333
    // printf("%f\n", e); // 3.3333

    char ch = 'A' + 1;
    char ch2 = 'A' + '1';
    printf("%c\n", ch);
    printf("%c\n", ch2);

    return 0;
}