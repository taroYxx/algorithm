//
//  main.c
//  jonsph
//
//  Created by Taro on 2017/3/13.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;


//创建环
Node* createCycle(int num){
    if (num <= 0) return NULL;
    
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 1;
    Node *p = head;
    for (int i = 2; i<=num; i++) {
        Node *q = (Node*)malloc(sizeof(Node));
        q->data = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    return head;
}


Node *showNode(Node *cycle){
    if (cycle == NULL) {
        return NULL;
    }
    
    
    
    Node *phead = cycle;
    Node *p = phead;
    printf("%p--data:%d\n",p,p->data);
   
    while (p->next && p->next != phead) {
        p = p->next;
        printf("%p--data:%d\n",p,p->data);
    }
    return cycle;
}

Node *jonsph(Node *cycle,int totalNum, int inputNum){
    if(!cycle || inputNum<=0) return NULL;
    
    Node *pCur = cycle;
    
    int time = 1;
    while (time < totalNum) {
        
        Node *pLast = pCur;
        for (int i = 0; i<inputNum; i++) {
            pLast = pCur;
            pCur = pCur->next;   //定位删除结点
            
            
        }
        
        pLast->next = pCur->next;
        printf("deleteP: %p--%d\n",pCur,pCur->data);
        free(pCur);
        pCur = pLast->next;
        time++;
    }
    
    return pCur;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    Node *cycle = createCycle(10);
    showNode(cycle);
    Node *result = jonsph(cycle, 10, 20);
    printf("finally data\n\n");
    showNode(result);
    return 0;
}
