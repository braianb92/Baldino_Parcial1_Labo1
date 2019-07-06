#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "venta.h"
#include "empleado.h"
#include "persona.h"
#include "producto.h"

int parser_loadVentaFromText(FILE* pFile, LinkedList* lista)
{
    char bufferId[4096];
    char bufferDate[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferprecioUnitario[4096];
    char buffercuit[4096];
    int cantidadDatos;
    Venta *pVenta;
    int retorno=-1;

    if(pFile != NULL && lista!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                                bufferDate,
                                                                bufferTipo,
                                                                bufferCantidad,
                                                                bufferprecioUnitario,
                                                                buffercuit);
        do
        {
            cantidadDatos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",    bufferId,
                                                                                    bufferDate,
                                                                                    bufferTipo,
                                                                                    bufferCantidad,
                                                                                    bufferprecioUnitario,
                                                                                    buffercuit);
            if(cantidadDatos==6)
            {
                pVenta = venta_newParametros(bufferId,bufferDate,bufferTipo,
                                            bufferCantidad,bufferprecioUnitario,buffercuit);
                if(pVenta != NULL)
                {
                    if(!ll_add(lista,pVenta))
                    {
                        retorno=0;
                    }
                }
            }
        }while(!feof(pFile));
    }
    return retorno;
}

