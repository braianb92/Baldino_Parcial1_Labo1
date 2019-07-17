#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "LinkedList.h"
#include "informe.h"
#include "Baldino_String_Geters.h"


int listaProblema1(void* p)
{
    Llamada* pLlamada=p;
    int auxProblema;
    int retortno=-1;

    llamada_getProblema(pLlamada,&auxProblema);
    if(auxProblema==1)
    {
        retortno=0;
    }
    return retortno;
}
int listaProblema2(void* p)
{
    Llamada* pLlamada=p;
    int auxProblema;
    int retortno=-1;

    llamada_getProblema(pLlamada,&auxProblema);
    if(auxProblema==2)
    {
        retortno=0;
    }
    return retortno;
}
int listaProblema3(void* p)
{
    Llamada* pLlamada=p;
    int auxProblema;
    int retortno=-1;

    llamada_getProblema(pLlamada,&auxProblema);
    if(auxProblema==3)
    {
        retortno=0;
    }
    return retortno;
}
int listaProblema4(void* p)
{
    Llamada* pLlamada=p;
    int auxProblema;
    int retortno=-1;

    llamada_getProblema(pLlamada,&auxProblema);
    if(auxProblema==4)
    {
        retortno=0;
    }
    return retortno;
}
int listaProblema5(void* p)
{
    Llamada* pLlamada=p;
    int auxProblema;
    int retortno=-1;

    llamada_getProblema(pLlamada,&auxProblema);
    if(auxProblema==5)
    {
        retortno=0;
    }
    return retortno;
}


int generarArchivo(char* fileName,LinkedList* lista)
{
    Llamada* pE;
    int auxId;
    char auxDate[4096];
    int auxCliente;
    int auxProblema;
    char auxSolucion[4096];
    int retorno=-1;
    int size;
    int i;

    FILE* fp=fopen(fileName,"w+");
    if(fp!=NULL && lista!=NULL)
    {
        fprintf(fp,"id_llamada,Fecha,Cliente,id_problema,Solucionado\n");
        size=ll_len(lista);
        for(i=0;i<size;i++)
        {
            pE=ll_get(lista,i);
            llamada_getId(pE,&auxId);
            llamada_getDate(pE,auxDate);
            llamada_getCliente(pE,&auxCliente);
            llamada_getProblema(pE,&auxProblema);
            llamada_getSolucion(pE,auxSolucion);
            if(pE!=NULL)
            {
                fprintf(fp,"%d,%s,%d,%d,%s\n",  auxId,
                                                auxDate,
                                                auxCliente,
                                                auxProblema,
                                                auxSolucion);
                retorno=0;
            }
        }
        fclose(fp);
    }
    return retorno;
}


/*
int cantidadReveladoTotal(void* p)
{
    Llamado* pLlamado=p;
    int auxCant;
    int contador=0;
    int ret=-1;

    Llamado_getCantidad(pLlamado,&auxCant);
    contador=auxCant;
    ret=contador;

    return ret;
}
*/

/*
int cantidadReveladoPolaroid(void* p)
{
    Llamado* pLlamado=p;
    char bufferTipo[4096];
    char* cad1="POLAROID_10x10";
    char* cad2="POLAROID_11x9";
    int contador=0;
    int ret=-1;

    Llamado_getTipo(pLlamado,bufferTipo);
    if((strcmp(bufferTipo,cad1)==0)||(strcmp(bufferTipo,cad2)==0))
    {
        contador=1;
    }
    ret=contador;
    return ret;
}
*/

/*
int cantidadReveladoMayorA150(void* p)
{
    Llamado* pLlamado=p;
    int auxCant;
    float auxPrecio;
    int calculo;
    int ret=0;

    Llamado_getCantidad(pLlamado,&auxCant);
    Llamado_getPrecioUnitario(pLlamado,&auxPrecio);
    calculo=auxCant*auxPrecio;
    if(calculo>150)
    {
        ret=1;
    }

    return ret;
}*/

/*
int cantidadReveladoMayorA300(void* p)
{
    Llamado* pLlamado=p;
    int auxCant;
    float auxPrecio;
    int calculo;
    int ret=0;

    Llamado_getCantidad(pLlamado,&auxCant);
    Llamado_getPrecioUnitario(pLlamado,&auxPrecio);
    calculo=auxCant*auxPrecio;
    if(calculo>300)
    {
        ret=1;
    }

    return ret;
}*/

//----------------------

/*
//---con ll_map-----
int calcularSueldoBasico(void* p)
{
    Empleado* pEmpleado=p;
    float sueldoBasico=250000;
    int horasTrabajadas;
    float auxSueldo;
    int retorno=-1;

    if(!empleado_getHorasTrabajadas(pEmpleado,&horasTrabajadas))
    {
        auxSueldo=sueldoBasico*horasTrabajadas;
        empleado_setSueldoFloat(pEmpleado,auxSueldo);
        retorno=0;
    }
    return retorno;
}

//----con ll_count---
int sueldosTotales (void* p)
{
    Empleado* pEmpleado=p;
    float auxSueldo;
    int retorno=0;

    if(!empleado_getSueldo(pEmpleado,&auxSueldo))
    {
        retorno=auxSueldo;
    }
    return retorno;
}

int promedioSueldos(LinkedList* lista,float* promedio)
{
    int cantidadEmpleados;
    int sumatoriaSueldos;
    int retorno=-1;

    if(lista!=NULL&&promedio!=NULL)
    {
        cantidadEmpleados=ll_len(lista);
        if(cantidadEmpleados>0)
        {
            sumatoriaSueldos=ll_count(lista,sueldosTotales);
            *promedio=sumatoriaSueldos/cantidadEmpleados;
            retorno=0;
        }
    }
    return retorno;
}*/
