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

void addRear(struct node **, struct node **, int);
void addFront(struct node **, struct node **, int);
int removeFront(struct node **, struct node **);
int removeRear(struct node **, struct node **);
void disp_circ(struct node *);

int main()
{
    struct queue queue1;

    queue1.front = queue1.rear = NULL;

    //system("cls");

    addRear(&queue1.front, &queue1.rear, 10);
    addRear(&queue1.front, &queue1.rear, 58);
    addRear(&queue1.front, &queue1.rear, 63);
    addRear(&queue1.front, &queue1.rear, 34);
    addRear(&queue1.front, &queue1.rear, 5);
    addRear(&queue1.front, &queue1.rear, 23);

    printf("Queue after adding from rear: ");
    disp_circ(queue1.front);

    addFront(&queue1.front, &queue1.rear, 15);
    addFront(&queue1.front, &queue1.rear, 24);

   
    printf("Queue after adding from front: ");
    disp_circ(queue1.front);

    removeFront(&queue1.front, &queue1.rear);
    removeFront(&queue1.front, &queue1.rear);

    printf("Queue after removing from front: ");
    disp_circ(queue1.front);

    removeRear(&queue1.front, &queue1.rear);
    removeRear(&queue1.front, &queue1.rear);

    printf("Queue after removing from Rear: ");
    disp_circ(queue1.front);

    return 0;
}

void addRear(struct node **f, struct node **r, int data)
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

void addFront(struct node **f, struct node **r, int data)
{
    struct node *q;

    q = (struct node *) malloc (sizeof(struct node));
    q->data = data;
    
    (*r)->next = q;
    (q)->next = *f;
    (*f) = q;
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

int removeFront(struct node **f, struct node **r)
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

int removeRear(struct node **f, struct node **r)
{
    struct node *s;
    int temp;
    temp = (*r)->data;

    s = *f;

    while(s->next != *r)
        s = s->next;
    
    s->next = *f;
    *r = s;

    return temp;
}