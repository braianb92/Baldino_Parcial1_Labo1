#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Llamada* llamada_new()
{
    return (Llamada*) malloc(sizeof(Llamada));
}

Llamada* llamada_newParametros(char* idStr,char* dateStr,char* clienteStr,char* problemaStr,char* solucionStr)
{

    Llamada* pLlamada=llamada_new();
    if(pLlamada!=NULL)
    {

        if(!llamada_setDate(pLlamada,dateStr)&&
           !llamada_setCliente(pLlamada,clienteStr)&&
           !llamada_setProblema(pLlamada,problemaStr)&&
           !llamada_setSolucion(pLlamada,solucionStr)&&
           !llamada_setId(pLlamada,idStr))
           {
               return pLlamada;
           }
           else
           {
               pLlamada=NULL;
           }

    }
    return pLlamada;
}

int llamada_delete(Llamada* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int llamada_setId(Llamada* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->id = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int llamada_setCliente(Llamada* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->cliente = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int llamada_getCliente(Llamada* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cliente;
        retorno = 0;
    }
    return retorno;
}

int llamada_setDate(Llamada* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isFecha(value))
    {
        if(strlen(value)==10)
        {
            strncpy(this->date,value,sizeof(this->date));
            retorno = 0;
        }
    }
    return retorno;
}



int llamada_setSolucion(Llamada* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->solucion,value,sizeof(this->solucion));
        retorno = 0;
    }
    return retorno;
}

int llamada_getDate(Llamada* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->date,sizeof(this->date));
        retorno = 0;
    }
    return retorno;
}


int llamada_getSolucion(Llamada* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->solucion,sizeof(this->solucion));
        retorno = 0;
    }
    return retorno;
}

int llamada_getId(Llamada* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int llamada_sortByDate(void* llamadaA,void* llamadaB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Llamada* pLlamadaA;
    Llamada* pLlamadaB;

    pLlamadaA=(Llamada*)llamadaA;
    pLlamadaB=(Llamada*)llamadaB;
    if(strcmp(pLlamadaA->date,pLlamadaB->date)>0)
    {
        return mayor;
    }
    if(strcmp(pLlamadaA->date,pLlamadaB->date)<0)
    {
        return menor;
    }
    return igual;
}

int llamada_setProblema(Llamada* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->problema = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int llamada_getProblema(Llamada* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->problema;
        retorno = 0;
    }
    return retorno;
}


/*
static int generarId(void)
{
    static int idLlamada=1;
    return idLlamada++;
}*/
