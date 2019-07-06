#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

typedef struct
{
    int id;
    char date[200];
    char tipo[200];
    int cantidad;
    float precioUnitario;
    char cuit[200];
}Venta;

Venta* venta_new();
Venta* venta_newParametros(char* idStr,char* dateStr,char* tipoStr,char* cantidadStr,char* precioStr,char* cuitStr);
int venta_delete();

int venta_setId(Venta* this, char* value);
int venta_getId(Venta* this,int* value);

int venta_setDate(Venta* this,char* value);
int venta_getDate(Venta* this,char* value);

int venta_setTipo(Venta* this,char* value);
int venta_getTipo(Venta* this,char* value);

int venta_setCuit(Venta* this,char* value);
int venta_getCuit(Venta* this,char* value);

int venta_setCantidad(Venta* this, char* value);
int venta_getCantidad(Venta* this, int* value);

int venta_setPrecioUnitario(Venta* this, char* value);
int venta_getPrecioUnitario(Venta* this, float* value);

int venta_sortByDate(void* ventaA,void* ventaB);

#endif // VENTA_H_INCLUDED
