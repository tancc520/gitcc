#include <stdio.h>
#include <stdlib.h>   // malloc、free 都在这个头文件里声明
#include <string.h>


/*
int main(){
    int *p;
    p=(int*)malloc(sizeof(int));  //开辟内存
    *p=15;
    printf("%d",*p);
    free(p);   //释放内存
    return 0;
}
    */

/*
typedef struct{
    int x;
    int y;
}po;
int main(){
    po *p;
    p=(po*)malloc(sizeof(po));   //占8个字节，补位：例如：char+int字节也为8
    p->x=18;
    p->y=20;
    printf("%d,%d\n",p->x,p->y);
    free(p);
    return 0;
}
    */

