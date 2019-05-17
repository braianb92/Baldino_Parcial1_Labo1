#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"

typedef struct
{
    char name[30];
    char surname[30];
    int edad;
    int idOrquesta;
    int idInstrumento;
    int idMusico;
    int isEmpty; //1 free - 0 full
}Musico;

int musico_addMusico(Musico* arrayMusico,Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,
                    int lenMusico,int lenOrquesta,int lenInstrumento,char* msgE,int tries);

int musico_alter(Musico* array, int len,char* generalMsgE,int exitAlterMenuNumber,int tries);
int musico_removeMusico(Musico* array, int len,char* msgE,int tries);
int musico_sortMusico(Musico* array, int len,int order);

int musico_printMusico(Musico* array,int len);

int musico_initMusico(Musico* array,int len);
int musico_findFree(Musico* array, int len);
int musico_findMusicoById(Musico* array, int len, int idE);
int musico_getID (Musico* array,int len,char* msgE,int tries);

#endif // MUSICO_H_INCLUDED
