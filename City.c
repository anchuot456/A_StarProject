#include <stdlib.h>
#include <math.h>
#include "City.h"

City* createCity(char* name, int x, int y){
    City* res = (City*)malloc(sizeof(City));
    if(!res) return 0;
    res->x = x;
    res->y = y;
    res->g = 3000;
    res->h = 0;
    res->f = 3000;
    res->name = name;
    res->neighbors =createNeighbors();
    return res;
}

Neighbors* createNeighbors(){
    Neighbors* res =(Neighbors*)malloc(sizeof(Neighbors));
    if(!res) return 0;
    res->neighbors = (char**)malloc(10*sizeof(char*));
    res->distance = (int*)malloc(10*sizeof(int));
    res->size = 0;
    return res;
}

void addNeighbor(City* p, char* name, int distance){
    int size = p->neighbors->size;
    p->neighbors->neighbors[size] = name;
    p->neighbors->distance[size] = distance;
    p->neighbors->size++;
}

int h(City *p,City *des){
    float cost = (abs(des->x - p->x)+abs(des->y - p->y))/4;
    return (int)cost;
}