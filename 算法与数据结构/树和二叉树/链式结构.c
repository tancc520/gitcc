//除去满二叉树和完全二叉树外，其他场景比较浪费空间
#include <stdio.h>
#include <stdlib.h>

typedef char element;

//创建树节点
typedef struct treenode{
    element data;
    treenode *lchild;
    treenode *rchild;
}treenode;

typedef treenode* bitree;

//前序遍历
void preorder(bitree T){
    if (T==NULL){
        return;
    }
    printf("%c",T->data);
    preorder(T->lchild);   //先输出左孩子 
    preorder(T->rchild);
}

