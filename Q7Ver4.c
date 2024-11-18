#include<stdio.h>
#define MAX 1
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
	emp_t var[MAX]; // array of 10 employees
	unsigned int temp;
	// take inputs
	
	for(int i =0; i<MAX; i++)
	{
		printf("Enter employee ID :");
		scanf("%u", &temp);
		var[i].empid = temp;
		getchar();
		printf("Enter name: ");
		scanf("%s[^\n]s", var[i].name);
		getchar();
		printf("Enter salary: ");
		scanf("%f", &var[i].salary);
		getchar();
		printf("Enter year of joining: ");
		scanf("%d", &var[i].yoj);
		getchar();
		printf("Enter Gender (M/F): ");
		scanf("%c", &var[i].gender);
		getchar();
		printf("Enter age (18 - 65): ");
		scanf("%u", &temp);
		var[i].age = temp;
		getchar(); 
		
		do {
		printf("Enter the choice for ID, 1:Adhar, 2:Passport, 3:Voter ID \n (any 1)\n ");
		scanf("%d", &var[i].id_choice);
		getchar(); 
		
		switch(var[i].id_choice) 
		{
			case 1:
				printf("Enter Adhar card ID:");
				scanf("%[^\n]s", var[i].uid.adhar);
				break;
				
			case 2:
				printf("Enter Passport ID:");
				scanf("%[^\n]s", var[i].uid.passport);
				break;
				
			case 3:
				printf("Enter adhar card ID:");
				scanf("%[^\n]s", var[i].uid.adhar);
				break;
				
			default:
				printf("Invalid....Try again!!!\n");
		} 
		} while (var[i].id_choice != 1 && var[i].id_choice != 2 && var[i].id_choice != 3);
	}
	
	printf("**************************************************************************");
	for (int i = 0; i < MAX ; i++)
	{
		printf("Employee ID: %d\n",var[i].empid);
		printf("Employee Name: %s\n",var[i].name);
		printf("Employee Salary: %f\n",var[i].salary);
		printf("Employee yoj: %d\n",var[i].yoj);
		printf("Employee Gender: %c\n",var[i].gender);
		printf("Employee age: %d\n",var[i].age);
		printf("Employee ID Adhar/Passport/Voter: %s %s %s\n",var[i].uid.adhar, var[i].uid.passport, var[i].uid.voter);
	}
}
