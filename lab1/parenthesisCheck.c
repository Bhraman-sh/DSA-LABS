#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdbool.h>

#define max 30

//Creating a stack that stores character 
typedef struct
{
    char arr[max];
    int ind;
    char top;
}STACK;

void parenthesisCheck(char *);
void push(STACK *, char);
char pop(STACK *);
void initStack(STACK *);
bool isEmpty(STACK *);


int main()
{
    char in[max]; //string to store the infix expression
    char post[max]; //string to store the postfix expression

    //Ask the user to type an expression;
    printf("Enter mathematical expression: ");
    fgets(in, sizeof(in), stdin);
    parenthesisCheck(in);

    return 0;
}

void initStack(STACK *s)
{
    s->ind = -1;
}

void push(STACK *s, char c)
{
    s->ind++;
    s->arr[s->ind] = c;
    s->top = s->arr[s->ind];
    //printf("\n%chello", s->top);
}

char pop(STACK *s)
{
    char c = s->top;
    s->ind--;
    s->top = s->arr[s->ind];
    printf("\n%c", s->top);
    return c;
}

bool isEmpty(STACK *s)
{
    if(s->ind == -1)
        return true;
    
    return false;
}

void parenthesisCheck(char *c)
{
    STACK s;
    initStack(&s);

    for(int i = 0; i < strlen(c) ; i++)
    {
        if(c[i] == '(')
        {
            push(&s, c[i]);
        }
        if(c[i] == ')')
        {
            if(isEmpty(&s))
            {
                printf("\nIncorrect mathematical expression!");
                return;
            }
            else
            {
                pop(&s);
            }
        }
    }
    if(isEmpty(&s))
    {
        printf("\nCorrect mathematical expression!");
        return;
    }
    else
    {
        printf("\nInCorrect mathematical expression!");
    }
}
