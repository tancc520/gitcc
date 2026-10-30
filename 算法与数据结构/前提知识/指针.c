#include <stdio.h>
    /*int a[]={120,100,201,2102};
    int *p=a;  
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)  “sizeof的应用”
    {
        printf("%d\n",a[i]);
    }
    */


    /*
    int a=100;
    int *p=&a;
    printf("%d\n",*p);
    *p=1000;                // *p的使用(非声明的变量)
    printf("%d",*p);
    return 0;
    */
    


    /*                     交换函数（指针形式）
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("a=%d,b=%d\n",*a,*b);
}
int main(){
    int m=10;
    int n=5;
    swap(&m,&n);
    printf("m=%d,n=%d",m,n);
    return 0;
}
    */
    

    /*
int main(){
    int a[]={10,101,103,130};
    int *p;
    p=a;
    printf("%p\n",&a);
    printf("%p\n",p);
    printf("%d",*p);
    return 0;
}
    */

int main(){
    int a[]={10,101,103,130};
    int *p;
    p=a;
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
        printf("%d  ",*(p+i));
    }
    return 0;
}
