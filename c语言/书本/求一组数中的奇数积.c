#include <stdio.h>
int oddpro(int n,int odd[]){
    int sum=1;
    for(int i=0;i<n;i++){
        if (odd[i]%2!=0){
            sum*=odd[i];
        }
    }
    return sum;
}
int main(){
    int n;
    while (1){
    scanf("%d",&n);
    int odd[n];
    for (int i=0;i<n;i++){
        scanf("%d",&odd[i]);
    }
    int sum=oddpro(n,odd);
    printf("%d",sum);
    }
    return 0;
}