#include <stdio.h>
int lxgwts(int days,float wd[]){
    int count=0;
    for(int i=0;i<days;i++){
        if (wd[i]>=35){
            count+=1;
        }
    }
    return count;
}
char*color_(int count){
    if (count>=7){
        return"red";
    }
    else if(count>=5){
        return"orange";
    }
    else if(count>=3){
        return"yellow";
    }
    else {return"no";}
}
int main(){
    int N;
    scanf("%d",&N);
    float wendu[30];
    for (int i=0;i<N;i++){
        scanf("%f",&wendu[i]);
    }
    int days=lxgwts(N,wendu);
    char*color=color_(days);
    printf("%d\n%s\n",days,color);
    return 0;
}