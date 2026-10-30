/*链栈:用单链表实现
  栈顶放在链表头部(头插头删,都是O(1))
  链栈不需要判满,除非内存耗尽*/
#include <stdio.h>
#include <stdlib.h>

typedef int element;

//栈的节点
typedef struct node
{
    element data;
    struct node *next;
}Node;

//链栈
typedef struct 
{
    Node *top;
    element count;
}linkstack;

//初始化一个空栈
linkstack *Stack(){
    linkstack *s=(linkstack*)malloc(sizeof(linkstack));
    s->count=0;
    s->top=NULL;
    return s;
}

//判空
void jdempty(linkstack *s){
    if (s->count==0)
    {
        printf("此链式栈为空\n");
    }
    else printf("此链栈未空\n");
}

//进栈（头插）
void push(linkstack *s,element e){
    Node *q=(Node*)malloc(sizeof(Node));
    q->data=e;
    q->next=s->top;   //新节点指向原栈顶(空栈时s->top为NULL,正好当链尾)
    s->top=q;         //栈顶更新为新节点(注意是s->top=q,不是s->top->next=q)
    s->count++;
}

//出栈(头删):删除的是栈顶节点,返回1成功/0失败
int pop(linkstack *s,element *e){
    if (s->top==NULL)   //空栈:top本身为NULL,不是top->next
    {
        printf("此为空栈\n");
        return 0;       //判空后必须return,否则后面会解引用NULL
    }
    Node *q=s->top;     //q是被删除的栈顶节点(类型是Node*,不是linkstack*)
    *e=q->data;         //先取出数据
    s->top=q->next;     //栈顶指向下一个节点
    free(q);            //释放原栈顶
    s->count--;
    return 1;
}

//遍历(从栈顶到栈底,注意不要修改top)
void stackment(linkstack *s){
    if (s->top==NULL)
    {
        printf("此为空栈\n");
        return;              //判空后必须return
    }
    Node *p=s->top;          //用临时指针做游标,不能动s->top
    while (p!=NULL)          //判的是当前节点本身,不是p->next
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int main(){
    linkstack *stack=Stack();

    jdempty(stack);

    for (int i = 0; i < 10; i++)
    {
        /* code */
        push(stack,i+1);
    }
    stackment(stack);

    element po;                 //普通变量即可,pop内部通过地址写回结果
    if (pop(stack,&po))         //&po 是 element*,与形参类型匹配
    {
        printf("出栈的元素是:%d\n",po);
    }
    stackment(stack);

    free(stack);
    
    return 0;
}