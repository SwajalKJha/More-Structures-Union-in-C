#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct A {
    int x;
    char *str;
};

int main() {
    struct A a1 = {101, "abc"}, a2;

    a1.str = malloc(20);
    if (a1.str == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    a1.x = 10;
    strcpy(a1.str, "hello");

    printf("Enter a number and a string: ");
    scanf("%d%s", &a1.x, a1.str);

    a2.x = a1.x;
    a2.str = malloc(strlen(a1.str) + 1);
    strcpy(a2.str, a1.str);

    printf("a1 -> x: %d, str: %s\n", a1.x, a1.str);
    printf("a2 -> x: %d, str: %s\n", a2.x, a2.str);

    free(a1.str);
    free(a2.str);

    return 0;
}

