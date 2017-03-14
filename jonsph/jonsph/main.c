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
    int firstData;
    printf("请输入M值(M值不能为0)：");
    scanf("%d",&firstData);
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = firstData;
    Node *p = head;
    for (int i = 2; i<=num; i++) {
        int pData;
        printf("请输入M值(M值不能为0)：");
        scanf("%d",&pData);
        Node *q = (Node*)malloc(sizeof(Node));
        q->data = pData;
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
        for (int i = 1; i<inputNum; i++) {
            pLast = pCur;
            pCur = pCur->next;   //定位删除结点
        }
        pLast->next = pCur->next;
//        printf("deleteP: %p--%d",pCur,pCur->data);
        printf("%d  ",pCur->data);
        free(pCur);
        pCur = pLast->next;
        
        time++;
    }
    printf("%d  \n",pCur->data);
    return pCur;
    
}


int main(int argc, const char * argv[]) {
    
    printf("请输入参与的人数\n");
    int peopleCount;
    scanf("%d",&peopleCount);
    
    printf("请输入初始M值(M值不能为0):");
    int initialM;
    scanf("%d",&initialM);
    
    Node *cycle = createCycle(peopleCount);
//    showNode(cycle);
    jonsph(cycle, peopleCount, initialM);
//    printf("finally data\n\n");
//    showNode(result);
    return 0;
}
