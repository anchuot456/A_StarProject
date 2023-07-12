#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "string.h"

Node* createNode(City* p){
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node) return 0;
    node->city = p;
    node->next = NULL;
    return node;
}

List* createList(){
    List* l =(List*)malloc(sizeof(List));
    if(!l) return 0;
    l->head = NULL;
    l->size = 0;
    return l;
}

void addNode(List* l, Node* node){
    if(l->head == NULL){
        l->size++;
        l->head = node;
        return;
    }
    Node* p =l->head;
    while(p->next!= NULL){
        p = p->next;
    }
    p->next=node;
    l->size++;
}

void removeNode(List* l, char* city){
    if(!strcmp(l->head->city->name,city)){
        Node* temp = l->head;
        l->head = l->head->next;
        l->size--;
        return;
    }
    Node* p = l->head;
    while(p->next!=NULL){
        if(!strcmp(p->next->city->name,city)){
            Node* temp = p->next;
            p->next = p->next->next;
            l->size--;
        }
        p = p->next;
    }
}

int isEmpty(List* l){
    return l->head == NULL;
}

Node* isInList(List* l, char* city){
    Node* p = l->head;
    while(p != NULL){
        if(!strcmp(p->city->name,city)){
            return p;
        }
        p = p->next;
    }
    return 0;
}

Node* findSmallestNode(List* l){
    Node* p = l->head;
    Node* res = l->head;
    while(p != NULL){
        if(p->city->f < res->city->f){
            res = p;
        }
        p = p->next;
    }
    return res;
}

void displayList(List* l){
    Node* p = l->head;
    while(p != NULL){
        printf("%s: %d\n", p->city->name, p->city->g);
        p = p->next;
    }
}
