#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int element;

//创建队列(动态内存分配)
typedef struct{
    element data[maxsize];
    int front;
    int rear;
}Queue;
Queue *initqueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0;
    q->rear=0;
    return q;
}

//初始化(对已有队列)
void stqueue(Queue *q){
    q->front=0;
    q->rear=0;
}

//判空
int jdempty(Queue *q){
    if (q->front==q->rear)
    {
        printf("队列为空\n");
        return 1;
    }
    else return 0;
}

//循坏队列入队
int equeue(Queue *q,element e){
    if ((q->rear+1)%maxsize==q->front)  //满队列的条件:队尾的下一个位置追上队头
    {
        printf("队列已满\n");     //对列还会剩下一个空位，但从代码角度已经满了
        return 0;
    }
    q->data[q->rear]=e;           //元素放到队尾,不是从队尾取出
    q->rear=(q->rear+1)%maxsize;  //确定队尾的条件,意思是q->rear++
    return 1;
}

//遍历(注意不要修改front,循环队列要用取模前进)
void queuement(Queue *q){
    if (q->front==q->rear)
    {
        printf("此为空队列\n");
        return;              //判空后必须return
    }
    for (int i=q->front; i!=q->rear; i=(i+1)%maxsize)  //用i走,别动front
    {
        printf("%d ",q->data[i]);
    }
    printf("\n");
}

//循环队列出队
int dequeue(Queue *q,element *e){
    if (q->front==q->rear)
    {
        printf("队列为空\n");
        return 0;
    }
    *e=q->data[q->front];            //e是指针,要用*e写回
    q->front=(q->front+1)%maxsize;
    printf("出队元素为%d\n",*e);
    return 1;
}

int main(){
    Queue *queue=initqueue();

    jdempty(queue);

    for (int i = 0; i < 10; i++)
    {
        equeue(queue,i+1);
    }
    queuement(queue);

    element e;
    dequeue(queue,&e);
    queuement(queue);

    return 0;
}