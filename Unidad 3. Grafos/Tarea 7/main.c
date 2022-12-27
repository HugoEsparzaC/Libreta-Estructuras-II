#include <stdio.h>

#define MAX_TEXT 80
#define DEBUG

void include_book();
void checkout_book();
void return_book();
void status();

int main(void)  {
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "rt", stdout);

    int n, op;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &op);
        switch (op) {
            case 1: include_book();
            break;
            case 2: checkout_book();
            break;
            case 3: return_book();
            break;
            case 4: status();
            break;
        }
    }
    return 0;
}

void include_book()
{
    char author[MAX_TEXT], title[MAX_TEXT];
    scanf("\n%[^\n]", author);
    scanf("\n%[^\n]", title);
#ifdef DEBUG
    printf("\nInclude book\n");
    printf("------------\n");
    printf("%s\n", author);
    printf("%s\n", title);
#endif
    // find the author
    // add new author if doesn't exist
    // add title
}

void checkout_book()
{
    char author[MAX_TEXT], title[MAX_TEXT], user[MAX_TEXT];
    scanf("\n%[^\n]", user);
    scanf("\n%[^\n]", author);
    scanf("\n%[^\n]", title);
#ifdef DEBUG
    printf("\nCheckout book\n");
    printf("-------------\n");    
    printf("%s\n", user);
    printf("%s\n", author);
    printf("%s\n", title);
#endif
    // verify that author and books exists
    // find the user
    // add new author if doesn't exist
    // add checkout if author and book exists
}

void return_book()
{
    char author[MAX_TEXT], title[MAX_TEXT], user[MAX_TEXT];
    scanf("\n%[^\n]", user);
    scanf("\n%[^\n]", author);
    scanf("\n%[^\n]", title);
#ifdef DEBUG
    printf("\nReturn book\n");
    printf("-----------\n");        
    printf("%s\n", user);
    printf("%s\n", author);
    printf("%s\n", title);
#endif
    // verify that user, author and title exists
    // if exists remove checkout
}

void status()
{
    printf("\nLibrary has the followig books:\n");
    printf("-------------------------------\n");        
    // Show author's catalog sorted alphabetically
    printf("\nThe following people are using the library:\n");
    printf("-------------------------------------------\n");        
    // Show user's catalog sorted alphabetically
}

