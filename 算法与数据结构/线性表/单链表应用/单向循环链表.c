/*最后一个节点指向头节点
  判断循环链表：通过快慢指针是否相遇来判断
*/
#include <stdio.h>
#include <stdlib.h>

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

//尾插法(返回新插入的尾节点)
Node *tailinsert(Node *L,element e){
    Node *p=(Node*)malloc(sizeof(Node));
    p->data=e;
    p->next=NULL;
    Node *tail=L;
    while (tail->next!=NULL)   //找到最后一个节点(注意是next非空)
    {
        /* code */
        tail=tail->next;
    }
    tail->next=p;
    return p;
}

//判断链表是否有环(快慢指针,相遇即有环)
int iscycle(Node *L){
    Node *fast=L;
    Node *slow=L;
    while (fast!=NULL&&fast->next!=NULL)
    {
        /* code */
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)   //必须放在循环内判断,有环时循环永远不会自动退出
        {
            return 1;
        }
    }
    return 0;   //fast走到头说明无环
}

//寻找环的起点
//原理:设头到起点距离a,相遇点到起点距离b,环长c
//     相遇时 2(a+b)=a+b+nc → a=(n-1)c+(c-b)
//     即"从头走a步"="从相遇点绕回起点",两者同速前进必在起点相遇
Node *cyclestart(Node *L){
    Node *fast=L;
    Node *slow=L;
    while (fast!=NULL&&fast->next!=NULL)
    {
        /* code */
        fast=fast->next->next;
        slow=slow->next;
        if (fast==slow)   //第一阶段:相遇
        {
            Node *p=L;    //第二阶段:一个指针回到头节点
            while (p!=slow)   //两个同速前进,再次相遇处即环的起点
            {
                /* code */
                p=p->next;
                slow=slow->next;
            }
            return p;
        }
    }
    return NULL;   //无环
}

int main(){
    Node *list=inlist();

    //创建循环一个链表
    Node *tail;                          //保存当前尾节点
    for (int i = 0; i < 3; i++)
    {
        /* code */
        tail=tailinsert(list,i+1);       //注意不要写Node *tail,会遮蔽外层变量
    }
    Node *three=tail;                    //第3个节点,作为环的起点
    for (int i = 3; i <8; i++)
    {
        /* code */
        tail=tailinsert(list,i+1);
    }
    tail->next=three;                    //最后一个节点(8)指回第3个节点,成环

    int i=iscycle(list);
    if (i)
    {
        /* code */
        printf("是单循环链表\n");
        Node *start=cyclestart(list);
        printf("环的起点是:%d\n",start->data);
    }
    else printf("不是单循环链表");
    
    Node *head=cyclestart(list);

    free(list);
    return 0;
}