#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char element;
char tree[]="ABDH#K###E##CFI###G#J##";
int idx=0;

typedef struct treenode{
    element treedata;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;

typedef treenode *bitree;

void createtree(bitree *t){
    element ch;
    ch=tree[idx++];
    if (ch=='#'){
        *t=NULL;
    }
    else{
        *t=(treenode*)malloc(sizeof(treenode));
        (*t)->treedata=ch;
        createtree(&(*t)->lchild);
        createtree(&(*t)->rchild);
    }
}

typedef struct{
    treenode *data[MAXSIZE];
    int front;
    int rear;
}Queue;

Queue *initqueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0;
    q->rear=0;
    return q;
}

int isempty(Queue *q){
    return q->front==q->rear;
}

int isfull(Queue *q){
    return (q->rear+1)%MAXSIZE==q->front;
}

int equeue(Queue *q,treenode *root){
    if(isfull(q)){
        return 0;
    }
    q->data[q->rear]=root;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}

int dequeue(Queue *q,treenode **e){
    if (isempty(q)) return 0;
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}

int queuesize(Queue *q){
    if (isempty(q)) return 0;
    return (q->rear-q->front+MAXSIZE)%MAXSIZE;
}

//层序遍历
int maxdepth(treenode *root){
    if (root==NULL){
        return 0;
    }
    int depth=0;
    Queue *q=initqueue();
    equeue(q,root);
    while(!isempty(q)){
        int count=queuesize(q);
        while(count>0){
            treenode *curr;
            dequeue(q,&curr);
            if (curr->lchild!=NULL){
                equeue(q,curr->lchild);
            }
            if(curr->rchild!=NULL){
                equeue(q,curr->rchild);
            }
            count--;
        }
        depth++;
    }
    return depth;
}

int main(){
    bitree t;
    createtree(&t);
    printf("这颗二叉树有%d层",maxdepth(t));
    return 0;
}