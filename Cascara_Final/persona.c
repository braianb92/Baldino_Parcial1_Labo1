#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#include "Baldino_String_Geters.h"
#include "validaciones.h"

//static int generarId(void);

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(char* idStr,char* birthStr,char* nombreStr,
                               char* apellidoStr,char* dniStr,char* cuitStr,
                               char* trabajoStr)
{

    Persona* pPersona=persona_new();
    if(pPersona!=NULL)
    {

        if(!persona_setId(pPersona,idStr)&&
           !persona_setBirth(pPersona,birthStr)&&
           !persona_setNombre(pPersona,nombreStr)&&
           !persona_setApellido(pPersona,apellidoStr)&&
           !persona_setDni(pPersona,dniStr)&&
           !persona_setCuit(pPersona,cuitStr)&&
           !persona_setTrabajo(pPersona,trabajoStr))
           {
               return pPersona;
           }
           else
           {
               pPersona=NULL;
           }
    }
    return pPersona;
}

int persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int persona_setId(Persona* this, char* value)
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

int persona_setBirth(Persona* this, char* value)
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

int persona_getBirth(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->birth,sizeof(this->birth));
        retorno = 0;
    }
    return retorno;
}

int persona_setCuit(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isCuit(value))
    {
        strncpy(this->cuit,value,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int persona_getCuit(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->cuit,sizeof(this->cuit));
        retorno = 0;
    }
    return retorno;
}

int persona_setNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->nombre,value,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_setApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->apellido,value,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_getApellido(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}

int persona_setTrabajo(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isLetter(value))
    {
        strncpy(this->trabajo,value,sizeof(this->trabajo));
        retorno = 0;
    }
    return retorno;
}

int persona_getTrabajo(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->trabajo,sizeof(this->trabajo));
        retorno = 0;
    }
    return retorno;
}

int persona_setDni(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL && isDni(value))
    {
        strncpy(this->dni,value,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int persona_getDni(Persona* this, char* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        strncpy(value,this->dni,sizeof(this->dni));
        retorno = 0;
    }
    return retorno;
}

int persona_getId(Persona* this, int* value)
{
    int retorno = -1;
    if(this != NULL && value!=NULL)
    {
        *value=this->id;
        retorno = 0;
    }
    return retorno;
}


int persona_sortByBirth(void* personaA,void* personaB)
{
    int mayor=1;
    int menor=-1;
    int igual=0;
    Persona* pPersonaA;
    Persona* pPersonaB;

    pPersonaA=(Persona*)personaA;
    pPersonaB=(Persona*)personaB;
    if(strcmp(pPersonaA->birth,pPersonaB->birth)>0)
    {
        return mayor;
    }
    if(strcmp(pPersonaA->birth,pPersonaB->birth)<0)
    {
        return menor;
    }
    return igual;
}

/*
static int generarId(void)
{
    static int idPersona=1;
    return idPersona++;
}*/
