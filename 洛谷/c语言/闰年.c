#include <stdio.h>
int main(){
    int y,m;
    scanf("%d,%d",&y,&m);
    int c=0;
    int days=0;
    if ((y%4==0&&y%100!=0)||y%400==0){
        c=1;
    }
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        days=31;
        break;
        case 2:days= c? 29:28;
        break;
        case 4:
        case 6:
        case 9:
        case 11:
        days=30;
        break;
    }
    printf("%d",days);
    return 0;
}