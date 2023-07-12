#ifndef __AStar_H__
#define __AStar_H__

#include<stdio.h>
#include "List.h"

/**
 * find the shortest way to connect 2 city
 * @param from name of departure city
 * @param to name of destination city
 * @return 1 if 1 of 2 city does not exist in city list
 * @return 0 if OK
*/
int aStar(List* l, char* from, char* to);

#endif //__AStar_H__