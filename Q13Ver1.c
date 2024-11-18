#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book{
	char title[30];
	char author[30];
	int isbn;
	int id;
	int cost;
};

void add(FILE *doc);
void display(FILE *doc);
void find(FILE *doc);
void filter(FILE *doc);
void quit(FILE *doc);

int main()
{	
	// do while loop to make this repeat multiple time till option quit is choosen
	do { 
		int num;
		printf("1. ADD A BOOK\n2. DISPLAY BOOKS\n3. FIND A BOOK BY ID\n4. FILTER BOOKS\n5. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &num);
		getchar();
		
		FILE *doc = fopen("library.txt", "a+"); // creating file at start to reduce argument passing on functions
		if(doc == NULL)
		{
			printf("\n Error while opening file....\n");
			return 0;
		}
		
		switch(num) //switch case for options
		{
			case 1: {add(doc); fclose(doc); break;} // closeing file after each function
			case 2: {display(doc); fclose(doc); break;}
			case 3: {find(doc); fclose(doc); break;}
			case 4: {filter(doc); fclose(doc); break;}
			case 5: {quit(doc); fclose(doc); return 0;}
		}
	} while(1);
}

void add(FILE *doc) // this will add book in doc
{
	int found = 0 , temp_id;
	struct book a;
	// asking user input
	printf("\nEnter book title: ");
	scanf("%s", a.title);
	getchar();
	printf("\nEnter book author name: ");
	scanf("%s", a.author);
	getchar();
	printf("\nEnter ISBN of book: ");
	scanf("%d", &a.isbn);
	getchar();
	
	//Checking that the book already exists or not
	do {
		found = 0; // Reset found for each ID check
		printf("\nEnter unique ID of book: ");
		scanf("%d", &temp_id);
		getchar();

		// Check if the ID already exists
		fseek(doc, 0, SEEK_SET); // Reset file pointer to the beginning
		
		struct book temp; // Temporary structure to read existing books
        	while (fscanf(doc, "Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", temp.title, temp.author, &temp.isbn, &temp.id, &temp.cost) != EOF)
        	{
		    if (temp.id == temp_id) // Compare with the entered ID
		    {
		        found = 1; // ID exists
		        break; // Exit the loop if found
		    }
		}
		
        	if(found)
        	{
		    printf("\nBook with this ID already exists. Please enter a unique ID.\n");
		    printf("Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", temp.title, temp.author, temp.isbn, temp.id, temp.cost);
		}
		else
		{
		    a.id = temp_id; // Assign only if the ID is unique
		}
        
    	} while(found); // Continue until a unique ID is found
    
	printf("\nEnter book's cost: ");
	scanf("%d", &a.cost);
	getchar();
	
	// saving / printing data on the doc
	fprintf(doc, "Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", a.title, a.author, a.isbn, a.id, a.cost);	
	printf("\nBook has been added successfully....\n");
	printf("----------------------------------------\n");
}
	
void display(FILE *doc) // displaying every data from book
{
	struct book d;
	
	//scaning doc till EOF End of File
    	while (fscanf(doc, "Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", d.title, d.author, &d.isbn, &d.id, &d.cost) != EOF) 
   	{
   		// printing data with seprations
	   	printf("----------------------------------------\n");
		printf("Title: %s\nAuthor: %s\nISBN: %d\nBook ID: %d\nBook cost: %d\n", d.title, d.author, d.isbn, d.id, d.cost);
		printf("----------------------------------------\n");
    	}
}

void find(FILE *doc) // finding book by ID
{
	int fid;
	struct book f;
	printf("\nEnter the ID of a book you want to find: ");
	scanf("%d", &fid);
	getchar();
	
	while (fscanf(doc, "Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", f.title, f.author, &f.isbn, &f.id, &f.cost) != EOF) 
   	{
   		// if id exists then it will print data
   		if(f.id == fid)
   		{
		   	printf("----------------------------------------\n");
			printf("Title: %s\nAuthor: %s\nISBN: %d\nBook ID: %d\nBook cost: %d\n", f.title, f.author, f.isbn, f.id, f.cost);
			printf("----------------------------------------\n");
		}
    	}
}
void filter(FILE *doc) // checking for multiple books by an author
{
	char fauthor[30];
	struct book flt;
	printf("\nEnter the author name you want to find: ");
	scanf("%s", fauthor);
	getchar();

	while (fscanf(doc, "Title:%s \nAuthor:%s \nISBN:%d \nBook ID:%d \nBook cost:%d \n", flt.title, flt.author, &flt.isbn, &flt.id, &flt.cost) != EOF) 
   	{
   		// comparing string of character of author name
   		if(strcmp(flt.author,fauthor) == 0)
   		{
		   	printf("----------------------------------------\n");
			printf("Title: %s\nAuthor: %s\nISBN: %d\nBook ID: %d\nBook cost: %d\n", flt.title, flt.author, flt.isbn, flt.id, flt.cost);
			printf("----------------------------------------\n");
		}
    	}
}
void quit(FILE *doc) // print quit or closing
{
	printf("\nExiting...");
}

