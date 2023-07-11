#ifndef __City_H__
#define __City_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct City{
    char* name;
    int x;
    int y;
    Neighbors neighbors;
}City;

typedef struct Neighbors{
    City** neighbors;
}Neighbors;

int h(City *p, City *des);
#endif //__City_H__