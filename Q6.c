#include<stdio.h>
#include<stddef.h>

//a
struct student{
	char name[20];
	int age;
	union ID{
		long int aadhar;
		long int passport;
	}uvar;
	char address[100];
	int marks[5];
}svar;

//b
//union A{
//	struct student;
//}a;

//c
//union B{
//	union A;
//}b;

int main()
{
	printf("%ld\n", sizeof(svar));
	printf("%ld\n", offsetof(struct student, name));
	printf("%ld\n", offsetof(struct student, age));
	printf("%ld\n", offsetof(struct student, uvar));
	printf("%ld\n", offsetof(struct student, uvar.aadhar));
	printf("%ld\n", offsetof(struct student, uvar.passport));
	printf("%ld\n", offsetof(struct student, address));
	printf("%ld\n", offsetof(struct student, marks));
	return 0;
}
