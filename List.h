#ifndef __Node_H__
#define __Node_H__

#include <stdio.h>
#include <stdlib.h>
#include "City.h"

typedef struct Node{
    City* city;
    struct Node* next;
}Node;

typedef struct List{
    Node* head;
    int size;
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

/**
 * check if the list is empty or not
 * @param l the checked list
 * @return 1 if list is empty
 * @return 0 otherwise
*/
int isEmpty(List* l);

/**
 * check if city exist in List
 * @param l the list store cities
 * @param city the checked city
 * @return node if city is in list
 * @return 0 otherwise
*/
Node* isInList(List* l, char* city);

/**
 * find the node has smallest f value
 * @param l the list store nodes
 * @return the smallest node in list
 * @return 0 list is empty
*/
Node* findSmallestNode(List* l);

/**
 * display all node of List and their g value
 * @param l the displayed list
*/
void displayList(List* l);
#endif //__Node_H__