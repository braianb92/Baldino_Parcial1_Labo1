#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llamada.h"
#include "controller.h"
#include "Parser.h"

int controller_llamadoLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_loadLlamadoFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}

int controller_List(LinkedList* list)
{
    Llamada* pE;
    int auxId;
    char auxDate[4096];
    int auxCliente;
    int auxProblema;
    char auxSolucion[4096];
    char problemaStr [5000];
    int size;
    int i;

    if(list!=NULL)
    {
        size=ll_len(list);
        for(i=0;i<size;i++)
        {
            pE=ll_get(list,i);
            llamada_getId(pE,&auxId);
            llamada_getDate(pE,auxDate);
            llamada_getCliente(pE,&auxCliente);
            llamada_getProblema(pE,&auxProblema);
            llamada_getSolucion(pE,auxSolucion);
            if(pE!=NULL)
            {
               switch(auxProblema)
                {
                    case 1:
                        strncpy(problemaStr,"No enciende PC",sizeof(problemaStr));
                        break;
                    case 2:
                        strncpy(problemaStr,"No funciona Mouse",sizeof(problemaStr));
                        break;
                    case 3:
                        strncpy(problemaStr,"No funciona teclado",sizeof(problemaStr));
                        break;
                    case 4:
                        strncpy(problemaStr,"No hay internet",sizeof(problemaStr));
                        break;
                    case 5:
                        strncpy(problemaStr,"No funciona telefono",sizeof(problemaStr));
                        break;
                }
                printf("\n---------------"
                       "\nLlamada: %d"
                       "\nFecha: %s"
                       "\nCliente: %d"
                       "\nProblema: %s"
                       "\nSolucionado: %s",
                       auxId,
                       auxDate,
                       auxCliente,
                       problemaStr,
                       auxSolucion);
            }
        }
    }
    return 1;

}

