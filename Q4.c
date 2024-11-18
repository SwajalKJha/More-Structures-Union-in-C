#include <stdio.h>

struct Person {
    char name[50];
    int age;
};

void fun(struct Person *p);

int main()
{
    struct Person p1;
    fun(&p1);
    printf("*************************************")
    printf("Name: %s", p1.name);
    printf("Age: %d\n", p1.age);
    return 0;
}
void fun(struct Person *p) 
{
    printf("Enter name: ");
    fgets(p->name, sizeof(p->name), stdin);

    printf("Enter age: ");
    scanf("%d", &p->age);
}

