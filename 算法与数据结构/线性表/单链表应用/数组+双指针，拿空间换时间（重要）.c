/*用单链表保存n个整数，结点的结构为[data][link]，且|data|≤n(n为正整数)。
现要求设计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的节点，
仅保留第一次出现的节点而删除其余绝对值相等的结点。
例如，若给定单链表
head如下:
head->21->-15->-15->-7->15
则删除节点后的head为
head->-15->-21
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int element;

//创建链表
typedef struct node{
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

//尾插法
void inserttail(Node *L,element e){
    Node *p=L;
    while (p->next!=NULL)
    {
        /* code */
        p=p->next;
    }
    Node *insert=(Node*)malloc(sizeof(Node));
    insert->data=e;
    insert->next=NULL;
    p->next=insert;
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

//删除绝对值相同的节点
void removenode(Node *L,int n){
    Node *p=L;
    int index;  //做为数组下标使用
    int *q=(int*)malloc((n+1)*sizeof(int));  //辅助数组,也可写作calloc:(int*)calloc(n+1,sizeof(int))
    memset(q,0,(n+1)*sizeof(int));            //malloc不清零,需手动初始化为0
    while (p->next!=NULL)
    {
        index=abs(p->next->data);  //用绝对值做数组下标
        if (*(q+index)==0){
            *(q+index)=1;  //第一次出现,保留
            p=p->next;
        }
        else{                  //如果此下标数在数组中为1,删除该节点
            Node *temp=p->next;
            p->next=temp->next;
            free(temp);
        }
    }
    free(q);
}

int main(){
    Node *list=inlist();
    
    inserttail(list,21);
    inserttail(list,-15);
    inserttail(list,-15);
    inserttail(list,7);
    inserttail(list,15);
    
    listment(list);

    removenode(list,21);
    
    listment(list);

    return 0;
}