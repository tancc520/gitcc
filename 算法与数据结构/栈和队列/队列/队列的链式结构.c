#include <stdio.h>
#include <stdlib.h>

typedef int element;

//创建链式队列
typedef struct queuenode{
    element data;
    struct queuenode *next;
}queuenode;
typedef struct{
    queuenode *front;
    queuenode *rear;
}Queue;

//初始化
Queue *initqueque(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    queuenode *node=(queuenode*)malloc(sizeof(queuenode));
    node->data=0;
    node->next=NULL;
    q->front=node;
    q->rear=node;
    return q;
}

//判空
int isempty(Queue *q){
    if (q->front==q->rear)
    {
        printf("此链式队列为空\n");
        return 1;
    }
    return 0;
}

//入队
void equeue(Queue *q,element e){
    queuenode *p=(queuenode*)malloc(sizeof(queuenode));
    p->data=e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

//出队（出的是队尾元素）
int delqueue(Queue *q,element *e){
    if (q->front==q->rear)
    {
       printf("此链式队列为空\n");
       return 0;
    }
    queuenode *p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if (p==q->rear)
    {
        q->rear=q->front;
    }
    free(p);
    printf("出队元素为%d\n",*e);
    return 1;
}

//获取对头元素
void gethead(Queue *q){
    if (q->front==q->rear)
    {
        printf("此链式队列为空\n");
        return;
    }
    element e=q->front->next->data;
    printf("队头元素为%d\n",e);
}

//遍历
void queuement(Queue *q){
    if (q->front==q->rear)
    {
        printf("此链式队列为空\n");
        return;
    }
    for (queuenode *p=q->front->next; p!=NULL; p=p->next) //连续存储看下标，顺序存储看指针
    {
        printf("%d ",p->data);
    }
    printf("\n");
}

int main(){
    Queue *queue=initqueque();

    for (int i = 0; i < 10; i++)
    {
        /* code */
        equeue(queue,i+1);
    }
    queuement(queue);

    gethead(queue);

    element e;
    delqueue(queue,&e);

    return 0;
}