#ifndef __Node_H__
#define __Node_H__

#include <stdio.h>
#include <stdlib.h>
#include "City.h"

typedef struct Node{
    City* city;
    Node* next;
}Node;
typedef struct List{
    Node* head;
}List;

/**
 * create a new city Node
 * @param p the city is created node
 * @return a new city node if allocation OK
 * @return 0 otherwise
*/
Node* createNode(City* p);

/**
 * create a empty city List
 * @return a new empty list if allocation OK
 * @return 0 otherwise
*/
List* createList();

/**
 * add a node into the list
 * @param l the list to store the node in
 * @param node added node
*/
void addNode(List* l, Node* node);

/**
 * remove a city node out of the list
 * @param l the list to remove node from
 * @param city the name of removed city node
*/
void removeNode(List* l, char* city);
#endif //__Node_H__