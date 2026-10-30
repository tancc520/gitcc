/*已知一个带有表头节点的单链表，节点结构为
data
link
假设该链表只给出了头指针list。在不改变链表的前提下，
请设计一个尽可能高效的算法，查找链表中倒数第k个位置上的结点(k为正整数)。、
若查找成功，算法输出该节点的data域的值，并返回1;否则，只返回0。*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;

//创建链表
typedef struct node{
    element data;
    struct node *next;
}Node;

//初始化链表
Node *malloclist(){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=0;
    p->next=NULL;
    return p;
} 

//头插法
void inserthead(Node *L,element e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=L->next;
    L->next=p;
}

//释放链表
void freelist(Node *L){
    Node *p=L->next;
    Node *q;
    while (p!=NULL)
    {
        /* code */
        q=p->next;
        free(p);
        p=q;
    }
    L->next=NULL;
}

//使用双指针找到倒数第k个点
int findnode(Node *L,element k){
    Node *fast=L->next;
    Node *slow=L->next;
    for (int i=0;i<k;i++){
        fast=fast->next;    //快指针先走k步
    }
    while (fast!=NULL)
    {
        slow=slow->next;    //两个指针一起走
        fast=fast->next;
    }                        //当fast走到链表末尾null时，slow和fast刚好相差k个节点
    if (slow!=NULL){
        printf("倒数第%d个节点值为%d\n",k,slow->data);
        return 1;
    }
    return 0;
}

//遍历链表
void listment(Node *L){
    Node *p=L->next;
    while (p!=NULL)
    {
        /* code */
        printf("%d\t",p->data);
        p=p->next;
    }
    
}
int main(){
    Node *list=malloclist();
    for (int  i = 0; i < 10; i++)
    {
        /* code */
        inserthead(list,i+1);
    }

    listment(list);

    findnode(list,6);
    return 0;
}
