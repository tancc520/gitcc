#include <stdio.h>
long long fact(int num){
    long long result=1;
    for (int i=1;i<=num;i++){
        result*=i;
    }
    return result;
}
long long Fact(int n,int k){
    if (k<0||k>n){
        return 0;
    }
    if (k==0||k==n){
        return 1;
    }
    long long fenzi=fact(n);
    long long fenmu=fact(k)*fact(n-k);
    long long result=fenzi/fenmu;
    return result;
}
int main(){
    int k,n;
    scanf("%d%d",&n,&k);
    long long sum=Fact(n,k);
    printf("%lld\n",sum);
    return 0;
}