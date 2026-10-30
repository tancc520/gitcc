#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int element;

typedef struct{
    element data[MAXSIZE];
    int front;
    int count;
}Queue;

Queue *initqueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=0;
    q->count=0;
    return q;
}

int queueempty(Queue *q){
    return q->count==0;
}

int queuefull(Queue *q){
    return q->count==MAXSIZE;
}


int equeue(Queue *q,element e){
    if (queuefull(q)){
        printf("队列已满\n");
        return 0;
    }
    int rear=(q->front+q->count)%MAXSIZE;
    q->data[rear]=e;
    q->count++;
    return 1;
}

int dequeue(Queue *q,element *e){
    if(queueempty(q)){
        printf("队列为空\n");
        return 0;
    }
    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    q->count--;
    return 1;
}

int main(){
    Queue *q=initqueue();
    equeue(q,1);
    equeue(q,2);
    equeue(q,3);
    
    element e;
    while(!queueempty(q)){
        dequeue(q,&e);
        printf("%d ",e);
    }
    return 0;
}