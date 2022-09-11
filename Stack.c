#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

#define Max 100

#define True 1
#define False 0

//color func
//________________________________________

void red () 
{
  printf("\033[1;31m");
}

void yellow() 
{
  printf("\033[1;33m");
}

void blue()
{
    printf("\033[0;34m");
}

void magenta()
{
    printf("\x1b[35m");
}

void reset () 
{
  printf("\033[0m");
}

//________________________________________


//global variable 
char cache[Max];
int i;

struct Node{
    char material[Max];
    struct Node* next;
} *top = NULL;

int is_Empty()
{
    if(top == NULL)
    {
        return True;
    }else{
        return False;
    }
}

void push(char met[Max])
{
    struct Node* newNode;
    newNode = malloc(sizeof(newNode));
    if (newNode == NULL)
    {
        printf("Error: Stack overflow");
        exit(1);
    }
    // for (int i = 0;newNode->material[i] == '\0';i++)
    // {
    //     newNode->material[i] = met[i];
    // }
    strcpy(newNode->material , met);
    newNode->next = top;
    top = newNode;
}

int length()
{
    int len = 0;
    struct Node* temp;
    temp = top;

    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void print_stack()
{
    struct Node* temp;
    temp = top;
    yellow();
    printf("\n\n_____________________\n\n");
    while (temp)
    {
        printf("%s", temp->material);
        printf("\n");
        temp = temp->next;
    }
    printf("_____________________\n\n");
    reset();
}

void pop()
{
    if(is_Empty())
    {
        printf("Error: Stack is Empty");
        exit(1);

    }else{
         struct Node* temp;
        temp = top;
        // for (i = 0;temp->material[i] == '\0';i++)
        // {
        //     cache[i] = temp->material[i]; 
        // }
        strcpy(cache , temp->material);

        top = top->next;
        free(temp);
        temp = NULL;
    }
   
}

void del_stack()
{
    struct Node* temp;
    temp = top;

    while (temp)
    {
        pop();
        temp = temp->next;
    }
}

void peek()
{
    if(is_Empty())
    {
        printf("Error: Stack is empty");
        exit(1);
    }else{
        // for (i = 0;top->material[i] == '\0';i++)
        // {
        //     cache[i] = top->material[i];
        // }
        strcpy(cache , top->material);
        printf("%s" , cache);
    }
}

int search(char input[Max])
{
    struct Node* curr = top;
    while(curr)
    {
        if(strcmp(curr->material , input) == 0)
            return 0;
        curr = curr->next;
        
    }
    return 1;
}

int main()
{
    int choice;
    char value[Max];
    char input[Max];

    red();
    printf("\n\n _______ mining materials data ________ \n");

    main:
    printf("\n\n");
    while (1)
    {
        blue();
        printf("1 = Push a material\n");
        printf("2 = Pop a material\n");
        printf("3 = Peek a material\n");
        printf("4 = Search a meterial\n");
        printf("5 = show the loaded length of the mineshaft\n");
        printf("6 = print materials from mineshaft\n");
        printf("7 = delete the mineshaft\n");
        printf("8 = exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            printf("\n\nEnter material you want to push: ");
            scanf("%s" , value);
            push(value);
            break;

            case 2:
            pop();
            printf("\n\nPopped material from mineshaft: %s\n" , cache);
            print_stack();
            break;

            case 3:
            printf("\n\ntop material of the mineshaft: ");
            peek();
            printf("\n\n");
            break;

            case 4:
            printf("\nEnter the material you want to search: ");
            scanf("%s" , input);
            if (search(input))
            {
                printf("\n\ninputed material is not in the stack\n");
            }else{
                printf("\ninputed material is in the stack\n");
            }
            break;
            
            case 5:
            printf("\nthe load shafts of the mineshaft is: %d\n\n" , length());
            break;

            case 6:
            print_stack();
            break;

            case 7:
            del_stack();
            printf("stack has been deleted\n\n");
            break;

            case 8:
            exit(0);
            break;

            default:
            printf("\nInvalid command\n");
            goto main;
            break;
        }
    }
}