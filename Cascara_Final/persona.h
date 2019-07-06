#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct
{
    int id;
    char birth[200];
    int day;
    int month;
    int year;
    char nombre[200];
    char apellido[200];
    char trabajo[200];
    char dni[200];
    char cuit[200];
}Persona;

Persona* persona_new();
Persona* persona_newParametros(char* idStr,char* birthStr,char* nombreStr,
                               char* apellidoStr,char* dniStr,char* cuitStr,
                               char* trabajoStr,char* dayStr,char* monthStr,
                               char* yearStr);
int persona_delete();

int persona_setId(Persona* this, char* value);
int persona_getId(Persona* this,int* value);

int persona_setBirth(Persona* this,char* value);
int persona_getBirth(Persona* this,char* value);

int persona_setDateInteger(Persona* this, char* dayStr,char* monthStr,char* yearStr);
int persona_getDateInteger(Persona* this, int* pDay,int* pMonth,int* pYear);

int persona_setNombre(Persona* this,char* value);
int persona_getNombre(Persona* this,char* value);

int persona_setApellido(Persona* this,char* value);
int persona_getApellido(Persona* this,char* value);

int persona_setTrabajo(Persona* this,char* value);
int persona_getTrabajo(Persona* this,char* value);

int persona_setDni(Persona* this,char* value);
int persona_getDni(Persona* this,char* value);

int persona_setCuit(Persona* this,char* value);
int persona_getCuit(Persona* this,char* value);

int persona_sortByBirth(void* personaA,void* personaB);

#endif // PERSONA_H_INCLUDED
