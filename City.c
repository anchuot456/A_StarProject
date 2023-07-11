#include <math.h>
#include "City.h"

int h(City *p,City *des){
    float cost = (abs(des->x - p->x)+abs(des->y - p->y))/4;
    return (int)cost;
}