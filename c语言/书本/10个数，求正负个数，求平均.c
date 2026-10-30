#include <stdio.h>
void main () {
    int i,a[10],n1=0,n2=0,total=0;
    for(i=0;i<10;i++) scanf("%d",&a[i]);
    for(i=0;i<10;i++) 
    {
        if (a[i]>0) n1++;
        else if(a[i]<0) n2++;
        total+=a[i];
        }
        printf("%d-%d-%f\n",n1,n2,total/10.0); 
}