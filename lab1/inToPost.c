#include<stdio.h>
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

void inToPost(char *, char *);
void push(STACK *, char);
char pop(STACK *);
void initStack(STACK *);
bool isEmpty(STACK *);
int precedence(char);

int main()
{
    char in[max]; //string to store the infix expression
    char post[max]; //string to store the postfix expression

    //Ask the user to type an expression;
    printf("Enter an infix expression: ");
    fgets(in, sizeof(in), stdin);
    inToPost(in,post);

    //display the postfix expression
    printf("\nThe corespondin postfix expression is: %s", post);

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
    //printf("\n%c", s->top);
    return c;
}

bool isEmpty(STACK *s)
{
    if(s->ind == -1)
        return true;
    
    return false;
}

void inToPost(char *i, char *p)
{
    char c;
    STACK s;
    initStack(&s);
    int counti = 0;
    int countp = 0;

    for(int j = 0; j<strlen(i); j++)
    {
         if((i[counti] >= 97) && (i[counti] <= 122))
        {
            p[countp] = i[counti];
            countp++;
        }
        else if(i[counti] == '(')
        {
           push(&s, i[counti]);
        }
        else if (i[counti] == ')')
        {
            while(s.top != '(')
            {
            p[countp] = pop(&s);
            countp ++;
            }
            pop(&s);
        }
        else 
        {
            while (!isEmpty(&s) && precedence(s.top) >= precedence(i[counti]))
            {
                p[countp] = pop(&s);
                countp++;
            }
            push(&s,i[counti]);
        }
        counti++;
    }
    while(!isEmpty(&s))
    {
        //printf("last while");
        p[countp] = pop(&s);
        countp++;
    }
    p[countp] = '\0';
   // printf("\nhello%c", pop(&s));
}

int precedence(char c)
{
    switch (c)
    {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}