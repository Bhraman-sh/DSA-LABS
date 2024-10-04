#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int strlen(char *);
void concat(char *,char *, char *);

int main()
{
    char *string1 = {"hello"};
    char *string2 = {" how"};

    printf("\nString 1: %s", string1);
    printf("\nString 2: %s", string2);

    printf("%c", *(string1 + 5));
    printf("\nLength of string 1 is %d", strlen(string1));
    printf("\nLength of string 2 is %d", strlen(string2));

    char *string3;
    concat(string1, string2, string3);

    printf("\nString 3: %s", string3);
    printf("\nLength of string 3 is %d", strlen(string3));
}

int strlen(char *s1)
{
    int i = 0;
    while(*(s1+i) != '\0')
    {
        i++;
    }

    return i;
}

void concat(char *s1, char *s2, char *s3)
{
    int i;
    int j=0;
    for(i=0; i<strlen(s1); i++)
    {
        *(s3+j) = *(s1+i);
        j++;
    }
    for(i=0; i<strlen(s2); i++)
    {
        *(s3+j) = *(s2+i);
        j++;
    }
    *(s3+j) = '\0'; 
}