#include <stdio.h>
#include <math.h>
int judge(int n,int x){
    for(int i=0;i<n;i++){
        if(x<=2) return 0;
        if(x==2) return 1;
        if(x%2==0) return 0;
        for (int i=3;i<=sqrt(x);i+=2){
            if(x%i==0) return 0;
        }
    }
    return 1;
}
int main(){
    int n,x;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        if (judge(n,x)){
            printf("Yes\n");
        }else {printf("No\n");}
    }
    return 0;

}