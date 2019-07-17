#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Llamado* llamado_new()
{
    return (Llamado*) malloc(sizeof(Llamado));
}

Llamado* llamado_newParametros(char* idStr,char* dateStr,char* clienteStr,char* problemaStr,char* solucionStr)
{

    Llamado* pLlamado=llamado_new();
    if(pLlamado!=NULL)
    {

        if(!llamado_setDate(pLlamado,dateStr)&&
           !llamado_setCliente(pLlamado,clienteStr)&&
           !llamado_setProblema(pLlamado,problemaStr)&&
           !llamado_setSolucion(pLlamado,solucionStr)&&
           !llamado_setId(pLlamado,idStr))
           {
               return pLlamado;
           }
           else
           {
               pLlamado=NULL;
           }
           /*
           llamado_setDate(pLlamado,dateStr);
           llamado_setTipo(pLlamado,tipoStr);
           llamado_setProblema(pLlamado,problemaStr);
           llamado_setPrecioUnitario(pLlamado,precioStr);
           llamado_setSolucion(pLlamado,solucionStr);
           llamado_setId(pLlamado,idStr);
           */
    }
    return pLlamado;
}

int llamado_delete(Llamado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int llamado_setId(Llamado* this, char* value)
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

int llamado_setCliente(Llamado* this, char* value)
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

int llamado_getCliente(Llamado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cliente;
        retorno = 0;
    }
    return retorno;
}

int llamado_setDate(Llamado* this, char* value)
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



int llamado_setSolucion(Llamado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->solucion,value,sizeof(this->solucion));
        retorno = 0;
    }
    return retorno;
}

int llamado_getDate(Llamado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->date,sizeof(this->date));
        retorno = 0;
    }
    return retorno;
}


int llamado_getSolucion(Llamado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->solucion,sizeof(this->solucion));
        retorno = 0;
    }
    return retorno;
}

int llamado_getId(Llamado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int llamado_sortByDate(void* llamadoA,void* llamadoB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Llamado* pLlamadoA;
    Llamado* pLlamadoB;

    pLlamadoA=(Llamado*)llamadoA;
    pLlamadoB=(Llamado*)llamadoB;
    if(strcmp(pLlamadoA->date,pLlamadoB->date)>0)
    {
        return mayor;
    }
    if(strcmp(pLlamadoA->date,pLlamadoB->date)<0)
    {
        return menor;
    }
    return igual;
}

int llamado_setProblema(Llamado* this, char* value)
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

int llamado_getProblema(Llamado* this, int* value)
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
    static int idLlamado=1;
    return idLlamado++;
}*/
