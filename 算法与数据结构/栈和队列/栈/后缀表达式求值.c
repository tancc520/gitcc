//遇到数字压栈，遇到运算符将入栈的元素进行此运算符计算，将运算结果压栈，以此循环操作，直到运算符变为\0时停止
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int element;
char expr[]="82/2+56*-";

typedef struct{
    int top;
    element *data;
}Stack;

//枚举运算符
typedef enum
{
    left_pare,right_pare,
    add,sub,mul,divide,mod,
    eos,num
}contentType;

//初始化
Stack *initstack(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(element*)malloc(sizeof(element)*maxsize);
    s->top=-1;
    return s;
}

//出栈
int pop(Stack *s,element *e){
    if (s->top==-1 ){
        printf("此为空栈\n");
    }
    
    *e=s->data[s->top];
    s->top--;
    return 1;
}

//入栈
int push(Stack *s,element e){
    s->top++;
    s->data[s->top]=e;
    return 1;
}

//字符转运算符1
int gettoken(char *symbol,int *index){
    *symbol=expr[*index];
    *index+=1;
    switch (*symbol)
    {
    case '(' :
        return left_pare;
    case ')':
        return right_pare;
    case '+':
        return add;
    case '-':
        return sub;
    case '*':
        return mul;
    case '/':
        return divide;
    case '%':
        return mod;
    case '\0':
        return eos;
    default:
        return num;
    }
}

//计算后缀表达式
int eval(Stack *s){
    char symbol;
    int op1,op2;
    int index=0;
    contentType token;
    token=gettoken(&symbol,&index);
    element result;
    while (token!=eos)
    {
        if (token==num)
        {
            push(s,symbol-'0');
        }
        else{
            pop(s,&op2);
            pop(s,&op1);
            
            //字符转换为运算符2
            switch(token){
                case add:
                    push(s, op1+op2);
                    break;
                case sub:
                    push(s,op1-op2);
                    break;
                case mul:
                    push(s,op1*op2);
                    break;
                case divide:
                    push(s,op1/op2);
                    break;
                case mod:
                    push(s,op1%op2);
                    break;
                default:
                    break;
            }
        }
        token=gettoken(&symbol,&index);
    }
    pop(s,&result);
    printf("%d",result);
    return 1;
}

int main(){
    Stack *satck=initstack();
    eval(satck);
    return 0;  
}