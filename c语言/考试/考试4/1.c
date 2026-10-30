#include <stdio.h>
int main(){
    int a,b,c,d,x=0,y=0,z=0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int count=0;
    for (int x=0;x<=d/a;x+=1){
        for(int y=0;y<=d/b;y+=1){
            for (int z=0;z<=d/c;z+=1){
                if(a*x+b*y+c*z==d){
                    count+=1;
                }
            }
        }
    }
    printf("%d",count);
    return 0;
    
}