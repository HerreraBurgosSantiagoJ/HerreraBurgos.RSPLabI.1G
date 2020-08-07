#include "../Heathers/sUser.h"
#include "../Heathers/LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

sUser* usr_newEmpty()
{
    return (sUser*) malloc(sizeof(sUser));
}


sUser* usr_new(int id, char* userName, int likes, int dislikes, int followers)
{
    sUser* user = (sUser*) malloc(sizeof(sUser));
    if(user!=NULL)
    {
        usr_setId(user,id);
        usr_setUsr(user,userName);
        usr_setLks(user,likes);
        usr_setDlk(user,likes);
        usr_setFlw(user,followers);
    }
    return user;
}

int usr_comId(void* user1, void* user2)
{
    int anw;
    sUser* a = (sUser*) user1;
    sUser* b = (sUser*) user2;
    if(a->id==b->id)
    {
        anw=0;
    }
    else if(a->id>b->id)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int usr_comUsr(void* user1, void* user2)
{
    int anw;
    sUser* a = (sUser*) user1;
    sUser* b = (sUser*) user2;
    anw=strcmp(b->userName,a->userName);
    return anw;
}

int usr_comLks(void* user1, void* user2)
{
    int anw;
    sUser* a = (sUser*) user1;
    sUser* b = (sUser*) user2;
    if(a->likes==b->likes)
    {
        anw=0;
    }
    else if(a->likes>b->likes)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int usr_comDlk(void* user1, void* user2)
{
    int anw;
    sUser* a = (sUser*) user1;
    sUser* b = (sUser*) user2;
    if(a->dislikes==b->dislikes)
    {
        anw=0;
    }
    else if(a->dislikes>b->dislikes)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int usr_comFlw(void* user1, void* user2)
{
    int anw;
    sUser* a = (sUser*) user1;
    sUser* b = (sUser*) user2;
    if(a->followers==b->followers)
    {
        anw=0;
    }
    else if(a->followers>b->followers)
    {
        anw=-1;
    }
    else
    {
        anw=1;
    }
    return anw;
}

int usr_getId(sUser* user, int* id)
{
    int isError = 1;
    if (user!=NULL)
    {
        *id = user->id;
        isError=0;
    }
    return isError;
}

int usr_getUsr(sUser* user, char* userName)
{
    int isError = 1;
    if (user!=NULL)
    {
        strcpy(userName,user->userName);
        isError=0;
    }
    return isError;
}

int usr_getLks(sUser* user, int* likes)
{
    int isError = 1;
    if (user!=NULL)
    {
        *likes = user->likes;
        isError=0;
    }
    return isError;
}

int usr_getDlk(sUser* user, int* dislikes)
{
    int isError = 1;
    if (user!=NULL)
    {
        *dislikes = user->dislikes;
        isError=0;
    }
    return isError;
}

int usr_getFlw(sUser* user, int* followers)
{
    int isError = 1;
    if (user!=NULL)
    {
        *followers = user->followers;
        isError=0;
    }
    return isError;
}

int usr_setId(sUser* user, int id)
{
    int isError=1;
    if(user!=NULL)
    {
        user->id=id;
        isError=0;
    }
    return isError;
}

int usr_setUsr(sUser* user, char* userName)
{
    int isError=1;
    if(user!=NULL)
    {
        strcpy(user->userName, userName);
        isError=0;
    }
    return isError;
}

int usr_setLks(sUser* user, int likes)
{
    int isError=1;
    if(user!=NULL)
    {
        user->likes=likes;
        isError=0;
    }
    return isError;
}

int usr_setDlk(sUser* user, int dislikes)
{
    int isError=1;
    if(user!=NULL)
    {
        user->dislikes=dislikes;
        isError=0;
    }
    return isError;
}

int usr_setFlw(sUser* user, int followers)
{
    int isError=1;
    if(user!=NULL)
    {
        user->followers=followers;
        isError=0;
    }
    return isError;
}

void usr_show(sUser* user)
{
    if (user!=NULL)
    {
        printf("%04d|%24s|%10d|%10d|%10d\n",user->id,user->userName,user->likes,user->dislikes,user->followers);
        printf("------------------------------------------------------\n");
    }
}

int usr_showAll(LinkedList* this)
{
    int length;
    int isError = 1;
    sUser* user;
    length = ll_len(this);
    if (length>0)
    {
        printf("Id|Nombre de usuario(nick)|Likes|Dislikes|Seguidores \n");
        printf("------------------------------------------------------\n");
        for(int i=0; i<length; i++)
        {
            user = (sUser*) ll_get(this,i);
            usr_show(user);
        }
        isError=0;
    }
    else
    {
        printf("\nNo hay usuarios para mostrar. Carguelos desde un documento.\n");
    }
    return isError;
}

int usr_excPopular(void* user, void* volume)
{
    int exclude = 0;
    sUser* a = (sUser*) user;
    int b = (int) volume;
    if(a->likes<=b)
    {
        exclude=1;
    }
    return exclude;
}

int usr_excHatted(void* user, void* diference)
{
    int exclude = 0;
    sUser* a = (sUser*) user;
    int b = (int) diference;
    int aux = (a->likes)-(a->dislikes);
    if(aux<=b)
    {
        exclude=1;
    }
    return exclude;
}
