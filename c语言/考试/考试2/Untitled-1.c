#include <stdio.h> 
int main (){
    int a,b;
    printf("??????????????:"); 
    scanf("%d %d",&a,&b);

    int sum=a+b;
    printf("%d+%d=%d\n", a,b,sum);

    int diffence=a-b;
    printf("%d-%d=%d\n", a, b, diffence);

    int product=a*b;	
    printf("%d*%d=%d\n",a,b, product);

    if (b!=0){
        int quotient=a/b; 
        printf("%d/%d=%d\n",a,b,quotient);
    }
    else {
        printf("?????????0,???????\n");
    }

    if (b!=0) {
        int yushu=a%b;
        printf("%d%%%d=%d\n",a,b,yushu);
    }
    else {
        printf("?????????0,???????\n");
    }
    return 0;
}

    
