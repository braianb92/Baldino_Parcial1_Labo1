#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char birth[200];
    char nombre[200];
    char apellido[200];
    char trabajo[200];
    int horasTrabajadas;
    float sueldo;
    char dni[200];
    char cuit[200];
}Empleado;

Empleado* empleado_new();
Empleado* empleado_newParametros(char* idStr,char* birthStr,char* nombreStr,
                               char* apellidoStr,char* dniStr,char* cuitStr,
                               char* trabajoStr,char* horasTrabajadasStr);
int empleado_delete();

int empleado_setId(Empleado* this, char* value);
int empleado_getId(Empleado* this,int* value);

int empleado_setBirth(Empleado* this,char* value);
int empleado_getBirth(Empleado* this,char* value);

int empleado_setNombre(Empleado* this,char* value);
int empleado_getNombre(Empleado* this,char* value);

int empleado_setApellido(Empleado* this,char* value);
int empleado_getApellido(Empleado* this,char* value);

int empleado_setTrabajo(Empleado* this,char* value);
int empleado_getTrabajo(Empleado* this,char* value);

int empleado_setHorasTrabajadas(Empleado* this,char* value);
int empleado_getHorasTrabajadas(Empleado* this,int* value);

int empleado_setSueldo(Empleado* this,char* value);
int empleado_getSueldo(Empleado* this,float* value);

int empleado_setDni(Empleado* this,char* value);
int empleado_getDni(Empleado* this,char* value);

int empleado_setCuit(Empleado* this,char* value);
int empleado_getCuit(Empleado* this,char* value);

int empleado_sortByBirth(void* empleadoA,void* empleadoB);

#endif // EMPLEADO_H_INCLUDED
