#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


//Lesson 7

void multiAriphmetics(int64_t *summ, int32_t *diff, int64_t *mult, int32_t *div);

int main(int argc, char **argv) {
    int64_t summ; //Sum of numbers
    int32_t diff; //Difference of numbers
    int64_t mult; //Multiplication of numbers
    int32_t div; //Division of numbers
    printf("Enter 2 numbers in turn, after entering each of the numbers press 'Enter':\n");
    multiAriphmetics(&summ, &diff, &mult, &div);
    printf("summ %"PRId64"\ndiff %"PRId32"\nmult %"PRId64"\ndiv %"PRId32"\n", summ, diff, mult, div);
    return 0;
}


void multiAriphmetics(int64_t *summ, int32_t *diff, int64_t *mult, int32_t *div){
    int64_t input1; //First entered number
    int64_t input2; //Second entered number
    scanf("%"SCNd64"\n", &input1);
    scanf("%"SCNd64, &input2);
    if (input2 == 0){
        printf("Error: Division by 0");
        exit(1);
    }
    if (input1 < -2147483648 || input2 < -2147483648){
        printf("Error: The entered number cannot be less than -2147483648");
        exit(2);
    }
    if (input1 > 2147483647 || input2 > 2147483647){
        printf("Error: The entered number cannot be more 2147483647");
        exit(3);
    }
    *summ = input1 + input2;
    *diff = input1 - input2;
    *mult = input1 * input2;
    *div = input1 / input2;
}