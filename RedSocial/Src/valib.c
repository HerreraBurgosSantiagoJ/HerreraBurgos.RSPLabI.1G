#include <string.h>
#include <ctype.h>

int validarChar(char ingreso,char opciones[])
{
    int i=0;
    int booleano=1;
    if(ingreso<91)
    {
        ingreso=tolower(ingreso);
    }
    while(opciones[i]!='\0')
    {
        if (ingreso==opciones[i])
        {
            booleano=0;
            break;
        }
        i++;
    }
    return booleano;
}

int validarInt(int ingreso, int opciones[], int len)
{
    int booleano=1;
    for (int i = 0 ; i < len ; i++)
    {
        if (ingreso==opciones[i])
        {
            booleano=0;
            break;
        }
    }
    return booleano;
}
