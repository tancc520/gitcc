//数组或顺序表必须**有序**
#include <stdio.h>

int search_bst(int arr[],int len,int value){
    int low=0;
    int high=len-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if (arr[mid]<value){
            low=mid+1;
        }
        else if (arr[mid]>value){
            high=mid-1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[]={13,3,23,5,25,2,52,5,6};
    int len=sizeof(arr)/sizeof(arr[0]);
    int value=25;
    printf("%d",search_bst(arr,len,value)+1);    
    return 0;
}