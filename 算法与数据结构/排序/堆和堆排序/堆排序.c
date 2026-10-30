#include <stdio.h>

void swap(int data[],int i,int j){
    int temp=data[i];
    data[i]=data[j];
    data[j]=temp;
}
//建堆
void adjust(int data[],int root,int len){
    int child;
    int temp=data[root];  //根节点值
    child=2*root;  //左孩子下标
    
    //只要存在孩子节点
    while(child<=len){
        //如果有右孩子，且右孩子比左孩子大，则选右孩子
        if(child<len && data[child]<data[child+1]){
            child++;  //右孩子下标
        }
        if(temp>data[child]) break;
        //子节点上移
        data[child/2]=data[child];
        //继续向下调整
        child=child*2;
    }
    //把原root的值放到最终位置
    data[child/2]=temp;
}

void heapsort(int data[],int length){
    //1.建堆过程：从最后一个非叶子节点开始向上调整
    for(int i=length/2;i>0;i--){
        adjust(data,i,length);
    }
    //2.排序过程：将堆顶最大值交换到数组末尾，并调整剩余部分为大根堆
    for(int i=length;i>0;i--){
        swap(data,1,i);
        adjust(data,1,i-1);   //交换后转换为大根堆
    }
}

int main(){
    //data[0]未使用，-1占位是为了从data[1]开始查找
    int data[]={-1,47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    heapsort(data,len-1);  //-1不算

    for(int i=1;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}