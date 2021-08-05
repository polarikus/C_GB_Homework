#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

//Lesson 9

int32_t str_sum_digits(const char *cs);

bool test_my_function();

int32_t schet(int32_t num);

char* concat(const char *s1, const char *s2);


int main(int argc, char **argv) {
    //char str[100] = "21474642 21473647";
    //printf("%"PRId32"\n",str_sum_digits(str));
    for (int i = 0; i < 100; ++i) {
        if (test_my_function() == false){
            printf("Function not work!!\n");
        }
    }
    printf("Test complete!");

    return 0;
}

int32_t str_sum_digits(const char *cs){
    int64_t summStr = 0;
    int64_t tmp = 0;
    int32_t ctr = 0;
    while (cs[ctr]){
        if (cs[ctr] >= '0' && cs[ctr] <= '9'){
            if (tmp == 0){
                tmp = cs[ctr] - '0';
            } else{
                tmp = (tmp * 10) + cs[ctr] - '0';
            }
        }
        if (cs[ctr] == ' '){
            if (summStr + tmp > 2147483647 || summStr + tmp < -2147483648){
                printf("Error: The sum of numbers is greater than the maximum or minimum allowed type int32_t");
                exit(1);
            }
            summStr = summStr + tmp;
            tmp = 0;
        }
        ctr ++;
    }
    if (summStr + tmp > 2147483647 || summStr + tmp < -2147483648){
        printf("Error: The sum of numbers is greater than the maximum or minimum allowed type int32_t");
        exit(1);
    }
    summStr = summStr + tmp;
    return (int32_t)summStr;
}
int32_t schet(int32_t num)
{
    int32_t i;
    for (i=0; num!=0; i++, num=num/10){}

    return i;
};

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

bool test_my_function(){
    int32_t numbers[3];
    int64_t resultSumm = 0;
    int32_t funcSumm = 0;
    char* resultString = "";
    srand(time(NULL));
    for (int8_t i = 0; i < 3; ++i) {
        int32_t N = 0;
        char string[N];
        int32_t tmp = rand() % 700000;
        numbers[i] = tmp;
        resultSumm += tmp;
        N = schet(tmp) + 1;
        itoa(tmp, string, 10);
        if (i == 0){
            resultString = concat(resultString, string);
        } else{
            resultString = concat(resultString, concat(" ", string));
        }

    }
    funcSumm = str_sum_digits(resultString);
    free(resultString);
    if (funcSumm != resultSumm){
        return false;
    }

    return true;

}

