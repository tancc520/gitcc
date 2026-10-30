#include <stdio.h>

void merge(int data[],int left,int mid,int right){
    int temp[100];   //暂存数据，后续将其复制到data[]中
    int i=left;   //左半部分起始索引
    int j=mid+1;  //有半部分起始索引
    int k=0;  //temp数组的下标

    while(i<=mid&&j<=right){
    
        if(data[i]<data[j])  temp[k++]=data[i++];  
        else temp[k++]=data[j++];
    }
    //将左边剩余部分拷贝到temp中(如果有)
    while(i<=mid){
        temp[k++]=data[i++];
    }
    //将右边剩余部分拷贝到temp中(如果有)
    while(j<=right){
        temp[k++]=data[j++];
    }
    //拷贝temp到data中
    for(int i=0;i<k;i++){
        data[left+i]=temp[i];
    }
}

void mergesort(int data[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(data,left,mid);  //递归左侧
        mergesort(data,mid+1,right);  //递归右侧
        merge(data,left,mid,right);  //将排好序的左右两边合并
    }
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    mergesort(data,0,len-1);

    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}