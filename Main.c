#include <stdio.h>
#include <stdlib.h>
#include "AStar.h"
#include "City.h"
#include "List.h"
#include "string.h"

int main(){
    FILE* file = fopen("FRANCE.MAP","r");
    List* l = createList();
    if(!file){
        return 2;
    }else{
        //get data from FRANCE.MAP and store in List of City
        City* p = NULL;
        while(!feof(file)){
            char *name = (char*)malloc(sizeof(char));
            if(!name) return 2;
            int x, y;
            int i = fscanf(file,"%s %d %d", name,&x,&y);
            if(i == 3){
                p = createCity(name,x,y);
                Node* node =createNode(p);
                addNode(l,node);
            }else{
                addNeighbor(p,name,x);
            }
            
        }
        fclose(file);
    }
    //get depparture and destination from user
    char* from;
    char* to;
    printf("Enter the name of departure city:");
    scanf("%s",from);
    printf("Enter the name of destination city:");
    scanf("%s",to);
    //Exercute A Star function
    aStar(l, from, to);
}