#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
//------VENTA-----------
int cantidadReveladoTotal(void* p);
int cantidadReveladoMayorA150(void* p);
int cantidadReveladoMayorA300(void* p);
int cantidadReveladoPolaroid(void* p);
int generarInforme_venta(char* path , LinkedList* arrayList);

//-------EMPLEADO-------
int calcularSueldo(void* p);
int promedioSueldos(LinkedList* lista,float* promedio);


#endif // INFORME_H_INCLUDED
