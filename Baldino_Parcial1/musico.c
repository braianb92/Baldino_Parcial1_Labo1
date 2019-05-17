#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_strings.h"
#include "musico.h"

static int generarId(void);


/** \brief  add values entered by the user to
*           an existing array of musico
*           in an empty position.
* \param    array Musico* Pointer to array of
* \param    len int Array len of musico
* \param    msgE char Shows an error message to be printed
*           when a value is not valid.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
* */
int musico_addMusico(Musico* arrayMusico,Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,
                    int lenMusico,int lenOrquesta,int lenInstrumento,char* msgE,int tries)
{
    int indexFree;
    int retorno=-1;
    char bufferName[30];
    char bufferSurname[30];
    char bufferEdad[30];
    int auxEdad;
    int auxIdOrquesta;
    int auxIdInstrumento;
    int posOfIdOrquesta;
    int posofIdInstrumento;
    if((arrayMusico!=NULL)&&(lenMusico>0)&&(arrayOrquesta!=NULL)&&(lenOrquesta>0)
       &&(arrayInstrumento!=NULL)&&(lenInstrumento>0))
    {
        indexFree=musico_findFree(arrayMusico,lenMusico);
        auxIdOrquesta=orquesta_getID(arrayOrquesta,lenOrquesta,msgE,tries);
        auxIdInstrumento=instrumento_getID(arrayInstrumento,lenInstrumento,msgE,tries);
        posOfIdOrquesta=orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,auxIdOrquesta);
        posofIdInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,auxIdInstrumento);
        if((indexFree!=-1)&&(auxIdOrquesta>=0)
           &&(posOfIdOrquesta!=-1)&&(auxIdInstrumento>=0)
           &&(posofIdInstrumento!=-1)
           &&(!getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries))
           &&(!getStringLetras(bufferSurname,"\nIngrese Apellido: ",msgE,tries))
           &&(!getStringNumeros(bufferEdad,"\nIngrese Edad: ",msgE,tries)))
        {
            auxEdad=atoi(bufferEdad);
            strncpy(arrayMusico[indexFree].name,bufferName,sizeof(bufferName));
            strncpy(arrayMusico[indexFree].surname,bufferSurname,sizeof(bufferSurname));
            arrayMusico[indexFree].edad=auxEdad;
            arrayMusico[indexFree].idOrquesta=auxIdOrquesta;
            arrayMusico[indexFree].idInstrumento=auxIdInstrumento;
            arrayMusico[indexFree].idMusico=generarId();
            arrayMusico[indexFree].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief  Modify values in an existing
*           array of musico
*           in an existing position.
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \param    generalMsgE char Shows an error message to be printed
*           when a value is not valid.
* \param    exitMenuNumber int Number that exits the menu
            and also used as max number to stablish a range
            of menu options to acces the corresponding function.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
* */
int musico_alter(Musico* array, int len,char* generalMsgE,int exitAlterMenuNumber,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    char bufferSurname[50];
    char* alterMenuText="\n1-Modificar Nombre\n2-Modificar Apellido\n"
                        "3- Atras (Menu Principal)\n";
    int retorno=-1;

    if((array!=NULL)&&(len>0))
    {
        auxID=musico_getID(array,len,generalMsgE,tries);
        if(auxID>=0)
        {
            posOfID=musico_findMusicoById(array,len,auxID);
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
                            if(!getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",generalMsgE,tries))
                            {
                                strncpy(array[posOfID].surname,bufferSurname,sizeof(bufferSurname));
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


/** \brief  Remove a musico by Id (put isEmpty Flag in 1)
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \param    msgE char Shows an error message to be printed
*           when a value is not valid.
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if wrong, (0) if OK.
**/
int musico_removeMusico(Musico* array, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(array!=NULL && len>0)
    {
        auxID=musico_getID(array,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=musico_findMusicoById(array,len,auxID);
            if(posOfID!=-1)
            {
               array[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int musico_sortMusico(Musico* array, int len,int order)///1up 0down
{
    int i;
    int j;
    int retorno=-1;
    Musico buffer;
    if(array!=NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {

            for(j=i+1;j<len;j++)
            {

                if((order==1)&&(strcmp(array[i].surname,array[j].surname)>0))
                {
                    buffer=array[i];
                    array[i]=array[j];
                    array[j]=buffer;
                    retorno=0;
                }
                else if((order==0)&&(strcmp(array[i].surname,array[j].surname)<0))
                {
                    buffer=array[i];
                    array[i]=array[j];
                    array[j]=buffer;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}


/** \brief  Indicates that all positions in the array are empty
*           by setting the flag isEmpty in 0 in all positions.
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \return   return 0.
**/
int musico_initMusico(Musico* array,int len)
{
    int i;
    if(array!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            //array[i].idMusico=-1;
            array[i].isEmpty=1;
        }
    }
    return 0;
}

/** \brief  Searchs through the array for a musico position.
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \return   return (-1) if no position found,
*           (Empty position) if empty position.
**/
int musico_findFree(Musico* array, int len)
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
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \param    idE Value to be found and matched in the array.
* \return   return (-1) if not found,
*           (position) if position matched.
**/
int musico_findMusicoById(Musico* array, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if((array[i].isEmpty==0)&&(array[i].idMusico==idE))
        {
            ret=i;
        }
    }
    return ret;
}

/** \brief  Asks the user to enter an ID.
* \param    array Musico* Pointer to array of Musico
* \param    len int Array len of musico
* \param    msgE char Shows an error message to be printed
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return (-1) if error, (ID) if OK
**/
int musico_getID (Musico* array,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(array!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese Codigo de Musico: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

/** \brief  Shows the values of occupied positions.
* \param    array Musico* Pointer to array of musico
* \param    len int Array len of musico
* \param    msgE char Shows an error message to be printed
* \param    tries The times user can try to enter
*           a valid value if something goes wrong.
* \return   return 0.
**/
int musico_printMusico(Musico* array,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(array[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\n"
            "Edad: %d\nCodigo Orquesta: %d\nCodigo Instrumento: %d\n-------\n",
                   array[i].idMusico,
                   array[i].name,
                   array[i].surname,
                   array[i].edad,
                   array[i].idOrquesta,
                   array[i].idInstrumento);
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
