#include <stdio.h>
void shift(int p[],int n){
    int last=p[n-1];
    for (int i=n-1;i>0;i--){
        p[i]=p[i-1];
    }
    p[0]=last;
}
int main(){
    int n;
    scanf("%d",&n);
    int p[100];
    for (int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    do {
        shift(p,n);
        for (int i=0;i<n;i++){
            printf("%d ",p[i]);
        }
        printf("\n");
    }while(p[n-1]!=n);
    return  0;
}