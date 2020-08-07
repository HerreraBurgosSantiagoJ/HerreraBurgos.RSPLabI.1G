#ifndef sUser_H_INCLUDED
#define sUser_H_INCLUDED

#include "LinkedList.h"
typedef struct{
    int id;
    char userName[40];
    int likes;
    int dislikes;
    int followers;
}sUser;

//usr = short for sUser

int usr_comId(void* user1, void* user2);
int usr_comUsr(void* user1, void* user2);
int usr_comLks(void* user1, void* user2);
int usr_comDlk(void* user1, void* user2);
int usr_comFlw(void* user1, void* user2);

int usr_getId(sUser* user, int* id);
int usr_getUsr(sUser* user, char* userName);
int usr_getLks(sUser* user, int* likes);
int usr_getDlk(sUser* user, int* dislikes);
int usr_getFlw(sUser* user, int* followers);

int usr_setId(sUser* user, int id);
int usr_setUsr(sUser* user, char* userName);
int usr_setLks(sUser* user, int likes);
int usr_setDlk(sUser* user, int dislikes);
int usr_setFlw(sUser* user, int followers);

void usr_show(sUser* user);
int usr_showAll(LinkedList* user);

int usr_excPopular(void* user, void* volume);
int usr_excHatted(void* user, void* diference);

sUser* usr_newEmpty();
sUser* usr_new(int id, char* userName, int likes, int dislikes, int followers);
#endif // sUser_H_INCLUDED
