#include <stdio.h>
int main(){
    int n=1;
    while (1){
        if (n%3==2&&n%5==3&&n%7==2){
            printf("至少为%d人",n);
            break;
        }
        n++;
    }
    return 0;
    
}