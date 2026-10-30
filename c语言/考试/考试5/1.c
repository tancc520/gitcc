#include <stdio.h>
void ch(int s,int v){
    if (v<=40&&s!=20){
        printf("no");
    }
    else if (v<=80&&s!=50){
        printf("no");
    }
    else if (v>80&&s!=100){
        printf("no");
    }else {printf("yes");}
}
int main(){
    int s,v;
    scanf("%d,%d",&s,&v);
    ch(s,v);
    printf("\n");
    return 0;
}