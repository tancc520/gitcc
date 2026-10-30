#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int element;
typedef struct node
{
    /* data */
    element data;
    struct node *next;
}Node;

//链表初始化(动态内存分配)
Node* inlsit(){
    Node *list=(Node*)malloc(sizeof(Node));
    list->data=0;
    list->next=NULL;
    return list;
}

//头插法(先插入的在后面)
void inserthead(Node *list,element e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=list->next;
    list->next=p;
}

//尾插法
Node *tailinsert(Node *L,element e){
    Node *p=L;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    Node *insert=(Node*)malloc(sizeof(Node));
    insert->data=e;
    p->next=insert;
    insert->next=NULL;
    return p;
}

//遍历
void listment(Node *L){
    Node *p=L->next;
    while (p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
}

//在指定位置插入数据
Node *insert(Node *L,int pos,element e){
    Node *p=L;
    int i=0;
    while (i<pos-1){
        p=p->next;
        i++;
    }
    if (p->next==NULL){
        return 0;
    }
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return p;
}

//删除节点(删除指定位置的节点)
int delete(Node *L,int pos){
    Node *p=L;
    int i=0;
    //找到要删除节点的前置节点
    while (i<pos-1){
        p=p->next;
        i++;
    }
    if (p->next==NULL){
        return 0;
    }
    Node *q=p->next; //q是(指向)要删除的节点
    p->next=q->next; //让要删除节点的前驱指向要删除节点的后继
    free(q); //释放多余内存
    return 1;
}

//获取链表长度
void getlength(Node *L){
    Node *p=L->next;
    int length=0;
    while (p!=NULL)
    {
        length++;
        p=p->next;
    }
    printf("链表长度为%d",length);
}

int main(){
    Node *list=inlsit();
    inserthead(list,27);
    inserthead(list,13);
    inserthead(list,91);
    inserthead(list,78);

    listment(list);

    tailinsert(list,33);
    listment(list);

    insert(list,3,10);
    listment(list);

    delete(list,4);
    listment(list);

    getlength(list);
    return 0;
} 

