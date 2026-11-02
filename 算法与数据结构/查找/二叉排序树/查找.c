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

void midorder(bitree *t){
    if(*t==NULL) return;
    midorder(&(*t)->lchild);
    printf("%d ",(*t)->data);
    midorder(&(*t)->rchild);
}

//判定二叉搜索树
//平衡二叉树的中序遍历必须严格递增
int isbst(bitree t,bitree *prev){
    if(t==NULL) return 1;
    if(!isbst(t->lchild,prev)) return 0;  //左子树不满足直接返回
    if(*prev!=NULL && t->data<=(*prev)->data) return 0;
    *prev=t;  //更新前驱
    return isbst(t->rchild,prev);
}
void judge(bitree t,bitree *prev){
    if(isbst(t,prev)) {
        printf("是二叉平衡树\n");
    }
    else printf("不是二叉平衡树\n");
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

    bitree prev=NULL;
    judge(t,&prev);

    bitree searcht;
    search_bst(t,53,NULL,&searcht);
    
    //前序遍历
    preorder(&t);
    printf("\n");

    //中序遍历
    printf("二叉搜索树中序遍历遵循严格递增\n");
    midorder(&t);
    printf("\n");

    printf("%d",searcht->data);
    return 0;
}