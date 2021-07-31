#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>


//Lesson 8

void task_1(void); //Exercise 1
void task_2(void); //Exercise 2
void task_3(void); //Exercise 3
void task_4(void); //Exercise 4

int main(int argc, char **argv) {
    task_4();
    return 0;
}

void task_1(void) {
    char input;
    int chars[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int max = chars[0];
    int ctr;
    int max_char;
    while ((input = getchar()) != '.') {
        if (input >= '0' && input <= '9') {
            chars[(input - '0')] = chars[(input - '0')] + 1;
        }
    }
    for (ctr = 0; ctr < 10; ctr++) {
        if (chars[ctr] > max) {
            max = chars[ctr];
            max_char = ctr;
        }
    }
    printf("Max: %d\n", max_char);
}

void task_2(void) {
    int sz = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int tmp = array[0];
    for (int i = 0; i < sz; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < sz - 1 ; ++i) {
        array[i] = array[i + 1];
    }
    array[sz - 1] = tmp;
    for (int i = 0; i < sz; ++i) {
       printf("%d ", array[i]);
    }

}

void task_3(void){
    int sz = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    for (int i = 0; i < sz; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    for (int i = 0; i < sz / 2 ; ++i) {
        int tmp = array[i];
        array[i] = array[sz - 1 -i];
        array[sz - 1 -i] = tmp;
    }
    for (int i = 0; i < sz; ++i) {
        printf("%d ", array[i]);
    }
}

void task_4(void){
    int sz = 10;
    int array[10] = {4, 2, 5, 1, 0, 3, 7, 8, 9, 0};
    for (int j = 0; j < sz - 1; ++j) {
        for (int i = 0; i < sz - i - 1 ; ++i) {
            if (array[i] > array[i + 1]){
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i+1] = tmp;
            }
        }
    }

    for (int i = 0; i < sz; ++i) {
        printf("%d ", array[i]);
    }
}