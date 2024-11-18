#include<stdio.h>
#include<string.h>

struct student {
	union ID {
		int ID;
	} id;
	char name[30];
	int marks[5];
	int sum;
	int max_marks;
	float CGPA;
};

float cgpa_fun(int sum, int max_marks);

int main() {	
	struct student students[100]; // Array to store data of up to 100 students
	int student_count = 0;  // Counter to track the number of students
	char choice;

	FILE *fptr;
	fptr = fopen("students_data.txt", "w"); // Open file to write student data
	
	if (fptr == NULL) {
		printf("Error opening file!\n");
		return 1;
	}

	do {
		struct student *ptr = &students[student_count];
		ptr->sum = 0; // Initialize sum for the current student

		// Get student name
		printf("Enter student's Name: ");
		scanf(" %[^\n]", ptr->name);  // Correct way to read string with spaces
		
		// Get student ID
		printf("Enter student's ID: ");
		scanf("%d", &ptr->id.ID);
		
		// Get marks for 5 subjects
		printf("Enter marks obtained in all 5 subjects: ");
		for(int i = 0; i < 5; i++) {
			scanf("%d", &ptr->marks[i]);
			ptr->sum += ptr->marks[i];
		}
		
		// Get max marks for all subjects
		printf("Enter max marks of all subjects: ");
		scanf("%d", &ptr->max_marks);
		
		// Calculate CGPA for the student
		ptr->CGPA = cgpa_fun(ptr->sum, ptr->max_marks);
		
		// Save the student's data to the file
		fprintf(fptr, "Student Name: %s\n", ptr->name);
		fprintf(fptr, "Student ID: %d\n", ptr->id.ID);
		fprintf(fptr, "Marks: ");
		for(int i = 0; i < 5; i++) {
			fprintf(fptr, "%d ", ptr->marks[i]);
		}
		fprintf(fptr, "\nSum of Marks: %d\n", ptr->sum);
		fprintf(fptr, "Max Marks: %d\n", ptr->max_marks);
		fprintf(fptr, "CGPA: %.2f\n", ptr->CGPA);
		fprintf(fptr, "---------------------------\n");

		// Print the result on screen
		printf("Total CGPA of student ID: %d is = %.2f\n", ptr->id.ID, ptr->CGPA);
		
		student_count++;  // Increment student count
		
		// Ask the user if they want to enter another student
		printf("Do you want to add another student? (y/n): ");
		scanf(" %c", &choice);  // Get user's choice
	} while (choice == 'y' || choice == 'Y');

	fclose(fptr);  // Close the file after saving all data

	printf("Data saved to students_data.txt\n");
	return 0;
}

// Function to calculate CGPA
float cgpa_fun(int sum, int max_marks) {
	return ((float)sum / (float)max_marks) * 10;  // Assume scaling of CGPA to 10
}

