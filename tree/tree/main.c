//
//  main.c
//  tree
//
//  Created by Taro on 2017/3/14.
//  Copyright © 2017年 Taro. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#define STACK_INIT_SIZE   100
#define STACKINCREMENT    10


//递归
//链式结构
typedef struct BiTree{
    char data;
    struct BiTree *lchild, *rchild;
}BiTNode, *BiTree;

BiTree createBiTree();
void preOrderTraverse(BiTree T);
void inOrderTraverse(BiTree T);
void postOrderTraverse(BiTree T);


//非递归 栈
typedef struct {
    BiTree *base;
    BiTree *top;
    int stacksize;
}SqStack;

void initStack();
void destroyStack(SqStack *s);
void clearStack(SqStack *s);

int stackIsEmpty(SqStack s);
int stackLength(SqStack s);

BiTree* getTop(SqStack s, BiTree *t);
void push(SqStack *s, BiTree t);
void pop(SqStack *s, BiTree *t);

void preOrderNoRecursionTraverse(BiTree T);
void inOrderNoRecursionTraverse(BiTree T);
void postOrderNoRecusionTraverse(BiTree T);


int main(int argc, const char * argv[]) {
    BiTree T;
    printf("按先序序列输入结点序列，'#'代表空：");
    T = createBiTree(T);
    printf("递归先序遍历:\n");
    preOrderTraverse(T);
    printf("\n");
    preOrderNoRecursionTraverse(T);
    
    printf("\n");
    printf("递归中序遍历:\n");
    inOrderTraverse(T);
    printf("\n");
    inOrderNoRecursionTraverse(T);
    
    
    printf("\n");
    printf("递归后序遍历:\n");
    postOrderTraverse(T);
    
    printf("\n");
    postOrderNoRecusionTraverse(T);
    printf("\n");
    
    return 0;
}

BiTree createBiTree(){
    char inputData;
    BiTree T;
    scanf("%c",&inputData);
    if (inputData == '#') T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if (!T) {
            printf("分配内存出错");
            return NULL;
        }
        T->data = inputData;
        T->lchild = createBiTree();
        T->rchild = createBiTree();
    }
    return T;
}

void preOrderTraverse(BiTree T){
    if (T) {
        printf("%c",T->data);
        preOrderTraverse(T->lchild);
        preOrderTraverse(T->rchild);
    }
}

void inOrderTraverse(BiTree T){
    if (T) {
        inOrderTraverse(T->lchild);
        printf("%c",T->data);
        inOrderTraverse(T->rchild);
    }
}

void postOrderTraverse(BiTree T){
    if (T) {
        postOrderTraverse(T->lchild);
        postOrderTraverse(T->rchild);
        printf("%c",T->data);
    }
}


//-------非递归--------

void preOrderNoRecursionTraverse(BiTree T){
    SqStack s;
    BiTree p;
    initStack(&s);
    push(&s, T);
    while (!stackIsEmpty(s)) {
        pop(&s, &p);
        printf("%c",p->data);
        if (p->rchild)push(&s, p->rchild);//先遍历做子树，所以右子树先入栈
        if (p->lchild)push(&s, p->lchild);
    }
    destroyStack(&s);
}


void inOrderNoRecursionTraverse(BiTree T){
    SqStack s;
    BiTree p ;
    initStack(&s);
    push(&s, T);
    while (!stackIsEmpty(s)) {
        while (getTop(s, &p)&&p) {//向左走到尽头
            push(&s, p->lchild);
        }
        pop(&s, &p);//空指针退栈
        if (!stackIsEmpty(s)) {//访问结点 向右一步
            pop(&s, &p);
            printf("%c",p->data);
            push(&s, p->rchild);
        }
    }
    destroyStack(&s);
}

void postOrderNoRecusionTraverse(BiTree T){
    SqStack s;
    BiTree p,q;
    initStack(&s);
    push(&s, T);
    while (!stackIsEmpty(s)) {
        while(getTop(s,&p)&&p&&(p->lchild||p->rchild)){
            push(&s,p->rchild);      // 右子树入栈
            push(&s,p->lchild);      // 左子树入栈
        }//注意栈中存在空指针，表示某个结点的右子树为空
        if(!stackIsEmpty(s)){//访问结点
            pop(&s,&p);
            if (p){
                printf("%c",p->data);
            }else{      // 存在右子树为空的结点，继续向上返回
                pop(&s,&p);
              printf("%c",p->data);
            }
            while (getTop(s,&q)&&q&&p==q->rchild){//若当前为右子树，则继续出栈
                pop(&s,&p);
                printf("%c",p->data);
                getTop(s,&q);
            }
        }
    }
    destroyStack(&s);
}



// ------栈操作--------

void initStack(SqStack *s){
    s->base = (BiTree *)malloc(STACK_INIT_SIZE*sizeof(BiTree));
    if (!s->base) {
        printf("分配内存失败");
        exit(0);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    
}


void destroyStack(SqStack *s){
    if (s) {
        free(s->base);
    }else{
        printf("指针为空，释放失败\n");
    }
}

void clearStack(SqStack *s){
    if (s) {
        s->top = s->base;
    }else{
        printf("指针为空，释放失败\n");
    }
}

int stackIsEmpty(SqStack s){
    
    return s.top==s.base?1:0;
  
}

int stackLength(SqStack s){
    return s.stacksize;
}

BiTree* getTop(SqStack s, BiTree *t){
    if (stackIsEmpty(s)) {
//        printf("空栈");
        return NULL;
    }else{
        *t = *(s.top-1);
        return t;
    }
}

void push(SqStack *s, BiTree t){
    //栈满 追加存储空间
    if (s->top-s->base == s->stacksize) {
        s->base = (BiTree *)realloc(s->base, (s->stacksize+STACKINCREMENT)*sizeof(BiTree));
        if (!s->base) {
            printf("重新申请空间失败\n");
            exit(0);
        }
        s->top = s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    
    *s->top++ = t;
}

void pop(SqStack *s, BiTree *t){
    if (s->top == s->base) {
        printf("已为空栈");
    }else{
        *t = *(--s->top);
    }
}




