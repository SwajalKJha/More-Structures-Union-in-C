#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct employee{
	unsigned int empid : 10;
	char name[20];
	float salary;
	int yoj;
	char gender;
	unsigned int age : 7;
	union ID {
			char adhar[20];
			char passport[20];
			char voter[20];
	}uid;
	int id_choice;
}emp_t;

int main()
{
	emp_t *var;
	var = (emp_t *)malloc(sizeof(struct employee));
	//sptr = (struct employee *)malloc(sizeof(struct employee));
	if(var != NULL)
	{
		printf("Memory Allocation Successful\n");
	}
	else
	{
		printf("Memory Allocation Unsuccessful... Exiting...\n");
		return -1;
	}
	

	unsigned int temp;
	// take inputs
	printf("Enter employee ID :");
	scanf("%u", &temp);
	var->empid = temp;
	getchar();
	printf("Enter name: ");
	scanf("%s[^\n]s", var->name);
	getchar();
	printf("Enter salary: ");
	scanf("%f", &var->salary);
	getchar();
	printf("Enter year of joining: ");
	scanf("%d", &var->yoj);
	getchar();
	printf("Enter Gender (M/F): ");
	scanf("%c", &var->gender);
	getchar();
	printf("Enter age (18 - 65): ");
	scanf("%u", &temp);
	var->age = temp;
	getchar(); 
	
	do {
	printf("Enter the choice for ID, 1:Adhar, 2:Passport, 3:Voter ID \n (any 1)\n ");
	scanf("%d", &var->id_choice);
	getchar(); 
	switch(var->id_choice) {
		case 1:
			printf("Enter Adhar card ID:");
			scanf("%[^\n]s", var->uid.adhar);
			break;
			
		case 2:
			printf("Enter Passport ID:");
			scanf("%[^\n]s", var->uid.passport);
			break;
			
		case 3:
			printf("Enter adhar card ID:");
			scanf("%[^\n]s", var->uid.adhar);
			break;
			
		default:
			printf("Invalid....Try again!!!\n");
	} 
	} while (var->id_choice != 1 && var->id_choice != 2 && var->id_choice != 3);
	
	    char search_name[30];
	    printf("Enter a name to search: ");
	    getchar();  
	    scanf("%[^\n]s", search_name);

	    if (strcmp(search_name, var->name) == 0)
	    {
		printf("Employee with name %s found\n", search_name);
	    }
	    else
	    {
		printf("%s name not found\n", search_name);
	    }


	    unsigned int search_empid;
	    printf("Enter employee ID to search: ");
	    scanf("%u", &search_empid);

	    if (search_empid == var->empid)
	    {
		printf("Employee with ID %u found\n", search_empid);
	    }
	    else
	    {
		printf("Employee with ID %u not found\n", search_empid);
	    }

    free(var);
    return 0;

}
