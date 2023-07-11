#ifndef __Node_H__
#define __Node_H__

#include <stdio.h>
#include <stdlib.h>
#include "City.h"

typedef struct Node{
    City* city;
    Node* next;
}Node;
#endif //__Node_H__