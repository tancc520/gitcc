#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct treenode{
    element data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;

typedef treenode *bitree;

void preoder(bitree t){
    if(t==NULL){
        return;
    }
    printf("%d ",t->data);
    preoder(t->lchild);
    preoder(t->rchild);
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
    else if (t->data>value){
        return search_bst(t->lchild,value,t,pos);
    }
    else return search_bst(t->rchild,value,t,pos);
}

//插入
int insert_bst(bitree *t,int value){
    bitree pos;
    bitree curr;
    int satus=search_bst(*t,value,NULL,&pos);
    if(satus==0){
        curr=(bitree)malloc(sizeof(treenode));
        curr->data=value;
        curr->lchild=NULL;
        curr->rchild=NULL;
        //如果树为空，新节点为根节点
        if(pos==NULL){
            *t=curr;
        }

        else if(value<pos->data){
            pos->lchild=curr;
        }
        else pos->rchild=curr;
        return 1;
    }
    else return 0;
}

//删除
//1.叶节点直接删  2.有一个孩子的节点，子承父业 3.有两个孩子的节点..
int delete(bitree *d){
    bitree temp,record;
    //只有左子树或无子节点
    if ((*d)->rchild==NULL){
        temp=*d;
        *d=(*d)->lchild;
        free(temp);
    }
    //只有右子树
    else if ((*d)->lchild==NULL){
        temp=*d;
        *d=(*d)->rchild;
        free(temp);
    }
    //左右子树都有(用左子树最大值替换)(用右子树最小值替换：将rchild和lchild互换即可)
    else {
        temp=*d;
        record=(*d)->lchild;
        while(record->rchild!=NULL){
            temp=record;
            record=record->rchild;
        }
        //替换当前值
        (*d)->data=record->data;
        //删除替代节点
        if (temp!=*d){
            temp->rchild=record->lchild;
        }
        else {
            //while循环一次没进的情况
            temp->lchild=record->lchild;
        }
        free(record); 
    }
    return 1;
}

//递归查找并删除目标节点
int delete_bst(bitree* t,int value){
    if(t==NULL||*t==NULL){
        printf("not found\n");
        return 0;
    }
    if ((*t)->data==value){
        return delete(t);
    }
    else if ((*t)->data>value){
        return delete_bst(&(*t)->lchild,value);
    }
    else return delete_bst(&(*t)->rchild,value);
}


int main(){
    bitree t=NULL;
    int arr[]={70,55,49,30,39,53,80,75,98,95};
    for (int i=0;i<10;i++){
        insert_bst(&t,arr[i]);
    }
    printf("插入：\n");
    preoder(t);
    insert_bst(&t,99);
    printf("\n");
    preoder(t);

    printf("\n");

    printf("删除：\n");
    preoder(t);
    delete_bst(&t,49);
    printf("\n");
    preoder(t);

    return 0;
}