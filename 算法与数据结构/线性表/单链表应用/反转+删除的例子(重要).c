/*
设线性表L=(a,a2,a3,...,an-2,an-1,an)采用带头节点的单链表保存，
typedef struct node
int data;
struct node* next;
}Node;
设计尽可能高效的算法，
重新排列各个节点，得到线性表L’=(a1,an,a2,an-1,a3,an-2,...)。*/

#include <stdio.h>
#include <stdlib.h> 

typedef int element;

//创建链表
typedef struct node
{
    element data;
    struct node *next;
}Node;

//初始化链表
Node *inlist(){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=0;
    p->next=NULL;
    return p;
}

//遍历
void listment(Node *L){
    Node *p=L->next;
    while (p!=NULL)
    {
        /* code */
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

//尾插法
void tailinsert(Node *L,element e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    //找到最后一个节点，把 p 接到它后面
    Node *t=L;
    while (t->next!=NULL)
    {
        t=t->next;
    }
    t->next=p;
}

//寻找中间节点+反转+依次插入
void reorderlist(Node *L){
    Node *fast=L->next->next;
    Node *slow=L->next;
    while (fast!=NULL&&fast->next!=NULL)
    {
        /* code */
        fast=fast->next->next;
        slow=slow->next;
    }
    Node *first=NULL;
    Node *second=slow->next;
    slow->next=NULL; //从中间拆开链表
    Node *third=NULL;
    while (second!=NULL)
    {
        third=second->next;
        second->next=first; //改变链表指向
        first=second;
        second=third;
    }
    Node *p1=L->next; 
    Node *q1=first;
    Node *p2,*q2;
   while (p1!=NULL&&q1!=NULL)
   {
    p2=p1->next;   
    q2=q1->next;
    p1->next=q1;
    q1->next=p2;
    p1=p2;
    q1=q2;
   }
}

int main(){
    Node *list=inlist();
    for (int i = 0; i < 6; i++)
    {
        /* code */
        tailinsert(list,i+1);
    }
    listment(list);

    reorderlist(list);
    listment(list);

    return 0;
}