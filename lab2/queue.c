//implement queue using circular linked list
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<malloc.h>

struct queue
{
    int data;
    struct queue *next;
};

void enqueue(struct queue **, struct queue **, int);
int dqueue(struct queue **, struct queue **);
void disp_circ(struct queue *);

int main()
{
    struct queue *front, *rear;

    front = rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 58);
    enqueue(&front, &rear, 63);
    enqueue(&front, &rear, 29);
    enqueue(&front, &rear, 42);
    enqueue(&front, &rear, 99);

    printf("Queue after enqueues: ");
    disp_circ(front);

    printf("\nThe element first in line is %d", dqueue(&front, &rear));
    printf("\nThe element first in line is %d", dqueue(&front, &rear));
    printf("\nThe element first in line is %d", dqueue(&front, &rear));
    printf("\nThe element first in line is %d", dqueue(&front, &rear));

    printf("\n\nQueue after dequeues: ");
    disp_circ(front);

    return 0;
}

void enqueue(struct queue **f, struct queue **r, int data)
{
    struct queue *q;

    q = (struct queue *) malloc (sizeof(struct queue));
    q->data = data;

    if( *f == NULL )
        *f = q;
    else
        (*r)->next = q;

    *r = q;
    (*r)->next = *f;
}

void disp_circ(struct queue *f)
{
    struct queue *p;
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

int dqueue(struct queue **f, struct queue **r)
{
    int item;
    struct queue *q;

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