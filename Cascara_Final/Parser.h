#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "LinkedList.h"

int parser_loadVentaFromText(FILE* pFile, LinkedList* lista);
int parser_loadPersonaFromText(FILE* pFile, LinkedList* lista);
int parser_loadEmpleadoFromText(FILE* pFile, LinkedList* lista);
int parser_loadProductoFromText(FILE* pFile, LinkedList* lista);


#endif // PARSER_H_INCLUDED
