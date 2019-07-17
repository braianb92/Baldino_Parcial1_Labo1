#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "llamada.h"


int parser_loadLlamadoFromText(FILE* pFile, LinkedList* lista)
{
    char bufferId[4096];
    char bufferDate[4096];
    char bufferCliente[4096];
    char bufferProblema[4096];
    char bufferSolucion[4096];
    int cantidadDatos;
    Llamada *pLlamado;
    int retorno=-1;

    if(pFile != NULL && lista!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId,
                                                        bufferDate,
                                                        bufferCliente,
                                                        bufferProblema,
                                                        bufferSolucion);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                            bufferDate,
                                                                            bufferCliente,
                                                                            bufferProblema,
                                                                            bufferSolucion);
            if(cantidadDatos==5)
            {
                pLlamado = llamada_newParametros(bufferId,bufferDate,bufferCliente,
                                            bufferProblema,bufferSolucion);
                if(pLlamado != NULL)
                {
                    if(!ll_add(lista,pLlamado))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

