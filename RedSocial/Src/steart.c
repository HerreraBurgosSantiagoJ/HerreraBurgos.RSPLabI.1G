#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Heathers/steart.h"

void progHeader(char title[])
{
    int largo=strlen(title);
    int largoRenglon=largo*3;
    int i;
    system("cls");
    for (i = 0; i<largoRenglon;i++)
    {
        printf("=");
    }
    printf("\n");
    for (i = 0; i<largo;i++)
    {
        printf(" ");
    }
    printf("%s",title);
    for (i = 0; i<largo;i++)
    {
        printf(" ");
    }
    printf("\n");
    for (i = 0; i<largoRenglon;i++)
    {
        printf("=");
    }
}

void subHeader(char sub[])
{
    int largo=strlen(sub);
    printf("\n%s\n",sub);
    for (int i = 0; i<largo;i++)
    {
        printf("-");
    }
    printf("\n");
}
