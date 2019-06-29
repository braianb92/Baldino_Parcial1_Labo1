#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "LinkedList.h"
#include "informe.h"


int cantidadMayor150(LinkedList* arrayList)
{
    Venta* pVenta;
    int i;
    int auxCant;
    float auxPrec;
    int calculo;
    int contador=0;
    int ret=-1;

    if(arrayList!=NULL)
    {
        for(i=0;i<ll_len(arrayList);i++)
        {
            pVenta=ll_get(arrayList,i);
            if(pVenta!=NULL)
            {
                venta_getCantidad(pVenta,&auxCant);
                venta_getPrecioUnitario(pVenta,&auxPrec);
                calculo=auxPrec*auxCant;
                if(calculo>150)
                {
                   contador++;
                }
            }
        }
        ret=contador;
    }
    return ret;
}

int cantidadMayor300(LinkedList* arrayList)
{
    Venta* pVenta;
    int i;
    int auxCant;
    float auxPrec;
    int calculo;
    int contador=0;
    int ret=-1;

    if(arrayList!=NULL)
    {
        for(i=0;i<ll_len(arrayList);i++)
        {
            pVenta=ll_get(arrayList,i);
            if(pVenta!=NULL)
            {
                venta_getCantidad(pVenta,&auxCant);
                venta_getPrecioUnitario(pVenta,&auxPrec);
                calculo=auxPrec*auxCant;
                if(calculo>300)
                {
                   contador++;
                }
            }
        }
        ret=contador;
    }
    return ret;
}

int cantidadReveladoPolaroid(LinkedList* arrayList,int* polaroid)
{
    Venta* pVenta;
    int auxCant;
    char bufferTipo[4000];
    int contador=0;
    int i;
    int ret=-1;
    if(arrayList!=NULL)
    {
        for(i=0;i<ll_len(arrayList);i++)
        {
            pVenta=ll_get(arrayList,i);
            if(pVenta!=NULL)
            {
                venta_getTipo(pVenta,bufferTipo);
                venta_getCantidad(pVenta,&auxCant);
                if((strcmp(bufferTipo,"POLAROID_10X10")==0)||(strcmp(bufferTipo,"POLAROID_11X9")==0))
                {
                    contador+=auxCant;
                }
            }
        }
        *polaroid=contador;
        ret=0;
    }
    return ret;
}

int generarInforme(char* path , LinkedList* arrayList)
{
    int size;
    int size150;
    int size300;
    int reveladasTotales;
    int reveladoPolaroid;
    int retorno=-1;

    FILE* fp=fopen(path,"w+");
    if(fp!=NULL && arrayList!=NULL)
    {
        size=ll_len(arrayList);
        if(!cantidadReveladoPolaroid(arrayList,&reveladoPolaroid)
           &&size>0)
        {
            reveladasTotales=ll_count(arrayList,cantidadReveladoL);
            size150=cantidadMayor150(arrayList);
            size300=cantidadMayor300(arrayList);
            if(size150!=-1&&size300!=-1)
            {
                /*
                48279-465-443-171
                */
                fprintf(fp,"\tCantidad: de fotos reveladas totales: %d\n",reveladasTotales);
                fprintf(fp,"\tCantidad: de ventas por un monto mayor a $150: %d\n",size150);
                fprintf(fp,"\tCantidad: de ventas por un monto mayor a $300: %d\n",size300);
                fprintf(fp,"\tCantidad: de fotos Polaroids reveladas: %d\n",reveladoPolaroid);
                fclose(fp);
                retorno=0;
            }
        }
    }
    return retorno;
}


int cantidadReveladoL(void* p)
{
    Venta* pVenta=p;
    int auxCant;
    int contador=0;
    int ret=-1;

    venta_getCantidad(pVenta,&auxCant);
    contador=auxCant;
    ret=contador;

    return ret;
}

int cantidadRevelado150L(void* p)
{
    Venta* pVenta=p;
    int auxCant;
    int auxPrecio;
    int calculo;

    int ret=0;

    venta_getCantidad(pVenta,&auxCant);
        venta_getPrecioUnitario(pVenta,&auxPrecio);
    calculo=auxCant*auxPrecio;
    if(calculo>150)
    {
        ret=1;
    }

    return ret;
}
