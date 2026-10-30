#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct treenode{
    element data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;

typedef treenode *bitree;

int arr[]={70,55,49,30,-1,39,-1,-1,53,-1,-1,-1,80,75,-1,-1,98,95,-1,-1,-1};
    int indx=0;

void createtree(bitree* t){
    element num;
    num=arr[indx++];
    
    if (num==-1){
        *t=NULL;
    }
    else{
        *t=(treenode*)malloc(sizeof(treenode));
        (*t)->data=num;
        createtree(&(*t)->lchild);
        createtree(&(*t)->rchild);
    }
}

void preorder(bitree *t){
    if (*t==NULL){
        return;
    }
    printf("%d ",(*t)->data);
    preorder(&(*t)->lchild);
    preorder(&(*t)->rchild);
}

int search_bst(bitree t,int value,bitree parent,bitree *pos){
    if (t==NULL){
        *pos=parent;
        return 0;
    }
    if (t->data==value){
        *pos=t;
        return 1;
    }
    if(t->data>value){
        return search_bst(t->lchild,value,t,pos);
    }
    else return search_bst(t->rchild,value,t,pos);
}

int main(){
    bitree t;
    createtree(&t);

    bitree searcht;
    search_bst(t,53,NULL,&searcht);

    preorder(&t);
    printf("\n");

    printf("%d",searcht->data);
    return 0;
}