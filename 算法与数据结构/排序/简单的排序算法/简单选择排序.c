#include <stdio.h>

void swap(int data[],int i,int j){
    int temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}

void choosesort(int data[],int len){
    for (int i=0;i<len;i++){
        int min=i;
        for(int j=i+1;j<len;j++){
            if(data[j]<data[min]){
                min=j;
            }
        }
        //如果找到的最小值不是当前位置,则进行交换
        if(i!=min){   //i！=min作用为“本轮 data[i] 恰好就是未排序区最小值”的开销
            swap(data,i,min);
        }
    }
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    choosesort(data,len);

    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}