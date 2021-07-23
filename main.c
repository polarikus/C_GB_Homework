#include <stdio.h>


//Lesson 6

char str_replace(char ch);

int main(int argc, char **argv) {
    char input;
    while ((input = getchar()) != '\n'){
        putchar(str_replace(input));
    }

    return 0;
}

char str_replace(char ch){
    if(ch == ' '){
        return '\0';
    }

    if (ch >= 'a' && ch <= 'z'){
        return 'l';
    }

    if (ch >= 'A' && ch <= 'Z'){
        return 'u';
    }

    if (ch >= '0' && ch <= '9'){
        return 'd';
    }

    return '*';
}


