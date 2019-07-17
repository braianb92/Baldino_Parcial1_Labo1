#ifndef LLAMADO_H_INCLUDED
#define LLAMADO_H_INCLUDED

typedef struct
{
    int id;
    char date[200];
    int cliente; //nuevo
    int problema; //problema reemplazo
    char solucion[200]; //solucion reemplazo
}Llamado;

Llamado* llamado_new();
Llamado* llamado_newParametros(char* idStr,char* dateStr,char* clienteStr,char* problemaStr,char* solucionStr);
int llamado_delete();

int llamado_setId(Llamado* this, char* value);
int llamado_getId(Llamado* this,int* value);

int llamado_setCliente(Llamado* this, char* value);
int llamado_getCliente(Llamado* this,int* value);

int llamado_setDate(Llamado* this,char* value);
int llamado_getDate(Llamado* this,char* value);

int llamado_setSolucion(Llamado* this,char* value);
int llamado_getSolucion(Llamado* this,char* value);

int llamado_setProblema(Llamado* this, char* value);
int llamado_getProblema(Llamado* this, int* value);

int llamado_sortByDate(void* llamadoA,void* llamadoB);

#endif // LLAMADO_H_INCLUDED
