#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef char element;

typedef struct threadnode{
    element data;
    struct threadnode *lchild; 
    struct threadnode *rchild; 
    int ltag;
    int rtag;
}threadnode;

typedef threadnode *threadtree;

char str[]="ABDH##I##EJ###CF##G##";
int idx=0;

threadtree prev;

//造树
void createtree(threadtree *T){
    element ch;
    ch=str[idx++];
    if (ch=='#'){
        *T=NULL;
    }
    else{
        //  threadtree相当于threadnode*
        *T=(threadtree)malloc(sizeof(threadnode));
        (*T)->data=ch;
        createtree(&(*T)->lchild);
        if ((*T)->lchild!=NULL){
            (*T)->ltag=0;
        }
        createtree(&(*T)->rchild);
        if ((*T)->rchild!=NULL){
            (*T)->rtag=0;
        }
    }
}

//具体线索化
//当前节点左空，T的lchild指向前驱prev
//前驱右空，前驱指向后继（T）
//然后将prev更新
void threading(threadtree T){
    if(T!=NULL){
        threading(T->lchild);
        if(T->lchild==NULL){
            T->ltag=1;              //ltag=1，标明这是线索，不是左孩子
            T->lchild=prev;      //如果T没有左孩子，那么T的lchild指向prev（前驱），也就是中序遍历中T的上一个字母
        }
        if(prev->rchild==NULL){
            prev->rtag=1;
            prev->rchild=T;      // 如果上一个节点prev没有右孩子，那么在中序遍历中，T就是prev的后继
        }                        // 整体上连成一个循环链表
        prev=T;                  // 当前T的lchild和T的前驱Rchild处理结束，将prev向下移
        threading(T->rchild);       //继续右子树
    }
}

//开始线索化
void inorderthreading(threadtree *head,threadtree T){
    //初始化头节点
    *head=(threadtree)malloc(sizeof(threadnode));
    (*head)->ltag=0;
    (*head)->rtag=1;
    (*head)->rchild=(*head); //后继先指向自己

    //判断空树
    if (T==NULL){
        (*head)->lchild=*head;
    }

    else{
        (*head)->lchild=T;
        prev=(*head); //表示上一个访问的节点
        threading(T);
        //调用完后，prev指向中序最后一个节点
        //最后一个节点线索化
        prev->rchild=*head;    //最后一个节点的后继指向头节点，形成循环
        prev->rtag=1;

        //头节点右指针指向最后一个节点
        (*head)->rchild=prev;
    }
}


//线索化遍历
void inorder(threadtree T){
    threadtree curr;
    curr=T->lchild;         //T实际上是头节点head，主函数main中调用函数时传入的是head
    while (curr!=T){
        while(curr->ltag==0){
            curr=curr->lchild;
        }
        printf("%c ",curr->data);

        while(curr->rtag==1 && curr->rchild!=T)  //curr!=T表明当前节点不是最后一个节点，最后一个节点的rtag==1,并且指向头节点（curr->lchild=head）
        {      
            curr=curr->rchild;
            printf("%c ",curr->data);
        }
        curr=curr->rchild; //进入右子树，必须放在循环内
        //直到curr==head，遍历结束
    }
}

int main(){
    threadtree head;
    threadtree T;
    createtree(&T);
    inorderthreading(&head,T);
    inorder(head);
    return 0;
}