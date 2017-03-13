//
//  main.c
//  b
//
//  Created by Taro on 2017/3/11.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Joseph.h"

typedef struct Node{
    int data;
    struct Node *next;
}Node;




Node* getAllNode();//查看所有结点
Node* insert(); //插入
Node* delete(); //删除



int main(int argc, const char * argv[]) {
    
    
    
//    Node *firstNode = (Node *)malloc(sizeof(Node));
//    Node *node1 = (Node *)malloc(sizeof(Node));
//    insert(firstNode, node1);
//    Node *node2 = (Node *)malloc(sizeof(Node));
//    insert(firstNode, node2);
//    
//    printf("删除前\n");
//    getAllNode(firstNode);
//    
//    firstNode = delete(firstNode, node2);
//    
//    printf("删除后\n");
//    getAllNode(firstNode);
   
    return 0;
}

Node* getAllNode(Node *firstNode){
    if (firstNode == NULL) {
         return NULL;
    }
    
    Node* everyNode = firstNode;
    printf("%p---next:%p\n",everyNode,everyNode->next);
    while (firstNode->next != NULL) {
        everyNode = firstNode->next;
        printf("%p---next:%p\n",everyNode,everyNode->next);
        firstNode = everyNode;
    }
    return NULL;
}


Node* insert(Node *firstNode, Node* addNode){
    if(addNode == NULL || firstNode == NULL)return NULL;
    Node* current = firstNode;
    while (current->next != NULL) {
        current = current->next;
    }
    printf("add node %p---data%d\n",addNode,addNode->data);
    current->next = addNode;
    return firstNode;
}

Node* delete(Node *firstNode, Node* deletNode){
    if (deletNode == NULL || firstNode == NULL) {
        return NULL;
    }
    //删除点为第一个点
    if (firstNode == deletNode) {
        Node * p = firstNode;
        firstNode = firstNode->next;
        printf("deletNode--%p---data:%d\n",deletNode,deletNode->data);
        free(p);
        return firstNode;
    }
    //删除点为普通结点
    Node *currentNode = firstNode;
    Node *lastNode = firstNode;
    while (currentNode!= NULL) {
        if (currentNode == deletNode) {        //判断是否是删除的目标
            lastNode->next = currentNode->next;
            printf("deletNode--%p---data:%d\n",deletNode,deletNode->data);
            free(currentNode);
            return firstNode;
        }
        lastNode = currentNode;
        currentNode = currentNode->next;
    }
    return firstNode;
}





//#######   Joseph     ########









