#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    char name[30];
    char lugar[30];
    int tipo; //Sinfonica(1);Filarmonica(2);Camara(3)
    int idOrquesta;
    int isEmpty; //1 free - 0 full
}Orquesta;

int orquesta_addOrquesta(Orquesta* array,int len,char* msgE,int tries);
int orquesta_alter(Orquesta* array, int len,char* generalMsgE,int exitAlterMenuNumber,int tries);
int orquesta_removeOrquesta(Orquesta* array, int len,char* msgE,int tries);
int orquesta_sortOrquesta(Orquesta* array, int len,int order);

int orquesta_printOrquesta(Orquesta* array,int len);

int orquesta_initOrquesta(Orquesta* array,int len);
int orquesta_findFree(Orquesta* array, int len);
int orquesta_findOrquestaById(Orquesta* array, int len, int idE);
int orquesta_getID (Orquesta* array,int len,char* msgE,int tries);

#endif // ORQUESTA_H_INCLUDED