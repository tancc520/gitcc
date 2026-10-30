//队列：只允许在一端入队，一边出队

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 

typedef int element;

//创建队列
typedef struct {
    element data[MAXSIZE];
    int front;
    int rear;
}Queue;

//初始化(对已存在的队列)
void initQueue(Queue *q){
    q->front=0;
    q->rear=0;
}

//判空
int jdempty(Queue *q){
    if (q->front==q->rear) //front和rear不一定全为零
    {
        printf("队列为空\n");
        return 1;
    }
    return 0;
}

//动态内存分配(创建新队列)
Queue *createQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0;   //data是结构体内的定长数组,不能再malloc赋值
    q->rear=0;
    return q;
}

//遍历
void queuement(Queue *q){
    if (q->front==q->rear)
    {
        printf("队列为空\n");
        return;              //判空后要return
    }
    for (int i=q->front; i<q->rear; i++)   //rear是下一个入队位置,取不到,用<
    {
        printf("%d ",q->data[i]);
    }
}

//出队
int pop(Queue *q,element *e){
    if (jdempty(q))          //要调用函数,写上括号和参数
    {
        printf("队列为空\n");
        return 0;            //int函数要返回值
    }
    *e=q->data[q->front];    //e是指针,要用*e写回
    printf("出队元素为%d\n",*e);
    q->front++;
    return 1;
}

//队尾满了,调整队列（对尾已到头，但不代表队列已满） 操作：将队头重置到队列顶端
int requeue(Queue *q){
    if (q->front>0){
        int step=q->front;
        for ( int i = q->front; i <q->rear ; i++)
        {
            q->data[i-step]=q->data[i];
        }
        q->front=0;
        q->rear=q->rear-step;
        return 1;
    }
    else {
        printf("队列已满\n");
        return 0;
    }
}

//入队
int equeue(Queue *q,element e){
    if (q->rear>=MAXSIZE){
        if (!requeue(q))     //要调用函数,写上括号和参数
        {
            printf("队列已满\n");
            return 0;
        }
    }
    q->data[q->rear]=e;      //入队放在队尾,不是队头
    q->rear++;
    return 1;
}

int main(){
    Queue *queue=createQueue();
    
    int n;
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++)
    {
        equeue(queue,i+1);
    }
    queuement(queue);

    element e;
    pop(queue,&e);
    queuement(queue);

    return 0;
}