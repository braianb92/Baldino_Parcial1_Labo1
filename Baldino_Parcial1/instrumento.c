#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_strings.h"
#include "instrumento.h"

static int generarId(void);


/** \brief  add values entered by the user to
*           an existing array of instrumento
*           in an empty position.
* \param    array Instrumento* Pointer to array of
* \param    len int Array len of instrumento
* \param    msgE char Shows an error message to be printed
*           when a value is not valid.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
* */
int instrumento_addInstrumento(Instrumento* array,int len,char* msgE,int tries)
{
    int indexFree;
    char bufferName[50];
    int auxTipo;
    int retorno=-1;
    if((array!=NULL)&&(len>0))
    {
        indexFree=instrumento_findFree(array,len);
        if((indexFree!=-1)&&(getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (!getIntInRange(&auxTipo,"\nIngrese Tipo Cuerdas(1)/"
            "Viento-madera(2)/Viento-metal(3)/Percusion(4): ",
            msgE,1,4,tries)))
        {
            strncpy(array[indexFree].name,bufferName,sizeof(bufferName));
            array[indexFree].tipo=auxTipo;
            array[indexFree].idInstrumento=generarId();
            array[indexFree].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Modify values in an existing
*           array of instrumento
*           in an existing position.
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of orquesta
* \param    generalMsgE char Shows an error message to be printed
*           when a value is not valid.
* \param    exitMenuNumber int Number that exits the menu
            and also used as max number to stablish a range
            of menu options to acces the corresponding function.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
* */
int instrumento_alter(Instrumento* array, int len,char* generalMsgE,int exitAlterMenuNumber,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    int auxTipo;
    char* alterMenuText="\n1-Modificar Nombre\n2-Modificar Tipo\n"
                        "3- Atras (Menu Principal)\n";
    int retorno=-1;

    if((array!=NULL)&&(len>0))
    {
        auxID=instrumento_getID(array,len,generalMsgE,tries);
        if(auxID>=0)
        {
            posOfID=instrumento_findInstrumentoById(array,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=exitAlterMenuNumber)
                {
                    printf(alterMenuText);
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",generalMsgE,1,
                                  exitAlterMenuNumber,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",generalMsgE,tries))
                            {
                                strncpy(array[posOfID].name,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getIntInRange(&auxTipo,"\nIngrese Tipo Cuerdas(1)/"
                                "Viento-madera(2)/Viento-metal(3)/Percusion(4): ",
                                generalMsgE,1,4,tries))
                            {
                                array[posOfID].tipo=auxTipo;
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}


/** \brief  Remove an instrumento by Id (put isEmpty Flag in 1)
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \param    msgE char Shows an error message to be printed
*           when a value is not valid.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int instrumento_removeInstrumento(Instrumento* array, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(array!=NULL && len>0)
    {
        auxID=instrumento_getID(array,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=instrumento_findInstrumentoById(array,len,auxID);
            if(posOfID!=-1)
            {
               array[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}


/** \brief  Indicates that all positions in the array are empty
*           by setting the flag isEmpty in 0 in all positions.
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \return   return 0.
**/
int instrumento_initInstrumento(Instrumento* array,int len)
{
    int i;
    if(array!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            //array[i].idInstrumento=-1;
            array[i].isEmpty=1;
        }
    }
    return 0;
}

/** \brief  Searchs through the array for an instrumento position.
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \return   return (-1) if no position found,
*           (Empty position) if empty position.
**/
int instrumento_findFree(Instrumento* array, int len)
{
    int i;
    int ret=-1;
    if(array!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty==1)
            {
                ret=i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
        if(ret==-1)
        {
            printf("\n----NO hay lugar libre!!----\n");
        }
    }
    return ret;
}

/** \brief  Searchs through the array for a
*           specific value(ID).
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \param    idE Value to be found and matched in the array.
* \return   return (-1) if not found,
*           (position) if position matched.
**/
int instrumento_findInstrumentoById(Instrumento* array, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if((array[i].isEmpty==0)&&(array[i].idInstrumento==idE))
        {
            ret=i;
        }
    }
    return ret;
}


/** \brief  Asks the user to enter an ID.
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \param    msgE char Shows an error message to be printed
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if error, (ID) if OK
**/
int instrumento_getID (Instrumento* array,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(array!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese Codigo de Instrumento: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

/** \brief  Shows the values of occupied positions.
* \param    array Instrumento* Pointer to array of instrumento
* \param    len int Array len of instrumento
* \param    msgE char Shows an error message to be printed
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return 0.
**/
int instrumento_printInstrumento(Instrumento* array,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nTipo Cuerda(1)/Viento-madera(2)/"
                    "Viento-metal(3)/Percusion(4): %d\n-------\n",
                   array[i].idInstrumento,
                   array[i].name,
                   array[i].tipo);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

/** \brief  Generates a unique ID.
* \param    receives void
* \return   return void.
**/
static int generarId(void)
{
    static int idEmp=0;
    return idEmp++;
}
