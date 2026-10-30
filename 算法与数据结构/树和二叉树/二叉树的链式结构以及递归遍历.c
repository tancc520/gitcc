//除去满二叉树和完全二叉树外，其他场景比较浪费空间
#include <stdio.h>
#include <stdlib.h>

typedef char element;
char tree[]="ABDH#K###E##CFI###G#J##";

//创建树节点
typedef struct treenode{
    element data;
    struct treenode *lchild;   // typedef 别名还没生效，这里必须写 struct treenode
    struct treenode *rchild;
}treenode;

typedef treenode* bitree;

#define STACKSIZE 100
typedef struct{
    bitree *data;  //栈里必须放"结点指针"，不能放 data 字符，出栈之后要靠这个指针跳到右孩子，只存字符就找不到右子树了
    int top;
}Stack;

Stack *initstack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(bitree*)malloc(sizeof(bitree)*STACKSIZE);   // 原来没给 data 分配空间，是野指针
    s->top=-1;
    return s;
}

//创建树（输入数据）
int idx=0;
void createtrre(bitree *t){    //指针类型的指针
    element ch;
    ch=tree[idx++];
    if (ch=='#'||ch=='\0'){    // '#' 是空结点标记；'\0' 防字符串读完
        *t=NULL;
    }
    else{
        *t=(treenode*)malloc(sizeof(treenode));
        (*t)->data=ch;
        createtrre(&(*t)->lchild);
        createtrre(&(*t)->rchild);
    }
}

int isempty(Stack *s){
    return s->top<0;      // 空返回 1，非空返回 0（原来写反了，函数名和含义对不上）
}

int push(Stack *s,bitree t){
    if (s->top+1>=STACKSIZE){
        return 0;         // 栈满
    }
    s->top++;             // 先加再写，否则第一次会写到 data[-1]
    s->data[s->top]=t;    // 存整个结点指针，不是 data 字符
    return 1;
}

int pop(Stack *s,bitree *t){
    if (isempty(s)){
        return 0;
    }
    *t=s->data[s->top];   // 取出结点指针
    s->top--;
    return 1;
}

//前序遍历（非递归版）,相比递归，自己写出入栈
void preordernon(Stack *s,bitree t){
    while (t!=NULL || !isempty(s)){
        while (t!=NULL){
            printf("%c ",t->data);
            push(s,t);
            t=t->lchild;              // 一路向左
        }
        if (!pop(s,&t)){              // 栈空就收工，否则 t->rchild 会空指针崩溃
            break;
        }
        t=t->rchild;                  // 转向右子树
    }
}

//前序遍历..遍历（S型） 与化学中的杂化相似
void preorder(bitree T){
    if (T==NULL){
        return;
    }
    printf("%c ",T->data);
    preorder(T->lchild);   //先输出左孩子 
    preorder(T->rchild);
}

//中序遍历
void inorder(bitree t){
    if (t==NULL){
        return;
    }
    inorder(t->lchild);
    printf("%c ",t->data);
    inorder(t->rchild); 
}

//后序遍历
void postorder(bitree t){
    if (t==NULL){
        return;
    }
    postorder(t->lchild);
    postorder(t->rchild);
    printf("%c ",t->data);
}

int main(){
    bitree t;
    createtrre(&t);

    preorder(t);
    printf("\n");

    inorder(t);
    printf("\n");

    postorder(t);
    printf("\n");

    Stack *s=initstack();
    bitree p=t;               // 用副本：非递归遍历会移动指针，直接用 t 会丢根
    preordernon(s,p);         // 前序（非递归），结果应和递归前序一致
    printf("\n");

    free(s->data); 
    free(s);
    free(t);

    return 0;
}