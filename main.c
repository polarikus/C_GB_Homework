#include <stdio.h>
#include <inttypes.h>
//Lesson 4
int main(int argc, char **argv) {
    uint32_t a;
    int8_t b;
    uint32_t result;
    char *str;
    printf("Enter number and shift value:\n");
    scanf("%"SCNu32"%"SCNd8, &a, &b);
    if (b > 0) {
		str = "right";
		result = a >> b;
    }
    else if (b < 0) {
		b = ~b + 1;
        result = a << b;
        str = "left";
    }
    else if(b == 0){
        printf("Zero shift is not defined");
        return 1;
    }
    else {
        printf("Unknown input type");
        return 2;
    }

    printf("Input: 0x%"PRIX32" shift %s %"PRId8"\n", a, str ,b);
    printf("Result: 0x%"PRIX32, result);

    return 0;

}

