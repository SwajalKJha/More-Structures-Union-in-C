#include <stdio.h>

struct A {
    int x;
    double y;
    float z;
    char ch;
};

int main() 
{
    struct A a1;
    float *ptr_z = &a1.z;
    struct A *base_address = (struct A *)((char *)ptr_z - ((char *)&a1.z - (char *)&a1));
    
    printf("Original base address of a1: %p\n", (void *)&a1);
    printf("Calculated base address of a1: %p\n", (void *)base_address);
    return 0;
}

