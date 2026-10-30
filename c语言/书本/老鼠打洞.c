#include <stdio.h>
int main() {

    float day=0;
    double day1=1,day2=1,s1=0,s2=0,sum=0,total=10;
    while (sum<total){
        sum=s1+s2;
        day++;
        s1+=day1;
        s2+=day2;
        day1*=2;
        day2/=2;
        
    }
    if (sum>total){
        day--;
        s1-=day1/2;
        s2-=day2*2;
        day1/=2;
        day2*=2;
    }
    
    double remain=total-sum;
    float day3=remain/(day1+day2);
    double S1=s1+day1*day3;
    double S2=s2+day2*day3;
    

    printf("tianshu:%.2lf\n",(day+day3));
    printf("dalaoshu:%.1lf\n",S1);
    printf("xiaplaoshu:%.1lf\n",S2);

    return 0;

    

    

}