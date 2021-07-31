#include <stdio.h>



//Lesson 8

void task_1(void); //Exercise 1
void task_2(void); //Exercise 2
void task_3(void); //Exercise 3
void task_4(void); //Exercise 4
void print_array(int *array, int sz);

int main(int argc, char **argv) {
    printf("--------------------- Exercise 1 ---------------------------\n");
    printf("Enter text consisting of Latin letters and numbers and ending with a dot:\n");
    task_1();
    printf("------------------------------------------------------------\n");
    printf("--------------------- Exercise 2 ---------------------------\n");
    task_2();
    printf("------------------------------------------------------------\n");
    printf("--------------------- Exercise 3 ---------------------------\n");
    task_3();
    printf("------------------------------------------------------------\n");
    printf("--------------------- Exercise 4 ---------------------------\n");
    task_4();
    printf("------------------------------------------------------------\n");
    return 0;
}

void print_array(int *array, int sz){
    for (int i = 0; i < sz; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void task_1(void) {
    char input;
    int chars[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int max = chars[0];
    int ctr;
    int max_char = 10;
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
    if (max_char != 10){
        printf("The most common number: %d\n", max_char);
    } else{
        printf("There are no numbers in the line\n");
    }
}

void task_2(void) {
    int sz = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int tmp = array[0];
    printf("Initial array:\n");
    print_array(array, sz);
    for (int i = 0; i < sz - 1 ; ++i) {
        array[i] = array[i + 1];
    }
    array[sz - 1] = tmp;

    printf("Cycle left an array by 1 element:\n");
    print_array(array, sz);
}

void task_3(void){
    int sz = 10;
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    printf("Initial array:\n");
    print_array(array, sz);
    for (int i = 0; i < sz / 2 ; ++i) {
        int tmp = array[i];
        array[i] = array[sz - 1 -i];
        array[sz - 1 -i] = tmp;
    }
    printf("Reverse Array:\n");
    print_array(array, sz);
}

void task_4(void){
    int sz = 10;
    int array[10] = {4, 2, 5, 1, 0, 3, 7, 8, 9, 0};
    printf("Initial array:\n");
    print_array(array, sz);
    for (int j = 0; j < sz - 1; ++j) {
        for (int i = 0; i < sz - i - 1 ; ++i) {
            if (array[i] > array[i + 1]){
                int tmp = array[i];
                array[i] = array[i + 1];
                array[i+1] = tmp;
            }
        }
    }
    printf("Ascending sorted array:\n");
    print_array(array, sz);
}