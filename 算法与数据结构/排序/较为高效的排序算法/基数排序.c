#include <stdio.h>
#include <stdlib.h>

void radixsort(int data[],int len){
    if(len<=1) return;

    //找出最大值，确定要找的“位数”
    int max=data[0];
    for (int i=0;i<len;i++){
        if (data[i]>max) max=data[i];
    }

    int *output=(int*)malloc(sizeof(int)*len);
    if(output==NULL) return;
    int count[10];   //十进制“桶”

    for(int k=1;max/k>0;k*=10){  //k即为位数(1为个位，10为十位.....)
        for(int i=0;i<10;i++) count[i]=0;  //初始count 
        for(int j=0;j<len;j++){
            count[(data[j]/k)%10]++;  //统计每个桶里有多少个
        }

        for(int i=1;i<10;i++){
            count[i]+=count[i-1];
        }

        for(int i=len-1;i>=0;i--){
            int d=(data[i]/k)%10;
            output[count[d]-1]=data[i];
            count[d]--;
        }
        //写回原数组
        for(int i=0;i<len;i++){
            data[i]=output[i];
        }
    }
    free(output);
}

int main(){
    int data[]={47,35,60,95,77,15,20};
    int len=sizeof(data)/sizeof(data[0]);
    
    radixsort(data,len);

    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }

    return 0;
}