#include "AStar.h"
#include "City.h"
#include "List.h"
#include "string.h"

int aStar(List* l, char* from, char* to){
    if(l->head == NULL){
        return 2;
    }
    //check if from and to is in list
    Node* dep = isInList(l,from);
    Node* des = isInList(l,to);
    if(!dep||!des){
        return 1;
    }

    List* open = createList();
    List* close = createList();

    dep->city->g = 0;
    dep->city->h = h(dep->city,des->city);
    dep->city->f = dep->city->g + dep->city->h;
    addNode(open,dep);
    while(!isEmpty(open)){
        Node* p = findSmallestNode(open);
        removeNode(open,p->city->name);
        if(p==des){
            displayList(close);
            return 0;
        }
        
        addNode(close,p);
        for(int i = 0; i < p->city->neighbors->size; i++){
            //create node of neighbor for open
            City* neighbor = isInList(l,p->city->neighbors->neighbors[i])->city;
            Node* new_q = createNode(neighbor);
            Node* old_q = isInList(open,new_q->city->name);
            if(old_q){//if q in open
                if(old_q->city->g > p->city->g + p->city->neighbors->distance[i]){//if g(q) > g(p) + Cost(p, q)
                    old_q->city->g = p->city->g + p->city->neighbors->distance[i];//g(q) = g(p) + Cost(p, q)
                    old_q->city->h = h(old_q->city,des->city);//calculate h(q)
                    old_q->city->f = old_q->city->g + old_q->city->h;//f(q)=g(q)+h(q)
                    //prev(q) = p
                }
            }else{
                new_q->city->g = p->city->g + p->city->neighbors->distance[i];//g(q) = g(p) + Cost(p, q)
                new_q->city->h = h(new_q->city,des->city);//calculate h(q)
                new_q->city->f = new_q->city->g + new_q->city->h;//f(q)=g(q)+h(q)
                //prev(q) = p
                addNode(open,new_q);
            }
            old_q = isInList(close,new_q->city->name);
            if(old_q){//if q in close
                if(old_q->city->g > p->city->g + p->city->neighbors->distance[i]){//if g(q) > g(p) + Cost(p, q)
                    removeNode(close,old_q->city->name);//remove q out of close
                    addNode(open,old_q);//add to open
                }
            }
        }
    }
    printf("There is no way to go from %s to %s", from, to);
    return 3;
}