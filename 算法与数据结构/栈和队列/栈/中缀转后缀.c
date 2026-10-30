//操作数输出
//操作符判断后是否入栈
//如果是运算符，优先级大于栈顶元素，压入栈中，否则将栈顶元素输出，然后将当前运算符压入栈中
/*左括号在栈外时，属于最高优先级，在站内时，属于最低优先级
  右括号，栈顶不是左括号时，持续出栈并输出，直到栈顶为左括号 */
#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

typedef int element;

char expr[]="5*(9-10)/20";

//运算符类型(必须放在初始化之前,因为栈底哨兵要用到eos)
typedef enum{
    lift_pare,right_pare,
    add,sub,mul,Div,mod,
    eos,num
}contentType;

typedef struct{
    element *data;
    int top;
}Stack;

//初始化:栈底先压一个eos当哨兵,它的优先级是0
//所有运算符的优先级都比它大,于是"栈空"不用特判,循环会自然停在它上面
Stack *initsatck(){
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=(element*)malloc(sizeof(element)*maxsize);
    s->data[0]=eos;
    s->top=0;      //top指向栈顶元素,top==0表示只剩哨兵,即空栈
    return s;
}

int pop(Stack *s,element *e){
    if (s->top==0){
        printf("此栈为空\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}

int push(Stack *s,element e){
    if (s->top>=maxsize-1){      //data[0]被哨兵占了,所以只能放到maxsize-1
        printf("栈满\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

int gettoken(char *symbol,int *index){
    *symbol=expr[*index];
    *index=*index+1;
    switch (*symbol){
        case '(':
            return lift_pare;
        case ')':
            return right_pare;
        case '+':
            return add;
        case '-':
            return sub;
        case '*':
            return mul;
        case '/':
            return Div;
        case '%':
            return mod;
        case '\0':
            return eos;
        default:
            //操作数只认字母和数字,别把不认识的字符也当操作数
            if ((*symbol>='a'&&*symbol<='z')||(*symbol>='A'&&*symbol<='Z')||(*symbol>='0'&&*symbol<='9')){
                return num;
            }
            return eos;
    }    
}

int print_token(contentType token){
    switch (token){
        case add:
        printf("%c",'+');
            break;
        case sub:
        printf("%c",'-');
            break;
        case mul:
        printf("%c",'*');
            break;
        case Div:
        printf("%c",'/');
            break;
        case mod:
        printf("%c",'%');
            break;
        default:
            return 0;
    }
    return 1;
}

void postfix(Stack *s){
    int in_stack[]={0,19,12,12,13,13,13,0};
    int out_stack[]={20,19,12,12,13,13,13,0};
    int index=0;
    char symbol;
    element e;
    contentType token=gettoken(&symbol,&index);
    while (token!=eos){
        if (token==num){
            printf("%c",symbol);
        }
        else if(token==right_pare){
            while(s->top>0&&s->data[s->top]!=lift_pare){   //碰到左括号或哨兵就停
                pop(s,&e);
                print_token(e);
            }
            if (s->data[s->top]==lift_pare){
                pop(s,&e);      //左括号出栈,但不输出
            }
        }
        else{
            while (in_stack[s->data[s->top]]>=out_stack[token]){
                pop(s,&e);
                print_token(e);
            }
            push(s,token);
        }
        token=gettoken(&symbol,&index);
    }
    //扫完表达式后,栈里剩下的运算符要全部弹出输出
    while (s->top>0){
        pop(s,&e);
        print_token(e);
    }
    printf("\n");
}

int main(){
    Stack *s=initsatck();
    printf("%s\n",expr);
    postfix(s);
    free(s->data);
    free(s);
    return 0;
}