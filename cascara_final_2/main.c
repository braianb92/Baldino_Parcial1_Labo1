#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "llamada.h"
#include "LinkedList.h"
#include "informe.h"
#include "Baldino_String_Geters.h"


int main()
{
    int option;
    char fileName[500];
    int idProblema;
    LinkedList* listaLlamados=ll_newLinkedList();
    LinkedList* listaProblema;

     do{
        getIntInRange(&option,"\n1)Cargar Archivo\n"
                                "2)Imprimir Llamadas\n"
                                "3)Generar Archivo de Llamadas\n"
                                "4)Salir\n"
                                ,"\nERROR\n",1,4,3);
        switch(option)
        {
            case 1:
                if(!getStringLetras(fileName,"Ingrese nombre de archivo a cargar:","\nERROR\n",3))
                {
                    if(!controller_llamadoLoadFromText(fileName,listaLlamados))
                    {
                       printf("\n--El archivo se cargo correctamente--");
                    }
                    else
                    {
                        printf("\n--ERROR AL CARGAR ARCHIVO--");
                    }
                }
                break;
            case 2:
                controller_List(listaLlamados);
                printf("\n**FIN DE LA LISTA**\n");
                break;
            case 3:
                    getIntInRange(&idProblema,"Ingrese problema:","\nERROR\n",1,5,3);
                    if(idProblema==1)
                    {
                        listaProblema=ll_filter(listaLlamados,listaProblema1);
                        generarArchivo("listaProblema1.csv",listaProblema);
                    }
                    else if(idProblema==2)
                    {
                        listaProblema=ll_filter(listaLlamados,listaProblema2);
                        generarArchivo("listaProblema2.csv",listaProblema);
                    }
                    else if(idProblema==3)
                    {
                        listaProblema=ll_filter(listaLlamados,listaProblema3);
                        generarArchivo("listaProblema3.csv",listaProblema);
                    }
                    else if(idProblema==4)
                    {
                        listaProblema=ll_filter(listaLlamados,listaProblema4);
                        generarArchivo("listaProblema4.csv",listaProblema);
                    }
                    else if(idProblema==5)
                    {
                        listaProblema=ll_filter(listaLlamados,listaProblema5);
                        generarArchivo("listaProblema5.csv",listaProblema);
                    }





                break;
        }
    }while(option != 4);
    return 0;
}
