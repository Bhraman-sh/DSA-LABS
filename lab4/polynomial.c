//Linked list can be used to add represent polynomials
//Each node represents a term while the entire list represents the expression
//Then we can use the linked list to perform mathematical operation like addition and multiplication in

#include<stdio.h>
#include<windows.h>
#include<malloc.h>

struct polynode
{
    float coeff;
    int exp;
    struct polynode *next;
};

void enter_poly(struct polynode **);
void append(struct polynode **, float, int);
void display_poly(struct polynode *);
void add_poly(struct polynode *, struct polynode *, struct polynode **);
void multiply_poly(struct polynode *, struct polynode *, struct polynode **);

int main()
{
    struct polynode *e1, *e2, *e3, *e4;
    e1 = e2 = e3 = e4 = NULL;
    enter_poly(&e1);
    // display_poly(e1);
    enter_poly(&e2);

    add_poly(e1,e2,&e3);

    printf("Adding the two polynomial\n\n");
    display_poly(e1);
    display_poly(e2);
    printf("------------------------\n");
    display_poly(e3);

    multiply_poly(e1,e2,&e4);

    printf("\nMultiplying the two polynomial\n\n");
    display_poly(e1);
    display_poly(e2);
    printf("------------------------\n");
    display_poly(e4);

    return 0;
}

void enter_poly(struct polynode **p)
{
    int e;
    float c;
    char ch;
    system("cls");
    printf("Enter a new polynomial\n\n");
    do
    {
        printf("Enter the coeffiecient: ");
        scanf("%f", &c);
        printf("Enter the power: ");
        scanf("%d", &e);

        append(p, c, e);

        printf("Do you want to modify your expression?(y/n)");
        fflush(stdin);
        ch = getchar();
        printf("\n");
    }while(ch == 'y' || ch == 'Y');
}

void append(struct polynode **p, float c, int e)
{
    struct polynode *temp, *q, *r;

    if(*p == NULL)  //if the linked list is empty
    {
        (*p) = (struct polynode *) malloc (sizeof(struct polynode));
        (*p)->coeff = c;
        (*p)->exp = e;
        (*p)->next = NULL;
        return;
    }
    temp = *p;

    if(e > temp->exp)   //if the entered term is of higher order than the first term
    {
        q = (struct polynode *) malloc (sizeof(struct polynode));
        q->coeff = c;
        q->exp = e;
        q->next = temp;
        *p = q;
        return;
    }

    while(1)
    {
        if(temp->exp == e)
        {
            temp->coeff += c;
            return;
        }

        if(temp->next != NULL)
        {
            if(temp->exp > e && temp->next->exp < e)
            {
                q = (struct polynode *) malloc (sizeof(struct polynode));
                q->coeff = c;
                q->exp = e;
                q->next = temp->next;
                temp->next = q;
                return;
            }                
        }
        else
        {
            q = (struct polynode *) malloc (sizeof(struct polynode));
            q->coeff = c;
            q->exp = e;
            q->next = NULL;
            temp->next = q;

            return;
        }
        temp = temp->next;
    } 
}

void add_poly(struct polynode *p1, struct polynode *p2, struct polynode **p3)
{
    if(p1 == NULL && p2 == NULL)
        return;
    
    while(p1 != NULL && p2 != NULL)
    {
       if (p1->exp > p2->exp)
       {
            append(p3,p1->coeff,p1->exp); 
            p1 = p1->next;
       }
       else if (p1->exp < p2->exp)
       {
            append(p3,p2->coeff,p2->exp); 
            p2 = p2->next;
       }
       else
       {
            append(p3, p2->coeff + p1->coeff, p2->exp);
            p1 = p1->next;
            p2 = p2->next;
       }
    }
    while (p1 != NULL)
    {       
        append(p3,p1->coeff,p1->exp); 
        p1 = p1->next;
    }
    
    while (p2 != NULL)
    {
        append(p3,p2->coeff,p2->exp); 
        p2 = p2->next;
    } 
}

void multiply_poly(struct polynode *p1, struct polynode *p2, struct polynode **p3)
{
    struct polynode *p2_beg = p2;
    while(p1 != NULL)
    {
        while(p2 != NULL)
        {
            append(p3, p1->coeff * p2->coeff, p1->exp + p2->exp);
            p2 = p2->next;
        }
        p2 = p2_beg;
        p1 = p1->next;
    }
}

void display_poly(struct polynode *p)
{
    if(p == NULL)
    {
        printf("0");
    }
    else
    {
        while(p != NULL)
        {
            if(p->next != NULL)
            {
                printf("%.4f^%d + ",p->coeff, p->exp);
            }
            else
            {
                printf("%.4f^%d",p->coeff, p->exp);
            }
            p = p->next;
        }
    }
    printf("\n");
}
