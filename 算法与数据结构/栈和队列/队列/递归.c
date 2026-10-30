#include <stdio.h>
#include <stdlib.h>

typedef int element;

int fun(int n){
    int sum=0;
    for (int i=0;i<=n;i++){
        sum+=i;
        return sum;
    }
}

//递归连加
int func(int n){
    if(n==1){
        return 1;
    }
    else {
        return fun(n-1)+n;
    }
}

//斐波那契数列（非递归）
int Fonc(int n){
    int last1=1;
    int last2=1;
    int result=0;
    for (int i = 3; i <=n; i++)
    {
        /* code */
        result=last1+last2;
        last2=last1;
        last1=result;
    }
    return result;
}

//斐波那契数列（递归）
int Foncs(int n){
    if (n==1 || n==2)
    {
        /* code */
        return 1;
    }
    else return Foncs(n-2)+Foncs(n-1);
}