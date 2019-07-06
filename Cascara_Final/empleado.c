#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Empleado* empleado_new()
{
    return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* empleado_newParametros(char* idStr,char* birthStr,char* nombreStr,
                               char* apellidoStr,char* dniStr,char* cuitStr,
                               char* trabajoStr,
                               char* horasTrabajadasStr)
{

    Empleado* pEmpleado=empleado_new();
    if(pEmpleado!=NULL)
    {

        if(!empleado_setId(pEmpleado,idStr)&&
           !empleado_setBirth(pEmpleado,birthStr)&&
           !empleado_setNombre(pEmpleado,nombreStr)&&
           !empleado_setApellido(pEmpleado,apellidoStr)&&
           !empleado_setDni(pEmpleado,dniStr)&&
           !empleado_setCuit(pEmpleado,cuitStr)&&
           !empleado_setTrabajo(pEmpleado,trabajoStr)&&
           !empleado_setHorasTrabajadas(pEmpleado,horasTrabajadasStr))
           {
               return pEmpleado;
           }
           else
           {
               pEmpleado=NULL;
           }
    }
    return pEmpleado;
}

int empleado_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int empleado_setBirth(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isFecha(value))
    {
        if(strlen(value)==10)
        {
            strncpy(this->birth,value,sizeof(this->birth));
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_getBirth(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->birth,sizeof(this->birth));
        retorno = 0;
    }
    return retorno;
}

int empleado_setCuit(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isCuit(value))
    {
        strncpy(this->cuit,value,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int empleado_getCuit(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int empleado_setNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int empleado_getNombre(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int empleado_setApellido(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->apellido,value,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int empleado_getApellido(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int empleado_setTrabajo(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->trabajo,value,sizeof(this->trabajo));
        retorno = 0;
    }
    return retorno;
}

int empleado_getTrabajo(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->trabajo,sizeof(this->trabajo));
        retorno = 0;
    }
    return retorno;
}

int empleado_setHorasTrabajadas(Empleado* this, char* value)
{
    int auxHoras;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumber(value))
    {
        auxHoras=atoi(value);
        if(auxHoras>=0)
        {
            this->horasTrabajadas = auxHoras;
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_getHorasTrabajadas(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int empleado_setSueldo(Empleado* this, char* value)
{
    float auxSueldo;
    int retorno = -1;

    if(this != NULL && value!=NULL && isNumberFloat(value))
    {
        auxSueldo=atof(value);
        if(auxSueldo>=0)
        {
            this->sueldo = auxSueldo;
            retorno = 0;
        }
    }
    return retorno;
}

int empleado_getSueldo(Empleado* this, float* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->sueldo;
        retorno = 0;
    }
    return retorno;
}

int empleado_setDni(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isDni(value))
    {
        strncpy(this->dni,value,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int empleado_getDni(Empleado* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int empleado_setId(Empleado* this, char* value)
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

int empleado_getId(Empleado* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int empleado_sortByBirth(void* empleadoA,void* empleadoB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Empleado* pEmpleadoA;
    Empleado* pEmpleadoB;

    pEmpleadoA=(Empleado*)empleadoA;
    pEmpleadoB=(Empleado*)empleadoB;
    if(strcmp(pEmpleadoA->birth,pEmpleadoB->birth)>0)
    {
        return mayor;
    }
    if(strcmp(pEmpleadoA->birth,pEmpleadoB->birth)<0)
    {
        return menor;
    }
    return igual;
}

/*
static int generarId(void)
{
    static int idEmpleado=1;
    return idEmpleado++;
}*/
