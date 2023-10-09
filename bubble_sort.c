#include <stdio.h>

int main(void){
    int unsort_array[6] = {9,8,7,6,5,4};
    int sizeof_array = sizeof(unsort_array) / sizeof(unsort_array[0]);
    int i, n;
    for (i=1; i<sizeof_array; ++i){
        for (n=0; n<sizeof_array-i; ++n){
            if (unsort_array[n] > unsort_array[n+1]) {
                int temp = unsort_array[n];
                unsort_array[n] = unsort_array[n+1];
                unsort_array[n+1] = temp;
            }
        }
    }
    for (i=0; i<sizeof_array; ++i){
        printf("%d\n", unsort_array[i]);
    }
}