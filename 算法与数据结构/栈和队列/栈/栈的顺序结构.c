#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int element;

//创建栈
typedef struct{
    element data[maxsize];
    int top;
}Stack;

//初始化
void instack(Stack *s){
    s->top=-1;
}

//进栈
int push(Stack *s,element e){
    if (s->top>=maxsize-1)
    {
        printf("已经满了");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//出栈(用指针把出栈元素带出去)
int pop(Stack *s,element *e){
    if (s->top==-1)
    {
        printf("此为空栈\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}

//遍历(从栈顶到栈底,注意不要修改top)
void stackment(Stack *s){
    if (s->top==-1)
    {
        printf("此为空栈\n");
        return;
    }
    for (int i=s->top; i>=0; i--)
    {
        printf("%d ",s->data[i]);
    }
    printf("\n");
}

//动态内存分配
Stack *dynamic(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->top=-1;   //data是结构体内的定长数组,不能再malloc赋值
    return s;
}

int main(){
    Stack *stack=dynamic();
    //Stack *stack;
    //insatck(stack);
    for (int i = 0; i < 5; i++)
    {
        push(stack,i+1);
    }
    stackment(stack);

    element po;                       //接收出栈元素
    if (pop(stack,&po))               //注意传地址
    {
        printf("出栈的元素是:%d\n",po);
    }
    stackment(stack);
    
    return 0;
}