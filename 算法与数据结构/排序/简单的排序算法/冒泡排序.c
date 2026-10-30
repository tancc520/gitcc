#include <stdio.h>

void swap(int data[],int i,int j){
    int temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}

void bullesort(int data[],int len){
    for (int i=0;i<len;i++){
        //每次比较到len-i-1,因为右侧已经排好序
        for (int j=0;j<len-i-1;j++){
            if(data[j]>data[j+1]){
                swap(data,j,j+1);
            }
        }
    }
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    bullesort(data,len);

    for (int i=0;i<len;i++){   
        printf("%d ",data[i]);
    }
    return 0;
}