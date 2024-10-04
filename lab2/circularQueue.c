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

struct queue
{
    struct node *front, *rear;
};

void enqueue(struct node **, struct node **, int);
int dqueue(struct node **, struct node **);
void disp_circ(struct node *);

int main()
{
    struct queue queue1;

    queue1.front = queue1.rear = NULL;

    //system("cls");

    enqueue(&queue1.front, &queue1.rear, 10);
    enqueue(&queue1.front, &queue1.rear, 58);
    enqueue(&queue1.front, &queue1.rear, 63);
    enqueue(&queue1.front, &queue1.rear, 29);
    enqueue(&queue1.front, &queue1.rear, 42);
    enqueue(&queue1.front, &queue1.rear, 99);

    printf("Queue after enqueues: ");
    disp_circ(queue1.front);

    printf("\nThe element first in line is %d", dqueue(&queue1.front, &queue1.rear));
    printf("\nThe element first in line is %d", dqueue(&queue1.front, &queue1.rear));
    printf("\nThe element first in line is %d", dqueue(&queue1.front, &queue1.rear));
    printf("\nThe element first in line is %d", dqueue(&queue1.front, &queue1.rear));

    printf("\n\nQueue after dequeues: ");
    disp_circ(queue1.front);

    return 0;
}

void enqueue(struct node **f, struct node **r, int data)
{
    struct node *q;

    q = (struct node *) malloc (sizeof(struct node));
    q->data = data;

    if( *f == NULL )
        *f = q;
    else
        (*r)->next = q;

    *r = q;
    (*r)->next = *f;
}

void disp_circ(struct node *f)
{
    struct node *p;
    p = f;

    while(1)
    {
        printf("%d ", p->data);
        p = p->next;
        if(p == f)
            break;
    }
    printf("\n");
}

int dqueue(struct node **f, struct node **r)
{
    int item;
    struct node *q;

    if(*f == NULL)
    {
        printf("Linked list is empty");
        return 0;
    }
    else
    {
        if(*f == *r)
        {
            item = (*f)->data;
            free(*f);
            *f = *r = NULL;
        }
        else
        {
            q = *f;
            item = q->data;
            (*f) = q->next;
            (*r)->next = *f;
            free(q);
        }
     }
     return item;
}