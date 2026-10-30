#include <stdio.h>

void shellsort(int data[],int len){
    int temp;
    int step=len/2;
    while(step>=1){
        //对每个分组进行插入排序
        for(int i=step;i<len;i++){
            if(data[i]<data[i-step]){  //当前步长下数组的尾大于头
                temp=data[i];  //暂存当前值
                int j=i-step;
                while(j>=0&&temp<data[j]){
                    data[j+step]=data[j];  //将较大值后移
                    j=j-step;
                }
                //插入temp
                data[j+step]=temp;
            }
        }
        //缩小步长直到为1
        step=step/2;
    }

}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);

    shellsort(data,len);

    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}