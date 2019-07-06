#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Producto* producto_new()
{
    return (Producto*) malloc(sizeof(Producto));
}

Producto* producto_newParametros(char* idStr,char* nombreStr,char* dateStr,char* tipoStr,char* cantidadStr,char* precioStr)
{

    Producto* pProducto=producto_new();
    if(pProducto!=NULL)
    {

        if(!producto_setDate(pProducto,dateStr)&&
           !producto_setTipo(pProducto,tipoStr)&&
           !producto_setCantidad(pProducto,cantidadStr)&&
           !producto_setPrecioUnitario(pProducto,precioStr)&&
           !producto_setNombre(pProducto,nombreStr)&&
           !producto_setId(pProducto,idStr))
           {
               return pProducto;
           }
           else
           {
               pProducto=NULL;
           }
           /*
           producto_setDate(pProducto,dateStr);
           producto_setTipo(pProducto,tipoStr);
           producto_setCantidad(pProducto,cantidadStr);
           producto_setPrecioUnitario(pProducto,precioStr);
           producto_setCuit(pProducto,cuitStr);
           producto_setId(pProducto,idStr);
           */
    }
    return pProducto;
}

int producto_delete(Producto* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int producto_setId(Producto* this, char* value)
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

int producto_setNombre(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int producto_getNombre(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int producto_setDate(Producto* this, char* value)
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

int producto_setTipo(Producto* this, char* value)
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



int producto_getDate(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->date,sizeof(this->date));
        retorno = 0;
    }
    return retorno;
}

int producto_getTipo(Producto* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int producto_getId(Producto* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int producto_sortByDate(void* productoA,void* productoB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Producto* pProductoA;
    Producto* pProductoB;

    pProductoA=(Producto*)productoA;
    pProductoB=(Producto*)productoB;
    if(strcmp(pProductoA->date,pProductoB->date)>0)
    {
        return mayor;
    }
    if(strcmp(pProductoA->date,pProductoB->date)<0)
    {
        return menor;
    }
    return igual;
}

int producto_setCantidad(Producto* this, char* value)
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

int producto_getCantidad(Producto* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->cantidad;
        retorno = 0;
    }
    return retorno;
}


int producto_setPrecioUnitario(Producto* this, char* value)
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

int producto_getPrecioUnitario(Producto* this, float* value)
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
    static int idProducto=1;
    return idProducto++;
}*/
