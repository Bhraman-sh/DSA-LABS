//implementation of circular queue using circular linked list (NO SIZE LIMIT)
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct stack
{
    struct node *top;
};

void push(struct node **, int);
int pop(struct node **);
void disp_Whole_Stack(struct node *);   //DISPLAY THE CONTENT OF STACK WITHOUT AFFECTING ANYTHING

int main()
{
    struct stack stack1;
    stack1.top = NULL;

    pop(&stack1.top);

    push(&stack1.top,10);
    push(&stack1.top,20);
    push(&stack1.top,30);
    push(&stack1.top,1);
    push(&stack1.top,130);
    push(&stack1.top,45);
    push(&stack1.top,12);

    disp_Whole_Stack(stack1.top);

    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    printf("Popping the element of the stacks: %d\n", pop(&stack1.top));
    return 0;
}

void push(struct node **top, int data)
{
    struct node *q;

    q = (struct node *) malloc (sizeof(struct node));
    q->data = data;
    q->next = *top;
    *top = q;

}

int pop(struct node **f)
{
    int item;
    struct node *q;

    if(*f == NULL)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        q = *f;
        item = q->data;
        *f = q->next;
        free(q);
    }
     return item;
}

void disp_Whole_Stack(struct node *f)
{
    while((f) != NULL)
    {
        printf("%d ", f->data);
        f = f->next;       
    }
    printf("\n");
}
