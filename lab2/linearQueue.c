//Implment linear queue using array and structure

#include<stdio.h>
#include<windows.h>

#define maxi 20

struct queue
{
    int arr[maxi];
    int front;
    int rear;
};

void initQueue(struct queue *);
void enqueue(struct queue *, int);
int dequeue(struct queue *);
void display(struct queue *);

int main()
{
    struct queue q1;
    initQueue(&q1);
    
    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);
    enqueue(&q1,4);
    enqueue(&q1,5);
    enqueue(&q1,15);
    enqueue(&q1,7);

    //printf("Before dequeue: ");
    //display(&q1);
    //printf("\n%d %d %d ", q1.arr[0], q1.arr[2], q1.arr[5]);
    printf("\nThe first element in Line is %d", dequeue(&q1));
    printf("\nThe first element in Line is %d", dequeue(&q1));
    printf("\nThe first element in Line is %d", dequeue(&q1));
    printf("\nThe first element in Line is %d", dequeue(&q1));
    printf("\nThe first element in Line is %d", dequeue(&q1));

    // printf("\n\nAfter dequeue: ");
    // display(&q1);

    return 0;
}

void initQueue(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct queue *q, int data)
{
    if(q->rear == maxi-1)
    {
        printf("Queue is full");
        return;
    }
    q->rear ++;
    //printf("\n %d %d ", q->front, q->rear);
    q->arr[q->rear] = data;
}

int dequeue(struct queue *q)
{
    int temp;
     //printf("\n%d %d", q->front, q->rear);
    if(q->front == q->rear)
    {
        printf("\nQueue is empty");
        return 0;
    }

    q->front ++;
    temp = q->arr[q->front];
    //printf("\n %d", temp);
    return temp;
}

void display(struct queue *q)
{
    int i;
    for(i = q->front + 1 ; i< q->rear; q++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}