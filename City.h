#ifndef __City_H__
#define __City_H__

#include<stdio.h>
#include<stdlib.h>

typedef struct City{
    char* name;
    int x;
    int y;
    int g;
    int h;
    Neighbors neighbors;
}City;

typedef struct Neighbors{
    char** neighbors;
    int** distance;
}Neighbors;

/**
 * create a new city
 * @param name name of the city
 * @param x longtitude of the city
 * @param y latitude of the city
 * @return a new city if memory allocation OK
 * @return 0 otherwise
*/
City* createCity(char* name, int x, int y);

/**
 * create a new list of neighbor cities
 * @return a new empty list if memory allocation OK
 * @return 0 otherwise
*/
Neighbors createNeighbors();

/**
 * add a new city into the neighbor list
 * @param p the city owns neighbor list that need to be added
 * @param name name of the neighbor city
 * @param distance distance from p to neighbor city
*/
void addNeighbor(City* p, char* name, int distance);

/**
 * calculate the valua of h
 * @param p the city needs to be calculate
 * @param des the destination city
 * @return value of h
*/
int h(City *p, City *des);
#endif //__City_H__