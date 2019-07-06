#include <stdio.h>
#include <stdlib.h>
#include "venta.h"
#include "controller.h"
#include "Parser.h"
#include "Baldino_String_Geters.h"

int controller_ventaLoadFromText(char* path , LinkedList* arrayList)
{
    FILE* pFile;
    int retorno=-1;
    if(arrayList!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile!=NULL)
        {
            if(!parser_loadFromText(pFile , arrayList))
            {
                fclose(pFile);
                retorno=0;
            }
        }
    }
    return retorno;
}


