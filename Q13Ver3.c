#include <stdio.h>
#include <stdlib.h>
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
    struct book *a = (struct book *)malloc(sizeof(struct book));
    if (!a)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    int found = 0;
    printf("Enter Book ID: ");
    scanf("%d", &a->id);
    getchar();

    // Check if the ID already exists
    rewind(doc);
    struct book temp;

    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", &temp.id, temp.title, temp.author, &temp.isbn, &temp.cost) != EOF)
    {
        if (a->id == temp.id)
        {
            found = 1;
            printf("ID found...\n");
            printf("ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", temp.id, temp.title, temp.author, temp.isbn, temp.cost);
            free(a);
            return;
        }
    }

    // If not found, add new book
    printf("Enter Book Title: ");
    scanf("%s", a->title);
    getchar();
    printf("Enter Book Author Name: ");
    scanf("%s", a->author);
    getchar();
    printf("Enter Book ISBN: ");
    scanf("%d", &a->isbn);
    getchar();
    printf("Enter Book Cost: ");
    scanf("%d", &a->cost);
    getchar();

    fprintf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", a->id, a->title, a->author, a->isbn, a->cost);
    printf("Book has been added\n");

    free(a);
}

void display(FILE *doc)
{
    struct book *d = (struct book *)malloc(sizeof(struct book));
    if (!d)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    rewind(doc);

    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", &d->id, d->title, d->author, &d->isbn, &d->cost) != EOF)
    {
        printf("/////////////////////////\n");
        printf("ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", d->id, d->title, d->author, d->isbn, d->cost);
        printf("/////////////////////////\n");
    }

    free(d);
}

void find(FILE *doc)
{
    struct book *f = (struct book *)malloc(sizeof(struct book));
    if (!f)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    int book_id;

    printf("Enter Book ID for Search: ");
    scanf("%d", &book_id);
    getchar();
    rewind(doc);

    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", &f->id, f->title, f->author, &f->isbn, &f->cost) != EOF)
    {
        if (book_id == f->id)
        {
            printf("/////////////////////////\n");
            printf("ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", f->id, f->title, f->author, f->isbn, f->cost);
            printf("/////////////////////////\n");
            free(f);
            return;
        }
    }
    printf("Book with ID %d not found.\n", book_id);
    free(f);
}

void filter(FILE *doc)
{
    struct book *flt = (struct book *)malloc(sizeof(struct book));
    if (!flt)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    char book_author[30];
    printf("Enter Author Name: ");
    scanf("%s", book_author);
    getchar();
    rewind(doc);

    while (fscanf(doc, "ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", &flt->id, flt->title, flt->author, &flt->isbn, &flt->cost) != EOF)
    {
        if (strcmp(book_author, flt->author) == 0)
        {
            printf("/////////////////////////\n");
            printf("ID: %d Title: %s Author: %s ISBN: %d Cost: %d\n", flt->id, flt->title, flt->author, flt->isbn, flt->cost);
            printf("/////////////////////////\n");
        }
    }
    free(flt);
}

void quit(FILE *doc)
{
    printf("Exiting...\n");
}