#include <stdio.h> 
int main (){
    double a,b;
    printf(":"); 
    scanf("%lf%lf",&a,&b);

    double sum=a+b;
    printf("%.2lf+%.2lf=%.2lf\n", a,b,sum);

    double diffence=a-b;
    printf("%.2lf-%.2lf=%.2lf\n", a, b, diffence);

    double product=a*b;	
    printf("%.2lf*%.2lf=%.2lf\n",a,b, product);

    if (b!=0){
        double quotient=a/b; 
        printf("%.2lf/%.2lf=%.2lf\n",a,b,quotient);
    }
    else {
        printf("\n");
    }
    return 0;
}

    
