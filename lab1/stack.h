#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define max 10

typedef struct
{
    int arr[max];
    int top;
} STACK;

void initStack(STACK *);
void push(STACK *,int);
int pop(STACK *);

int main()
{
    int i;

    STACK stack1;
    initStack(&stack1);

    push(&stack1,10);
    push(&stack1,20);
    push(&stack1,32);

    i = pop(&stack1);
    if(i != -1);
        printf("\nItem popped = %d  \\ %d", i,stack1.top);

    i = pop(&stack1);
    if(i != -1);
        printf("\nItem popped = %d", i);

    i = pop(&stack1);
    if(i != -1);
        printf("\nItem popped = %d", i);

    return 0;
}

void initStack(STACK * st)
{
    st->top = 0;
    printf("Stack has been initialized");
}

void push(STACK * st, int a)
{
    if (st->top == max - 1)
    {
        printf("Error stack is full");
        exit(0);
    }
    else
    {
        st->arr[st->top] = a;
        st->top++;
    }
}

int pop (STACK * st)
{
    if (st->top == -1)
    {
        return -1;
    }
    else
    {
    st->top --;
    return st->arr[st->top];
    }
}


