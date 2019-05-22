#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#include "orquesta.h"
#include "instrumento.h"
#include "musico.h"

int informe_menu(Orquesta* arrayOrquesta,Musico* arrayMusico,Instrumento* arrayInstrumento,
                 int lenOrquesta,int lenMusico,int lenInstrumento,int exitMenuNumber,int tries);

int informe_cantidadOrquestas(Orquesta* arrayOrquesta,int lenOrquesta,int* pCantidadOrquestas);
int informe_cantidadMusicos(Musico* arrayMusico,int lenMusico,int* pCantidadMusicos);
int informe_cantidadInstrumentos(Instrumento* arrayInstrumento,int lenInstrumento,int* pCantidadInst);

int informe_tipoInstrumentoMasUsado(Instrumento* arrayInstrumento,int lenInstrumento,int* pTipoInstMasUsado);
int informe_InstrumentoMasUsadoPorMusicos(Instrumento* arrayInstrumento,Musico* arrayMusico,int lenInstrumento,int lenMusico);
int informe_InstrumentosMenosUsadosPorMusicos(Instrumento* arrayInstrumento,Musico* arrayMusico,int lenInstrumento,int lenMusico);

int informe_printMusicoByInstrumentoDeterminado(Musico* arrayMusico,Instrumento* arrayInstrumento,
                                                int lenMusico,int lenInstrumento,char* msgE);

int informe_printMusicosByOrquestaDeterminada(Musico* arrayMusico,Orquesta* arrayOrquesta,Instrumento* arrayInstrumento,
                                              int lenMusico,int lenOrquesta,int lenInstrumento,char* msgE);

int informe_printMusicoSoloCuerda(Musico* arrayMusico,Instrumento* arrayInstrumento,
                                  int lenMusico,int lenInstrumento);

int informe_promedioMusicosPorOrquesta(Musico* arrayMusico,Orquesta* arrayOrquesta,int lenMusico,int lenOrquesta);
int informe_promedioDeEdadMusicos(Musico* arrayMusico,int lenMusico);
int informe_musicoOverPromedio(Musico* arrayMusico,int lenMusico,float promedioResult,int* valor);

int informe_tipoOrquestaMasFrecuente(Orquesta* arrayOrquesta,int lenOrquesta);
int informe_orquestaConMasMusicos(Orquesta* arrayOrquesta,Musico* arrayMusico,int lenOrquesta,int lenMusico);
int informe_orquestaConMasde5Musicos (Orquesta* arrayOrquesta,Musico* arrayMusico,int lenOrquesta,int lenMusico);

int informe_orquestaConMasde5Musicos (Orquesta* arrayOrquesta,Musico* arrayMusico,
                                   int lenOrquesta,int lenMusico);
int informe_edadMusicoMasDe30(Musico* arrayMusico,Instrumento* arrayInstrumento,Orquesta* arrayOrquesta,int lenInstrumento,int lenMusico,int lenOrquesta);

#endif // INFORMES_H_INCLUDED
