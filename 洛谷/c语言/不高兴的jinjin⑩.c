#include <stdio.h>
int main(){
    int times[7];
    int un=0;
    int f_un=0;
    for(int i=1;i<=7;i++){
        scanf("%d",&times[i]);
        if (times[i]>8){
            un=1;
            f_un=i;
            break;
        }
    }
    if (un){
        printf("%d",f_un);
    }
    else {
        printf("0");
    }
    return 0;

}