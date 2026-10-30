#include <stdio.h>
#include <string.h>  //strcpy
#include <stdlib.h>  //malloc函数
#define maxsize 100
typedef int element;

//顺序表初始化(动态内存分配)
typedef struct 
{
    /* data */
    element *data;
    int length;
}seqlist;
seqlist *inlist(){
    seqlist *L=(seqlist*)malloc(sizeof(seqlist));
    L->data=(element*)malloc(sizeof(element)*maxsize);
    L->length=0;
    return L;
}

//在尾部添加元素
int append(seqlist *L,element e){
    if (L->length>=maxsize){
        printf("顺序已满\n");
        return 0;
    }
    L->data[L->length]=e;
    L->length++;
    return 1;
}

//遍历
void listment(seqlist *L){
    for (int i=0;i<L->length;i++){
        printf("%d\t",L->data[i]);
    }
    printf("\n");
}

//查找(根据位置查找)
void findlist1(seqlist *L,element pos){
    if (pos>L->length){
        printf("在数组中不存在\n");
    }
    printf("第%d个元素为:%d\n",pos,L->data[pos-1]);
}

//插入
int setin(seqlist *L,element pos,element e){
    if (L->length>maxsize){
        printf("列表已满\n");
        return 0;
    }
    else if(pos<1||pos>L->length){
        printf("插入位置错误\n");
        return 0;
    }
    for( int i=L->length-1;i>=pos-1;i--){
        L->data[i+1]=L->data[i];
    }
    L->data[pos-1]=e;
    L->length++;
    return 1;
}

//删除
void delete(seqlist *L,element pos,element *e){
    *e=L->data[pos-1];
    if (pos>L->length){
        printf("删除所在的位置大于列表的长度");
    }
    for (int i=pos;i<L->length;i++){
        L->data[i-1]=L->data[i];
    }
    L->length--;
}

//查找(根据元素查找)
int findlist2(seqlist *L,element e){
    for(int i=0;i<L->length;i++){
        if (L->data[i]==e){
            return i+1;
        }
    }
    return 0;
}

int main(){
    seqlist *list=inlist();
    printf("初始化成功，目前长度为%d\n",list->length);
    printf("目前占用内存%d字节\n",(int)sizeof(list->data));
    append(list,2);    
    append(list,22);
    append(list,783257);
    append(list,232);
    listment(list);
    findlist1(list,3);
    setin(list,2,91);
    listment(list);
    element deletedata;
    delete(list,3,&deletedata);
    printf("删除的数据为:%d\n",deletedata);
    listment(list);
    int pos=findlist2(list,91); //查找22第一次出现在哪个位置
    printf("元素91第一次出现的位置在顺序表第%d位",pos);
    return 0;
}