#include <stdlib.h>
#include <stdio.h>
#include "../Heathers/Controller.h"
#include "../Heathers/utn.h"
#include "../Heathers/LinkedList.h"
#include "../Heathers/steart.h"
#include "../Heathers/Parser.h"
#include "../Heathers/sUser.h"
#define PRONAME "Post Data Manager"
#define PATH_LEN 250
#define DATA_VOL 604 //viene de 120*5(datos en txt) + 4(comas que separan los datos)


int ctlr_load(LinkedList* this)
{
    int isError = 1;
    int cont = 1;
    int trys=3;
    char path[PATH_LEN];
    char** buffer;
    sUser* auxUser;
    do{
        progHeader(PRONAME);
        subHeader("Cargar Desde Archivo");
        if(trys<3)
        {
            printf("\nERROR: La fuente ingresada no es valida, o el archivo no existe");
            printf("\n%d intentos restantes",trys);
        }
        printf("\nIngrese la ubicacion desde donde desa cargar los datos(D:carpeta/carpeta2/archivo.csv)\nFuente: ");
        myFgets(path,PATH_LEN);
        buffer=par_loadTXT(path,DATA_VOL,0);
        trys--;
    }while(isError&&trys>0);
    auxUser = usr_newEmpty();
    if((!isError)&&auxUser!=NULL)
    {
        while(buffer!=NULL)
        {
            buffer = par_loadTXT(path,DATA_VOL,cont);
            if(buffer!=NULL)
            {
                cont++;
                auxUser = usr_newEmpty();
                isError = usr_setId(auxUser,atoi(buffer[0]));
                if(isError)
                {
                    break;
                }
                isError = usr_setUsr(auxUser,buffer[1]);
                if(isError)
                {
                    break;
                }
                isError = usr_setLks(auxUser,atoi(buffer[2]));
                if(isError)
                {
                    break;
                }
                isError = usr_setDlk(auxUser,atoi(buffer[3]));
                if(isError)
                {
                    break;
                }
                isError = usr_setFlw(auxUser,atoi(buffer[4]));
                if(isError)
                {
                    break;
                }
                isError=ll_add(this,auxUser);
                if(isError==-1)
                {
                    isError=1;
                    break;
                }
            }
        }
        if(!isError)
        {
            printf("Datos cargados.\n");
        }
    }
    else
    {
        printf("ERROR! No se pudo cargar los datos del documento, es posible que\n");
        printf("el documento no exista, este dañado o no contenga datos.\n");
    }
    return isError;
}

int ctlr_showList(LinkedList* this)
{

/*
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los posteos.
*/
    int isError = 1;
    int length;
    length = ll_len(this);
    progHeader(PRONAME);
    subHeader("Mostrar Datos");
    if (length>0)
    {
        isError=usr_showAll(this);
    }
    return isError;
}

int ctlr_fillterPoppular(LinkedList* this)
{

/*
4) filtrar por mejores posteos: Se deberá generar un archivo igual al original, pero donde solo
aparezcan posteos con más de 5000 likes.
*/
    int isError = 1;
    LinkedList* bestPost;

    progHeader(PRONAME);
    subHeader("Filtrar los Mejores Posteos");
    bestPost = ll_fillter(this,usr_excPopular,(void*)5000);
    if(bestPost!=NULL)
    {
        printf("\nSe guardara un archivo en la carpeta \" Excluded \" en la ubicacion de este programa");
        printf("\nBajo el nombre \" Mejores Posteos.txt \" con los datos filltrados");
        isError = save_usersData(bestPost,"../Excluded/Mejores Posteos.txt");
    }
    else
    {
        printf("\nError! No es posible filltrar los posteos, es probable que por falta de memoria");
        printf("\nPruebe cerrar algunos programas e intentelo nuevamente");
    }
    free(bestPost);
    return isError;
}

int ctlr_fillterHatted(LinkedList* this)
{

/*
5) filtrar por haters: Se deberá generar un archivo igual al original, pero donde solo aparezcan
posts donde la cantidad de dislikes supere a la de likes.
*/
    int isError = 1;
    LinkedList* hattedPosts;

    progHeader(PRONAME);
    subHeader("Filtrar los Mas Odiados");
    hattedPosts = ll_fillter(this,usr_excHatted,(void*)0);
    if(hattedPosts!=NULL)
    {
        printf("\nSe guardara un archivo en la carpeta \" Excluded \" en la ubicacion de este programa");
        printf("\nBajo el nombre \" Mas Odiados.txt \" con los datos filltrados");
        isError = save_usersData(hattedPosts,"../Excluded/Mas Odiados.txt");
    }
    else
    {
        printf("\nError! No es posible filltrar los posteos, es probable que por falta de memoria");
        printf("\nPruebe cerrar algunos programas e intentelo nuevamente");
    }
    free(hattedPosts);
    return isError;
}

int ctlr_sortFollowers(LinkedList* this)
{
/*
6) ordenar por cantidad de followers: Se deberá mostrar por pantalla un listado de los posteos
ordenados por cantidad de followers descendente.
*/
    int isError = 0;
    progHeader(PRONAME);
    subHeader("Ordenar por Seguidores");
    isError = ll_sort(this,usr_comFlw,0);
    if(!isError)
    {
        isError=usr_showAll(this);
    }
    return isError;
}

int save_usersData(LinkedList* this, char* path)
{
    int isError = 1;
    int size;
    int id;
    char userName[40];
    int likes;
    int dislikes;
    int followers;
    sUser* user;
    FILE* file;
    file = fopen(path,"w");
    size = ll_len(this);
    isError=fprintf(file,"id,user,likes,dislikes,followers");
    for(int i = 0; i<size; i++)
    {
        user = (sUser*) ll_pop(this,i);
        usr_getId(user,&id);
        usr_getUsr(user,userName);
        usr_getLks(user,&likes);
        usr_getDlk(user,&dislikes);
        usr_getFlw(user,&followers);
        isError=fprintf(file,"%d,%s,%d,%d,%d\n",id,userName,likes,dislikes,followers);
        if(isError<0)
        {
            isError=1;
            break;
        }
        else
        {
            isError=0;
        }
    }
    if(!isError)
    {
        printf("Datos guardados.\n");
    }
    free(user);
    fclose(file);
    return isError;
}

int ctlr_staticAsignment(LinkedList* this)
{
    int isError = 1;
    return isError;
}

int stat_likes(void* user)
{
    int aleatory;
    int isError = 1;
    sUser* a = (sUser*) user;
    aleatory = rand()%( 10000 - 500 +1) + 500;
    isError=usr_setLks(a,aleatory);
    return isError;
}

int stat_dislikes(void* user)
{
    int aleatory;
    int isError = 1;
    sUser* a = (sUser*) user;
    aleatory = rand()%( 3500 - 300 +1) + 300;
    isError=usr_setDlk(a,aleatory);
    return isError;
}

int stat_followers(void* user)
{
    int aleatory;
    int isError = 1;
    sUser* a = (sUser*) user;
    aleatory = rand()%( 20000 - 10000 +1) + 10000;
    isError=usr_setFlw(a,aleatory);
    return isError;
}


/*
1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos
del mismo.
2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los posteos.
3) Asignar estadísticas: Se deberá hacer uso de la función map. la cual recibirá el linkedlist y
una función que asignará a cada post un valor de likes entre 500 y 10000, dislikes con valores
entre 300 y 3500 y followers entre 10000 y 20000. calculados de manera aleatoria.
4) filtrar por mejores posteos: Se deberá generar un archivo igual al original, pero donde solo
aparezcan posteos con más de 5000 likes.
5) filtrar por haters: Se deberá generar un archivo igual al original, pero donde solo aparezcan
posts donde la cantidad de dislikes supere a la de likes.
6) ordenar por cantidad de followers: Se deberá mostrar por pantalla un listado de los posteos
ordenados por cantidad de followers descendente.
7) mostrar más popular: Informar el nombre del user o users con el posteo más likeado. Y
cuál es ese número.
8) salir.
*/

