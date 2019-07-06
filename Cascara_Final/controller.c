#include <stdio.h>
#include <stdlib.h>
#include "venta.h"
#include "empleado.h"
#include "persona.h"
#include "producto.h"
#include "controller.h"
#include "Parser.h"

int controller_ventaLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_loadVentaFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}
