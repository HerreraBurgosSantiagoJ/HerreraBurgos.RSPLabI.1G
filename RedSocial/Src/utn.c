#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "boolib.h"
#include "valib.h"
#include "string.h"

void getInt(int* intNum,char mensage[])
{
    int rightEntry;
    int numb;
    printf(mensage);
    rightEntry=scanf("%d",&numb);
    fflush(stdin);
    while(not(rightEntry))
    {
        printf("Error, lo ingresado no es un numero");
        printf(mensage);
        rightEntry=scanf("%d",&numb);
        fflush(stdin);
    }
    *intNum=numb;
}

void getFloat(float* floatNum,char mesage[])
{
    int rightEntry;
    float floatPoint;
    printf(mesage);
    rightEntry=scanf("%f",&floatPoint);
    fflush(stdin);
    while(not(rightEntry))
    {
        printf("Lo ingresado no es un decimal.\n");
        printf(mesage);
        rightEntry=scanf("%f",&floatPoint);
        fflush(stdin);
    }
    *floatNum=floatPoint;
}

void getChar(char* character,char mesage[],char error[], char options[])
{
    int rightEntry;
    char characterI;
    printf(mesage);
    rightEntry=scanf("%c",&characterI);
    fflush(stdin);
    while(not(rightEntry)||validarChar(characterI,options))
    {
        printf(error);
        printf(mesage);
        rightEntry=scanf("%c",&characterI);
        fflush(stdin);
    }
    *character=characterI;
}

void myFgets(char* to, int len)
{
    char auxString[len];
    fgets(auxString,len,stdin);
    for ( int i = 0 ; i < len ; i++)
    {
        if ( auxString[i] != '\n')
        {
            to[i]=auxString[i];
        }
    }
}

void reviser(char* from, char* to)
{
    int len,j=0;
    char last=' ', current=' ';
    len = strlen(from);
    for(int i=0; i<len; i++)
    {
        if(from[i]!=' '&&last==' ')
        {
            if(from[i]>=97&&from[i]<=122)
            {
                current=toupper(from[i]);
            }
            else
            {
                current=from[i];
            }
            to[j]=current;
            j++;
        }
        else if(last!=' '&&from[i]!=' ')
        {
            if(from[i]>=65&&from[i]<=90)
            {
                current=tolower(from[i]);
            }
            else
            {
                current=from[i];
            }
            to[j]=current;
            j++;
        }
        else if(last!=' '&&from[i]==' ')
        {
            to[j]=from[i];
            j++;
        }
        if(from[i]=='\0'||from[i]=='\n')
        {
            break;
        }
        last=from[i];
    }
}

void getName(char* to, char* sorter, int len)
{
    char aux[len];
    printf("Ingrese el nombres de %s: ",sorter);
    myFgets(to,len);
    fflush(stdin);
    reviser(to,aux);
    strcpy(to,aux);
}
