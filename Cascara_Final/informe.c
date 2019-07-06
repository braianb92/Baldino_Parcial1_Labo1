#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "venta.h"
#include "LinkedList.h"
#include "informe.h"

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
        if(size>0)
        {
            reveladasTotales=ll_count(arrayList,cantidadReveladoTotal);
            size150=ll_count(arrayList,cantidadReveladoMayorA150);
            size300=ll_count(arrayList,cantidadReveladoMayorA300);
            reveladoPolaroid=ll_count(arrayList,cantidadReveladoPolaroid);
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


int cantidadReveladoTotal(void* p)
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

int cantidadReveladoPolaroid(void* p)
{
    Venta* pVenta=p;
    char bufferTipo[4096];
    char* cad1="POLAROID_10x10";
    char* cad2="POLAROID_11x9";
    int contador=0;
    int ret=-1;

    venta_getTipo(pVenta,bufferTipo);
    if((strcmp(bufferTipo,cad1)==0)||(strcmp(bufferTipo,cad2)==0))
    {
        contador=1;
    }
    ret=contador;
    return ret;
}

int cantidadReveladoMayorA150(void* p)
{
    Venta* pVenta=p;
    int auxCant;
    float auxPrecio;
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

int cantidadReveladoMayorA300(void* p)
{
    Venta* pVenta=p;
    int auxCant;
    float auxPrecio;
    int calculo;
    int ret=0;

    venta_getCantidad(pVenta,&auxCant);
    venta_getPrecioUnitario(pVenta,&auxPrecio);
    calculo=auxCant*auxPrecio;
    if(calculo>300)
    {
        ret=1;
    }

    return ret;
}
