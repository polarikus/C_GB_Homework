#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>

//Lesson 5
uint16_t get_input(void);
void validate_input(int32_t input);
uint16_t calculate_prime_numbers_while(uint16_t number);
uint16_t calculate_prime_numbers_for(uint16_t number);

int main(int argc, char **argv) {
    uint16_t input_number = get_input();
    printf("Prime numbers counted in a loop 'while': %"PRIu16"\n", calculate_prime_numbers_while(input_number));
    printf("..................................................\n");
    printf("Prime numbers counted in a loop 'for': %"PRIu16"\n", calculate_prime_numbers_for(input_number));
    return 0;
}

uint16_t get_input(void){
    int32_t input = 0;
    printf("Input number:\n");
    scanf("%"SCNd32, &input);
    validate_input(input);
    return input;
}

void validate_input(int32_t input){
    if (input < 0){
        printf("Invalid input: number must be unsigned!\n");
        exit(1);
    }
    if (input > 65535){
        printf("Invalid input: number must be less than 65 536\n");
        exit(2);
    }
    if (input == 0){
        printf("Invalid input: number must be more than 0\n");
        exit(3);
    }
}

uint16_t calculate_prime_numbers_while(uint16_t number){
    uint16_t result = 0;
    uint16_t ctr1;
    uint16_t ctr2;
    printf("Starting print prime numbers a 'while' loop:\n");
    ctr1 = 2;
    while (ctr1 <= number){
        ctr2 = 2;
        bool prime = true;
        while (ctr2 * ctr2 <= ctr1){
            //printf("ctr1: %"PRIu16  " ctr2: %"PRIu16"\n", ctr1, ctr2);
            if (ctr1 % ctr2 == 0){
                prime = false;
                break;
            }
            ctr2++;
        }
            if (prime == true){
                //printf("DUBUG1: %"PRIu16" ", ctr1 % (ctr2 - 1));
                //printf("DUBUG2: %"PRIu16" ", ctr2);
                result ++;
                printf("%"PRIu16"\n", ctr1);
            }
        ctr1++;
    }
    return result;
}
uint16_t calculate_prime_numbers_for(uint16_t number){
    uint16_t result = 0;
    printf("Starting print prime numbers a loop 'for':\n");
    for (uint16_t i=2; i<number; i++)
    {
        bool prime=true;
        for (uint16_t j=2; j*j<=i; j++)
        {
            if (i % j == 0)
            {
                prime=false;
                break;
            }
        }
        if(prime){
            printf("%"PRIu16"\n", i);
            result++;
        }
    }
    return result;
}