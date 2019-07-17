#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[200];
    char date[200];
    char tipo[200];
    int cantidad;
    float precioUnitario;
}Producto;

Producto* producto_new();
Producto* producto_newParametros(char* idStr,char* nombreStr,char* dateStr,char* tipoStr,char* cantidadStr,char* precioStr);
int producto_delete();

int producto_setId(Producto* this, char* value);
int producto_getId(Producto* this,int* value);

int producto_setNombre(Producto* this,char* value);
int producto_getNombre(Producto* this,char* value);

int producto_setDate(Producto* this,char* value);
int producto_getDate(Producto* this,char* value);

int producto_setTipo(Producto* this,char* value);
int producto_getTipo(Producto* this,char* value);

int producto_setCantidad(Producto* this, char* value);
int producto_getCantidad(Producto* this, int* value);

int producto_setPrecioUnitario(Producto* this, char* value);
int producto_getPrecioUnitario(Producto* this, float* value);

int producto_sortByDate(void* productoA,void* productoB);

#endif // PRODUCTO_H_INCLUDED
