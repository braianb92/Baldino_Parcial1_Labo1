#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "utn_strings.h"

int informe_menu(Orquesta* arrayOrquesta,Musico* arrayMusico,Instrumento* arrayInstrumento,
                 int lenOrquesta,int lenMusico,int lenInstrumento,int exitMenuNumber,int tries)
{
    //int cantOrqu;
    //int cantIns;
    //int cantMusc;
    //int tipoIns;
    int option=0;

    while(option!=exitMenuNumber)
    {
        printf("\n1-Orquesta con mas de 5 musicos(A)\n2-Musicos mas de 30(B)\n"
               "3-Orquestas lugar particular(C)\n4-Orquesta Completa(D)\n"
               "5-Listar Musico por Orquesta determinada(E)\n"
               "6-Orquesta con mas musicos(F)\n7-Musicos instrumentos de cuerda(G)\n"
               "8-Imprimir promedio de musicos por Orquestas(H)\n9-Atras (menu principal)\n");

        getIntInRange(&option,"\n   INGRESE OPCION: ","\nNO\n",1,exitMenuNumber,tries);
        switch(option)
        {
            case 1:
                informe_orquestaConMasde5Musicos(arrayOrquesta,arrayMusico,lenOrquesta,lenMusico);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                informe_printMusicosByOrquestaDeterminada(arrayMusico,arrayOrquesta,arrayInstrumento,lenMusico,lenOrquesta,
                                                          lenInstrumento,"\nERROR\n");
                break;
            case 6:
                informe_orquestaConMasMusicos(arrayOrquesta,arrayMusico,lenOrquesta,lenMusico);
                break;
            case 7:
                informe_printMusicoSoloCuerda(arrayMusico,arrayInstrumento,lenMusico,
                                              lenInstrumento);
                break;
            case 8:
                informe_promedioMusicosPorOrquesta(arrayMusico,arrayOrquesta,lenMusico,lenOrquesta);
                break;
        }
    }
    return 0;
}

/** \brief  Shows the total amount of salary between employees,
*           the average salary and the number of employees
*           over the average.
* \param    arrayEmployee Employee* Pointer to array of employees
* \param    lenEmployee int Array len of emplyee
* \return   return (-1) if wrong, (0) if OK.
**/
int informe_cantidadOrquestas(Orquesta* arrayOrquesta,int lenOrquesta,int* pCantidadOrquestas)
{
    int i;
    int contadorOrquestas=0;
    int ret=-1;
    if(arrayOrquesta!=NULL && lenOrquesta>0 && pCantidadOrquestas!=NULL)
    {
        for(i=0;i<lenOrquesta;i++)
        {
            if(arrayOrquesta[i].isEmpty==0)
            {
                contadorOrquestas++;
                ret=0;
            }
        }
        *pCantidadOrquestas=contadorOrquestas;
    }
    return ret;
}

/** \brief  Calculates the number of employees over
*           the average salary.
* \param    arrayEmployee Employee* Pointer to array of employees
* \param    lenEmployee int Array len of emplyee
* \param    promedioResult The average salary
* \param    valor Pointer that keeps the
*           number of employees that are
*           over the average salary.
* \return   return (-1) if wrong, (0) if OK.
**/
int informe_cantidadMusicos(Musico* arrayMusico,int lenMusico,int* pCantidadMusicos)
{
    int i;
    int contadorMusicos=0;
    int ret=-1;
    if(arrayMusico!=NULL && lenMusico>0 && pCantidadMusicos!=NULL)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                contadorMusicos++;
                ret=0;
            }
        }
        *pCantidadMusicos=contadorMusicos;
    }
    return ret;
}

/** \brief  Calculates the number of employees over
*           the average salary.
* \param    arrayEmployee Employee* Pointer to array of employees
* \param    lenEmployee int Array len of emplyee
* \param    promedioResult The average salary
* \param    valor Pointer that keeps the
*           number of employees that are
*           over the average salary.
* \return   return (-1) if wrong, (0) if OK.
**/
int informe_cantidadInstrumentos(Instrumento* arrayInstrumento,int lenInstrumento,int* pCantidadInst)
{
    int i;
    int contadorInstrumentos=0;
    int ret=-1;
    if(arrayInstrumento!=NULL && lenInstrumento>0 && pCantidadInst!=NULL)
    {
        for(i=0;i<lenInstrumento;i++)
        {
            if(arrayInstrumento[i].isEmpty==0)
            {
                contadorInstrumentos++;
                ret=0;
            }
        }
        *pCantidadInst=contadorInstrumentos;
    }
    return ret;
}

/*int informe_edadMusicoMasDe30(Musico* arrayMusico,Instrumento* arrayInstrumento,Orquesta* arrayOrquesta,int lenInstrumento,int lenMusico,int lenOrquesta)
{
    int i;
    int posIdIns;
    int posIdOrq;
    int retorno=-1;
    if(arrayMusico!=NULL && lenMusico>=0)
    {
        musico_sortMusicoByEdad(arrayMusico,lenMusico,1);
        for(i=1;i<lenMusico;i++)
        {
            if(arrayMusico[i].isEmpty==0&&arrayMusico[i].edad>=30)
            {
                posIdIns=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento);
                posIdOrq=Orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,arrayMusico[i].idInstrumento);
                printf("\nID Musico: %d\nNombre: %s\n"
                       "Apellido: %s\nEdad: %d\n",
                       arrayMusico[i].idMusico,
                       arrayMusico[i].name,
                       arrayMusico[i].surname,
                       arrayMusico[i].edad);
            }

    }
    return 0;
}*/

//ARREGLAR
int informe_InstrumentosMenosUsadosPorMusicos(Instrumento* arrayInstrumento,Musico* arrayMusico,
                                              int lenInstrumento,int lenMusico)
{
    int i;
    int min=lenMusico+1;
    int contadorOcurrencia=0;
    int IdInstrumentoMenorOcurrencia;
    int posIdInstrumento;
    char stringTipo[30];
    int retorno=-1;
    if(arrayInstrumento!=NULL && lenInstrumento>0
       && arrayMusico!=NULL && lenMusico>0)
    {
        musico_sortMusicosByInstrumentoEficiente(arrayMusico,lenMusico,1);
        for(i=1;i<lenMusico;i++)
        {
            if(arrayMusico[i-1].isEmpty==0&&arrayMusico[i].isEmpty==0)
            {
                if(arrayMusico[i-1].idInstrumento!=arrayMusico[i].idInstrumento)
                {
                    contadorOcurrencia++;
                }
                else
                {
                    contadorOcurrencia--;
                    min=0;

                }
                if(contadorOcurrencia<=min)
                {
                    min=contadorOcurrencia;
                    IdInstrumentoMenorOcurrencia=arrayMusico[i].idInstrumento;
                    posIdInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,
                                                            IdInstrumentoMenorOcurrencia);
                    if(posIdInstrumento!=-1)
                    {
                        switch(arrayInstrumento[posIdInstrumento].tipo)
                        {
                            case 1:
                               strncpy(stringTipo,"Cuerda",sizeof(stringTipo));
                               break;
                            case 2:
                                strncpy(stringTipo,"Viento-Madera",sizeof(stringTipo));
                                break;
                            case 3:
                                strncpy(stringTipo,"Viento-Metal",sizeof(stringTipo));
                                break;
                            case 4:
                                strncpy(stringTipo,"Percusion",sizeof(stringTipo));
                                break;
                        }
                        printf("\n----\nInstrumentos menos Usados Por Musicos\n----\n"
                               "Nombre: %s\nId Instrumento: %d\nTipo: %s\n",
                               arrayInstrumento[posIdInstrumento].name,
                               arrayInstrumento[posIdInstrumento].idInstrumento,
                               stringTipo);
                        retorno=0;
                    }
                }

            }


        }

    }
    return retorno;
}

int informe_InstrumentoMasUsadoPorMusicos(Instrumento* arrayInstrumento,Musico* arrayMusico,
                                              int lenInstrumento,int lenMusico)
{
    int i;
    int max=0;
    int contadorOcurrencia=0;
    int IdInstrumentoMayorOcurrencia;
    int posIdInstrumento;
    char stringTipo[30];
    int retorno=-1;
    if(arrayInstrumento!=NULL && lenInstrumento>0
       && arrayMusico!=NULL && lenMusico>0)
    {
        musico_sortMusicosByInstrumentoEficiente(arrayMusico,lenMusico,1);
        for(i=1;i<lenMusico;i++)
        {
            if(arrayMusico[i-1].idInstrumento==arrayMusico[i].idInstrumento)
            {
                contadorOcurrencia++;
                if(contadorOcurrencia>max)
                {
                    max=contadorOcurrencia;
                    IdInstrumentoMayorOcurrencia=arrayMusico[i].idInstrumento;
                }
            }
            else
            {
                contadorOcurrencia--;
            }
        }
        posIdInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,
                                                         IdInstrumentoMayorOcurrencia);
        if(posIdInstrumento!=-1)
        {
            switch(arrayInstrumento[posIdInstrumento].tipo)
            {
                case 1:
                   strncpy(stringTipo,"Cuerda",sizeof(stringTipo));
                   break;
                case 2:
                    strncpy(stringTipo,"Viento-Madera",sizeof(stringTipo));
                    break;
                case 3:
                    strncpy(stringTipo,"Viento-Metal",sizeof(stringTipo));
                    break;
                case 4:
                    strncpy(stringTipo,"Percusion",sizeof(stringTipo));
                    break;
            }
            printf("\nInstrumento mas Usado Por Musicos: %s\n"
                   "Id Instrumento: %d\nTipo: %s\n",
                   arrayInstrumento[posIdInstrumento].name,
                   arrayInstrumento[posIdInstrumento].idInstrumento,
                   stringTipo);
            retorno=0;
        }
    }
    return retorno;
}

int informe_promedioDeEdadMusicos(Musico* arrayMusico,int lenMusico)
{
    int i;
    int edadesSumadas;
    float promedioResult;
    int musicoOverPromedio;
    int cantidadMusicos=0;
    int sum=0;
    int ret=-1;
    if(arrayMusico!=NULL && lenMusico>0)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                sum+=arrayMusico[i].edad;
                cantidadMusicos++;
            }
        }
        edadesSumadas=sum;
        promedioResult=edadesSumadas/cantidadMusicos;
        informe_musicoOverPromedio(arrayMusico,lenMusico,promedioResult,&musicoOverPromedio);
        ret=0;
        if(ret==0)
        {
            printf("\nLa edad promedio es: %.2f\n"
                    "Cantidad demusicos que superan la edad promedio: %d\n",
                    promedioResult,musicoOverPromedio);
        }
    }
    return ret;
}

int informe_promedioMusicosPorOrquesta(Musico* arrayMusico,Orquesta* arrayOrquesta,
                                       int lenMusico,int lenOrquesta)
{
    int cantidadMusicos;
    int cantidadOrquesta;
    int promedio;

    informe_cantidadMusicos(arrayMusico,lenMusico,&cantidadMusicos);
    informe_cantidadOrquestas(arrayOrquesta,lenOrquesta,&cantidadOrquesta);
    promedio=cantidadMusicos/cantidadOrquesta;
    printf("\nEL promedio de Musicos por orquesta es: %d\n",promedio);

    return 0;
}

int informe_musicoOverPromedio(Musico* arrayMusico,int lenMusico,float promedioResult,int* valor)
{
    int i;
    int contadorMusico=0;
    int ret=-1;
    if(arrayMusico!=NULL && lenMusico>0 && valor!=NULL)
    {
        for(i=0;i<lenMusico;i++)
        {
            if(arrayMusico[i].isEmpty==0)
            {
                if(arrayMusico[i].edad>promedioResult)
                {
                    contadorMusico++;
                }
            }

        }
        *valor=contadorMusico;
        ret=0;
    }
    return ret;
}

int informe_printMusicoByInstrumentoDeterminado(Musico* arrayMusico,Instrumento* arrayInstrumento,
                                                int lenMusico,int lenInstrumento,char* msgE)
{
    int i;
    int auxIdInstrumento;
    int posInstrumento;
    int posMusico;
    char stringTipo[30];
    int flag=1;

    auxIdInstrumento=instrumento_getID(arrayInstrumento,lenInstrumento,msgE,3);
    posInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,auxIdInstrumento);
    if((auxIdInstrumento>=0)&&(posInstrumento!=-1))
    {
        for(i=0;i<lenMusico;i++)
        {
            if((arrayMusico[i].isEmpty==0)&&(arrayMusico[i].idInstrumento==auxIdInstrumento))
            {
                posInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento);
                posMusico=musico_findMusicoById(arrayMusico,lenMusico,arrayMusico[i].idMusico);
                if((posInstrumento>=0)&&(posMusico>=0))
                {
                    switch(arrayInstrumento[posInstrumento].tipo)
                    {
                       case 1:
                           strncpy(stringTipo,"Cuerda",sizeof(stringTipo));
                           break;
                        case 2:
                            strncpy(stringTipo,"Viento-Madera",sizeof(stringTipo));
                            break;
                        case 3:
                            strncpy(stringTipo,"Viento-Metal",sizeof(stringTipo));
                            break;
                        case 4:
                            strncpy(stringTipo,"Percusion",sizeof(stringTipo));
                            break;
                    }
                    printf("\nMusico: %s %s\nInstrumento: %s\nTipo: %s\nCodigo Musico: %d\n"
                           "Codigo Instrumento: %d\n-------\n",
                           arrayMusico[posMusico].name,
                           arrayMusico[posMusico].surname,
                           arrayInstrumento[posInstrumento].name,
                           stringTipo,
                           arrayMusico[posMusico].idMusico,
                           arrayInstrumento[posInstrumento].idInstrumento);
                           flag=0;
                }
            }
        }
        if(flag)
        {
            printf("\n----El listado se encuentra vacio----\n");
        }
    }
    return 0;
}

int informe_printMusicosByOrquestaDeterminada(Musico* arrayMusico,Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,
                                              int lenMusico,int lenOrquesta,int lenInstrumento,char* msgE)
{
    int i;
    int auxIdOrquesta;
    int posOrquesta;
    int posMusico;
    int posInstrumento;
    char stringTipo[30];
    int flag=1;

    auxIdOrquesta=orquesta_getID(arrayOrquesta,lenOrquesta,msgE,3);
    posOrquesta=orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,auxIdOrquesta);
    if((auxIdOrquesta>=0)&&(posOrquesta!=-1))
    {
        for(i=0;i<lenMusico;i++)
        {
            if((arrayMusico[i].isEmpty==0)&&(arrayMusico[i].idOrquesta==auxIdOrquesta))
            {
                posOrquesta=orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,arrayMusico[i].idOrquesta);
                posMusico=musico_findMusicoById(arrayMusico,lenMusico,arrayMusico[i].idMusico);
                posInstrumento=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento);
                if((posOrquesta>=0)&&(posMusico>=0)&&(posMusico>=0))
                {
                    switch(arrayInstrumento[posInstrumento].tipo)
                    {
                       case 1:
                           strncpy(stringTipo,"Cuerda",sizeof(stringTipo));
                           break;
                        case 2:
                            strncpy(stringTipo,"Viento-Madera",sizeof(stringTipo));
                            break;
                        case 3:
                            strncpy(stringTipo,"Viento-Metal",sizeof(stringTipo));
                            break;
                        case 4:
                            strncpy(stringTipo,"Percusion",sizeof(stringTipo));
                            break;
                    }
                    printf("\nMusico: %s %s\nEdad: %d\nTipo: %s\nNombre Instrumento: %s"
                           "\n-------\n",
                           arrayMusico[posMusico].name,
                           arrayMusico[posMusico].surname,
                           arrayMusico[posMusico].edad,
                           stringTipo,
                           arrayInstrumento[posInstrumento].name);
                           flag=0;
                }
            }
        }
        if(flag)
        {
            printf("\n----El listado se encuentra vacio----\n");
        }
    }
    return 0;
}

int informe_tipoOrquestaMasFrecuente(Orquesta* arrayOrquesta,int lenOrquesta)
{
    int i;
    int max=0;
    int contadorOcurrencia=0;
    int tipoOrquestaMayorOcurrencia;
    char stringTipo[30];
    int retorno=-1;
    if(arrayOrquesta!=NULL && lenOrquesta>=0)
    {
        orquesta_sortOrquestaByTipo(arrayOrquesta,lenOrquesta,1);
        for(i=1;i<lenOrquesta;i++)
        {
            if(arrayOrquesta[i-1].tipo==arrayOrquesta[i].tipo)
            {
                contadorOcurrencia++;
                if(contadorOcurrencia>max)
                {
                    max=contadorOcurrencia;
                    tipoOrquestaMayorOcurrencia=arrayOrquesta[i].tipo;
                }
            }
            else
            {
                contadorOcurrencia=0;
            }
        }
        if(tipoOrquestaMayorOcurrencia>=1 || tipoOrquestaMayorOcurrencia<=3)
        {
            switch(tipoOrquestaMayorOcurrencia)
            {
                case 1:
                    strncpy(stringTipo,"Sinfonica",sizeof(stringTipo));
                    break;
                case 2:
                    strncpy(stringTipo,"Filarmonica",sizeof(stringTipo));
                    break;
                case 3:
                    strncpy(stringTipo,"Camara",sizeof(stringTipo));
                    break;
            }
            printf("\nTipo de Orquesta mas frecuente: %s\n-------\n",stringTipo);
            retorno=0;
        }
    }
    return retorno;
}

int informe_orquestaConMasMusicos (Orquesta* arrayOrquesta,Musico* arrayMusico,
                                   int lenOrquesta,int lenMusico)
{
    int i;
    int max=0;
    int contadorMusico=0;
    int IdorquestaConMasMusicos;
    int posIdOrquesta;
    int cantidadMusicos=0;
    char stringTipo[30];
    int retorno=-1;

    if(arrayOrquesta!=NULL&&arrayMusico!=NULL
       &&lenOrquesta>0&&lenMusico>0)
    {
        musico_sortMusicosByIdOrquestaEficiente(arrayMusico,lenMusico,1);
        for(i=1;i<lenMusico;i++)
        {
            if(arrayMusico[i-1].idOrquesta==arrayMusico[i].idOrquesta)
            {
                contadorMusico++;
                if(contadorMusico>max)
                {
                    max=contadorMusico;
                    IdorquestaConMasMusicos=arrayMusico[i].idOrquesta;
                }
            }
            else
            {
                contadorMusico--;
            }
        }
        posIdOrquesta=orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,IdorquestaConMasMusicos);
        if(posIdOrquesta!=-1)
        {
            switch(arrayOrquesta[posIdOrquesta].tipo)
            {
                case 1:
                    strncpy(stringTipo,"Sinfonica",sizeof(stringTipo));
                    break;
                case 2:
                    strncpy(stringTipo,"Filarmonica",sizeof(stringTipo));
                    break;
                case 3:
                    strncpy(stringTipo,"Camara",sizeof(stringTipo));
                    break;
            }
            printf("\nOrquesta con mas Musicos: %s\n"
                   "Lugar: %s\nTipo: %s\nCodigo Orquesta: %d\n"
                   "Cantidad de musicos: %d\n",
                   arrayOrquesta[posIdOrquesta].name,
                   arrayOrquesta[posIdOrquesta].lugar,
                   stringTipo,
                   arrayOrquesta[posIdOrquesta].idOrquesta,
                   cantidadMusicos);
            retorno=0;
        }
    }
    return retorno;
}

int informe_orquestaConMasde5Musicos (Orquesta* arrayOrquesta,Musico* arrayMusico,
                                   int lenOrquesta,int lenMusico)
{
    int i;
    int posIdOrquesta;
    char stringTipo[30];
    int orquestaAnterior=0;
    int contadorOrquesta=0;

    musico_sortMusicosByIdOrquestaEficiente(arrayMusico,lenMusico,1);
    for(i=0;i<lenMusico;i++)
    {
        if(arrayMusico[i].isEmpty==0)
        {
            posIdOrquesta=orquesta_findOrquestaById(arrayOrquesta,lenOrquesta,arrayMusico[i].idOrquesta);
            if(orquestaAnterior==posIdOrquesta)
            {
                contadorOrquesta++;
            }
            else
            {
                contadorOrquesta--;
            }
            orquestaAnterior=posIdOrquesta;
            if(contadorOrquesta>=5)
            {
                switch(arrayOrquesta[posIdOrquesta].tipo)
                {
                    case 1:
                        strncpy(stringTipo,"Sinfonica",sizeof(stringTipo));
                        break;
                    case 2:
                        strncpy(stringTipo,"Filarmonica",sizeof(stringTipo));
                        break;
                    case 3:
                        strncpy(stringTipo,"Camara",sizeof(stringTipo));
                        break;
                }
                printf("\nID orquesta: %d\nNombre: %s\n"
                       "Tipo: %s\nLugar: %s",
                       arrayOrquesta[posIdOrquesta].idOrquesta,
                       arrayOrquesta[posIdOrquesta].name,
                       stringTipo,
                       arrayOrquesta[posIdOrquesta].lugar);
            }
        }
    }
    return 0;
}


int informe_printMusicoSoloCuerda(Musico* arrayMusico,Instrumento* arrayInstrumento,
                                  int lenMusico,int lenInstrumento)
{
    int i;
    int posInstrumentoCuerda;
    int auxTipo;
    char stringTipo[30];
    int flag=1;
    Instrumento_sortInstrumentoByTipo(arrayInstrumento,lenInstrumento,1);
    for(i=0;i<lenMusico;i++)
    {

        if(arrayMusico[i].isEmpty==0)
        {
            posInstrumentoCuerda=instrumento_findInstrumentoById(arrayInstrumento,lenInstrumento,arrayMusico[i].idInstrumento);
            auxTipo=instrumento_findInstrumentoByTipo(arrayInstrumento,lenInstrumento,arrayInstrumento[posInstrumentoCuerda].tipo);
            if(posInstrumentoCuerda!=-1&&auxTipo==1)
            {
                switch(auxTipo)
                {
                   case 1:
                       strncpy(stringTipo,"Cuerda",sizeof(stringTipo));
                       break;
                    case 2:
                        strncpy(stringTipo,"Viento-Madera",sizeof(stringTipo));
                        break;
                    case 3:
                        strncpy(stringTipo,"Viento-Metal",sizeof(stringTipo));
                        break;
                    case 4:
                        strncpy(stringTipo,"Percusion",sizeof(stringTipo));
                        break;
                }
                printf("\nNombre: %s\nApellido: %s\n"
                "Edad: %d\nNombre Instrumento: %s\n"
                "Tipo Instrumento: %s\n-------\n",
                       arrayMusico[i].name,
                       arrayMusico[i].surname,
                       arrayMusico[i].edad,
                       arrayInstrumento[posInstrumentoCuerda].name,
                       stringTipo);
                flag=0;
            }

        }

    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}
