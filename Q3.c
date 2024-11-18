#include <stdio.h>

struct Address {
    char street[50];
    char city[50];
    int zip;
};
struct Person {
    char name[50];
    int age;
    struct Address addr;
};

int main() {
    struct Person p1;
    snprintf(p1.name, sizeof(p1.name), "CDAC");
    p1.age = 30;

    snprintf(p1.addr.street, sizeof(p1.addr.street), "Pachwati");
    snprintf(p1.addr.city, sizeof(p1.addr.city), "Pune");
    p1.addr.zip = 10001;
    
    printf("Name: %s\n", p1.name);
    printf("Age: %d\n", p1.age);
    printf("Address: %s, %s, %d\n", p1.addr.street, p1.addr.city, p1.addr.zip);
    return 0;
}

