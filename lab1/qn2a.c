#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
    int year;
    int month;
    int day;
} DATE;

void printAge(DATE *, DATE *);
void initDate(DATE *, int , int , int);

int main()
{
    DATE todayDate, bday1, bday2;
    initDate(&todayDate, 2023, 12, 4);
    initDate(&bday1, 2003, 4, 5);
    initDate(&bday2, 2003, 4, 27);

    printAge(&todayDate,&bday1);
    printAge(&todayDate,&bday2);

    return 0;
}

void initDate(DATE *d, int y, int m, int da)
{
    d->year = y;
    d->month = m;
    d->day = da;
}
