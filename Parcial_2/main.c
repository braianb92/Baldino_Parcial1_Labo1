#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "venta.h"
#include "LinkedList.h"
#include "informe.h"

int main()
{
    LinkedList* listaVentas=ll_newLinkedList();
    controller_ventaLoadFromText("data.csv",listaVentas);
    generarInforme("informe.txt",listaVentas);
    return 0;
}
