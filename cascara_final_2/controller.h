#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

#include "LinkedList.h"
int controller_llamadoLoadFromText(char* path , LinkedList* arrayList);
int controller_ventaSaveAsText(char* path , LinkedList* arrayList);
int controller_List(LinkedList* list);

#endif // CONTROLLER_H_INCLUDED
