#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Venta* venta_new()
{
    return (Venta*) malloc(sizeof(Venta));
}

Venta* venta_newParametros(char* idStr,char* dateStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr)
{

    Venta* pVenta=venta_new();
    if(pVenta!=NULL)
    {

        if(!venta_setDate(pVenta,dateStr)&&
           !venta_setTipo(pVenta,tipoStr)&&
           !venta_setCantidad(pVenta,cantidadStr)&&
           !venta_setPrecioUnitario(pVenta,precioStr)&&
           !venta_setCuit(pVenta,cuitStr)&&
           !venta_setId(pVenta,idStr))
           {
               return pVenta;
           }
           else
           {
               pVenta=NULL;
           }
           /*
           venta_setDate(pVenta,dateStr);
           venta_setTipo(pVenta,tipoStr);
           venta_setCantidad(pVenta,cantidadStr);
           venta_setPrecioUnitario(pVenta,precioStr);
           venta_setCuit(pVenta,cuitStr);
           venta_setId(pVenta,idStr);
           */
    }
    return pVenta;
}

int venta_delete(Venta* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int venta_setId(Venta* this, char* value)
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

int venta_setDate(Venta* this, char* value)
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

int venta_setTipo(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isAlphanumeric(value))
    {
        if(strlen(value)>=3)
        {
            strncpy(this->tipo,value,sizeof(this->tipo));
            retorno = 0;
        }
    }
    return retorno;
}


int venta_setCuit(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isCuit(value))
    {
        strncpy(this->cuit,value,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_getDate(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->date,sizeof(this->date));
        retorno = 0;
    }
    return retorno;
}

int venta_getTipo(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int venta_getCuit(Venta* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int venta_getId(Venta* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int venta_sortByDate(void* ventaA,void* ventaB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Venta* pVentaA;
    Venta* pVentaB;

    pVentaA=(Venta*)ventaA;
    pVentaB=(Venta*)ventaB;
    if(strcmp(pVentaA->date,pVentaB->date)>0)
    {
        return mayor;
    }
    if(strcmp(pVentaA->date,pVentaB->date)<0)
    {
        return menor;
    }
    return igual;
}

int venta_setCantidad(Venta* this, char* value)
{
    int auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxID=atoi(value);
        if(auxID>=0)
        {
            this->cantidad = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getCantidad(Venta* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cantidad;
        retorno = 0;
    }
    return retorno;
}


int venta_setPrecioUnitario(Venta* this, char* value)
{
    float auxID;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumberFloat(value))
    {
        auxID=atof(value);
        if(auxID>=0)
        {
            this->precioUnitario = auxID;
            retorno = 0;
        }
    }
    return retorno;
}

int venta_getPrecioUnitario(Venta* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->precioUnitario;
        retorno = 0;
    }
    return retorno;
}
/*
static int generarId(void)
{
    static int idVenta=1;
    return idVenta++;
}*/
