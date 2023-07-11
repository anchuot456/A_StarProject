#include <stdio.h>
#include <stdlib.h>
#include "AStar.h"
#include "City.h"
#include "List.h"
#include "string.h"

int main(){
    FILE* file = fopen("FRANCE.MAP","r");
    if(!file){
        return 2;
    }else{
        List* l = createList();
        while(!foef()){
            char* name, s;
            int x, y, distance;
            fscanf(file,"%s %d %d", &name,&x,&y);
            City* p = createCity(name,x,y);
            do{
                fscanf(file,"%s %d",&s,&distance);
                addNeighbor(p,s,distance);
            }while(s!="\n");
            addNode(l,p);
        }
        fclose(file);
    }
}