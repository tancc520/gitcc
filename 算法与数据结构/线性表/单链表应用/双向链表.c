/*一个指向直接后继，一个指向直接前驱*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//创建链表
typedef struct node
{
    element data;
    struct node *prev,*next;
}Node;

//初始化
Node *inlist(){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=0;
    p->prev=NULL;
    p->next=NULL;
    return p;
}
//释放链表
void freelist(Node *L){
    Node *p=L;
    free(p);
}

//遍历(从头节点的下一个开始,头节点是哑节点不参与输出)
void listment(Node *L){
    Node *p=L->next;
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//头插法
void headinsert(Node *L,element e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    p->prev=L;
    if (L->next!=NULL)
    {
        L->next->prev=p;
    }
    L->next=p;
}

//尾插法
void tailinsert(Node *L,element e){
    Node *p=L;
    while (p->next!=NULL)
    {
        /* code */
        p=p->next;
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=NULL;
    q->prev=p;
    p->next=q;
}

//指定位置插入
void towardinsert(Node *L,element pos,element e){
    Node *p=L;
    int i=0;
    while (i<pos-1)
    {
        p=p->next;
        i++;
        if (p==NULL)
        {
            printf("插入位置错误\n");
            return;
        }
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->prev=p;
    q->next=p->next;
    if (q->next!=NULL)   //双向链表别忘记维护后继的prev
    {
        q->next->prev=q;
    }
    p->next=q;
}

//删除节点(返回1成功,0失败)
int delnode(Node *L,element pos){
    Node *p=L;
    int i=0;
    while (i<pos-1)
    {
        /* code */
        p=p->next;
        i++;
        if (p==NULL)
        {
            printf("输入的位置错误\n");
            return 0;
        }
    }
    if (p->next==NULL){
        printf("输入的位置错误\n");
        return 0;
    }
    Node *q=p->next;
    p->next=q->next;
    if (q->next!=NULL)   //双向链表别忘记维护后继的prev
    {
        q->next->prev=p;
    }
    free(q);
    return 1;
}

int main(){
    Node *list=inlist();
    for (int  i = 5; i < 10; i++)
    {
        headinsert(list,i+1);
    }
    listment(list);

    for (int i = 0; i < 5; i++)
    {
        tailinsert(list,i+1);
    }
    listment(list);

    towardinsert(list,6,91);
    listment(list);

    delnode(list,10);   //删除第10个节点
    listment(list);

    return 0;
}