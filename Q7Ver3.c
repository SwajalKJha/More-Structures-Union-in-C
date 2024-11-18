#include<stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct employee{
	char *name;
	char *address;
	float salary;
}emp_t;

int main()
{
	emp_t *sptr;
	sptr = (emp_t *)malloc(sizeof(struct employee));

	if(sptr == NULL)
	{
		return -1;
	}
	// Take input
	char temp[100];
	printf("Enter name: ");
	scanf("%[^\n]s",temp);
	
	int len = strlen(temp);
	sptr->name= (char *)malloc(sizeof(char)*(len+1));
	
	// copy temp tp sptr->name
	strcpy(sptr->name,temp);
	
	free(sptr->name);
	free(sptr);
	
	return 0;
}
