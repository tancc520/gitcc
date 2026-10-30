#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    for(int x=0;x<n;x++){
        for (int y=0;y<n;y++){
            if (x==y||x+y==n-1){
                printf("+");
            }
            else{printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}