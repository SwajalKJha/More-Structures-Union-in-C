#include <stdio.h>

struct book
{
    int id;
    int isbn;
    char title[30];
    char author[30];
    int cost;
};
void add(FILE *doc);
void display(FILE *doc);
void find(FILE *doc);
void filter(FILE *doc);
void quit(FILE *doc);
int main()
{
    do
    {
        char choice;
        printf("Welcome to Library\n");
        printf(" 1.Add\n 2.Display\n 3.Find\n 4.Filter\n 5.Quit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);
        getchar();

        FILE *doc = fopen("library.txt", "a+");
        if (doc == NULL)
        {
            printf("Initializing File Failed...Exiting,,,\n");
            return 0;
        }

        switch (choice)
        {
        case 1:
        {
            add(doc);
            break;
        }
        case 2:
        {
            display(doc);
            break;
        }
        case 3:
        {
            find(doc);
            break;
        }
        case 4:
        {
            filter(doc);
            break;
        }
        case 5:
        {
            quit(doc);
            fclose(doc);
            return 0;
        }
        default:
            printf("Invalid choice. Please try again.\n");
        }
        fclose(doc);
    } while (1);

    return 0;
}

void add(FILE *doc)
{
    struct book a;
    int found = 0;
    printf("Enter Book ID: ");
    scanf("%d", &a.id);
    getchar();

    rewind(doc);
    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d", &a.id, a.title, a.author, &a.isbn, &a.cost) != EOF)
    {
        if (a.id == a.id)
        {
            found = 1;
            printf("ID found...\n");
            printf("ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", a.id, a.title, a.author, a.isbn, a.cost);
            return;
        }
    }

    printf("Enter Book Title: ");
    scanf("%s", a.title);
    getchar();
    printf("Enter Book Author Name: ");
    scanf("%s", a.author);
    getchar();
    printf("Enter Book ISBN: ");
    scanf("%d", &a.isbn);
    getchar();
    printf("Enter Book Cost: ");
    scanf("%d", &a.cost);
    getchar();

    fprintf(doc, "ID: %d Title: %s Author: %s ISBN: %i Cost: %d", a.id, a.title, a.author, a.isbn, a.cost);
    printf("Book has been added\n");
}
void display(FILE *doc)
{
    struct book d;
    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %i Cost: %d", d.id, d.title, d.author, d.isbn, d.cost) != EOF)
    {
        printf("/////////////////////////");
        printf("ID: %d Title: %s Author: %s ISBN: %i Cost: %d", d.id, d.title, d.author d.isbn, d.cost);
        printf("/////////////////////////");
    }
}
void find(FILE *doc)
{
    struct book f;
    char book_id;
    printf("Enter Book ID for Search: ");
    scanf("%d", &book_id);
    getchar();
    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %i Cost: %d", f.id, f.title, f.author, f.isbn, f.cost) != EOF)
    {
        if (book_id == f.id)
        {
            printf("/////////////////////////");
            printf("ID: %d Title: %s Author: %s ISBN: %i Cost: %d", f.id, f.title, f.author, f.isbn, f.cost);
            printf("/////////////////////////");
        }
    }
}
void filter(FILE *doc)
{
    struct book flt;
    char book_author[30];
    printf("Enter Author Name: ");
    scanf("%s", book_author);
    getchar();
    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %i Cost: %d", flt.id, flt.title, flt.author, flt.isbn, flt.cost) != EOF)
    {
        (strcmp(book_author, flt.author) == 0)
        {
            printf("/////////////////////////");
            printf("ID: %d Title: %s Author: %s ISBN: %i Cost: %d", flt.id, flt.title, flt.author, flt.isbn, flt.cost);
            printf("/////////////////////////");
        }
    }
}
void quit(FILE *doc)
{
    printf("Exiting...");
}