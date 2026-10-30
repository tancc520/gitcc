#include <stdio.h>

//插入排序
void insertsort(int data[],int len){
    int key;  //暂存当前待插入的元素
    for (int i=1;i<len;i++){
        key=data[i];
        int j=i-1;
        //向前查找插入位置，移动比key大的元素
        while(j>=0&&data[j]>key){
            data[j+1]=data[j];  //将比key大的元素向后移
            j--;  //向前继续比较
        }
        //插入key
        data[j+1]=key;
    }
}

//折半插入排序
void biinsertsort(int data[],int len){
    int low,high,mid;
    int key;
    for (int i=1;i<len;i++){
        key=data[i];  //记录待插入的值
        low=0;
        high=i-1;
        
        while(low<=high){
            mid=(low+high)/2;
            if(data[mid]>key) high=mid-1; //插入点在左边
            else low=mid+1;  //插入点在右边
        }
        //从后往前依次将大于key的元素后移，为key腾出位置
        int j=i-1;
        while(j>=low){
            data[j+1]=data[j];
            j--;
        }
        //why low?: because:while(low<=high)
        data[low]=key;
    }
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    insertsort (data,len);

    for (int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}