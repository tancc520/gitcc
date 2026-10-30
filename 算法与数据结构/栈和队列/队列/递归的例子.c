//一个小球从高度为h的空中释放，每次弹起高度为原来高度的0.9倍，当小球停止弹起时(h<1e-6),求小球在空中走过的路程

#include <stdio.h>

/*double distance(double h){
    double next=h;
    double result=h;
    while (next>1e-6){
        next=next*0.9;
        result=result+2*next;
    }
    return result;
}

int main(){
    double h;
    scanf("%lf",&h);
    printf("%f",distance(h));
    return 0;
}
*/

double distance(double h){
    double up=h*0.9;
    if (h<1e-6)
    {
        return h;
    }
    return h+up+distance(up);
}

int main(){
    double h;
    scanf("%lf",&h);
    printf("%lf",distance(h));
    return 0;
}