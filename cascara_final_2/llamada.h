#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int id;
    char date[200];
    int cliente; //nuevo
    int problema; //problema reemplazo
    char solucion[200]; //solucion reemplazo
}Llamada;

Llamada* llamada_new();
Llamada* llamada_newParametros(char* idStr,char* dateStr,char* clienteStr,char* problemaStr,char* solucionStr);
int llamada_delete();

int llamada_setId(Llamada* this, char* value);
int llamada_getId(Llamada* this,int* value);

int llamada_setCliente(Llamada* this, char* value);
int llamada_getCliente(Llamada* this,int* value);

int llamada_setDate(Llamada* this,char* value);
int llamada_getDate(Llamada* this,char* value);

int llamada_setSolucion(Llamada* this,char* value);
int llamada_getSolucion(Llamada* this,char* value);

int llamada_setProblema(Llamada* this, char* value);
int llamada_getProblema(Llamada* this, int* value);

int llamada_sortByDate(void* llamadaA,void* llamadaB);

#endif // LLAMADA_H_INCLUDED
