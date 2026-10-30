#include <stdio.h>

int partition(int data[],int low,int high){
    //选择最左侧元素为基准元素
    int pivot=data[low];

    while(low<high){
        //右侧寻找一个比pivot小的数
        while(low<high&&data[high]>=pivot){
            high--;
        }
        data[low]=data[high];
        //左侧寻找一个比pivot大的数
        while(low<high&&data[low]<=pivot){
            low++;
        }
        data[high]=data[low];
    }
    //将pivot放在low上，标志着partition结束
    data[low]=pivot;
    return low;  //返回pivot的最终位置，pivot已确定了位置
}

void quicksort(int data[],int low,int high){
    int pivot;
    if(low<high){
        pivot=partition(data,low,high);
        quicksort(data,low,pivot-1);  //递归排序左侧
        quicksort(data,pivot+1,high);  //递归排序右侧
    }
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    quicksort(data,0,len-1);

    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}