//十字链表即可表示出边，也可表示入边
#include <stdio.h>  
#include <stdlib.h>
#define MAXVERTXNUM 100

typedef int infotype;
typedef char vertxtype;

//弧节点（边节点）
typedef struct arcbox{
    int tailvertx;  //弧尾顶点的位置
    int headvertx;  //弧头顶点的位置
    struct arcbox *tlink;  //指向下一个具有相同弧尾的弧
    struct arcbox *hlink;  //指向下一个具有相同弧头的弧
    infotype *info;
}arcbox;

//顶点节点
typedef struct vertxnode{
    vertxtype data;     //顶点信息
    arcbox *firstin;    //指向该顶点的第一条入弧
    arcbox *firstout;   //指向该顶点的第一条出弧
}vertxnode;

//十字链表图
typedef struct{
    vertxnode xlist[MAXVERTXNUM];  //顶点表
    int vertxnum; //顶点数
    int arcnum;  //弧数
}OLgraph;

//在vi和vj之间创建一条弧（有向边vi->vj）
void arcadd(OLgraph *g,int vi,int vj){
    arcbox *newarc=(arcbox*)malloc(sizeof(arcbox));
    if (newarc==NULL){
        printf("内存分配失败\n");
    }
    newarc->headvertx=vj; //头
    newarc->tailvertx=vi; //尾
    newarc->info=NULL;

    //将新弧插入到vj的入弧链表（头插法）
    newarc->hlink=g->xlist[vj].firstin;
    g->xlist[vj].firstin=newarc;

    newarc->tlink=g->xlist[vi].firstout;
    g->xlist[vi].firstout=newarc;
}

//初始化图
void initgraph(OLgraph *g,vertxtype vext[],int n){
    g->vertxnum=n;
    g->arcnum=0;
    for (int i=0;i<n;i++){
        g->xlist[i].data=vext[i];
        g->xlist[i].firstin=NULL;
        g->xlist[i].firstout=NULL;
    }
}

//输出出边
void printf_outarc(OLgraph *g){
    printf("各顶点的出边为:\n");
    for (int i=0;i<g->vertxnum;i++){
        printf("V%c的出边:",g->xlist[i].data);
        arcbox *p=g->xlist[i].firstout;
        if(p==NULL){
            printf("无");
        }
        while(p!=NULL){
            printf("V%d -> V%d",p->tailvertx,p->headvertx);
            p=p->tlink;
            if(p!=NULL) printf(",");
        }
        printf("\n");
    }
}

//输出入边
void printfinarc(OLgraph *g){
    printf("各顶点的入边为:\n");
    for (int i=0;i<g->vertxnum;i++){
        printf("V%c的入边:",g->xlist[i].data);
        arcbox *p=g->xlist[i].firstin;
        if (p==NULL){
            printf("无");
        }
        while (p!=NULL){
            printf("V%d -> V%d",p->tailvertx,p->headvertx);
            p=p->hlink;
            if (p!=NULL) printf(",");
        }
        printf("\n");
    }
}

int main(){
    OLgraph g;
    vertxtype vetx[]={'0','1','2','3'};
    int n=sizeof(vetx)/sizeof(vetx[0]);

    initgraph(&g,vetx,n);

    //添加有向边
    arcadd(&g,0,1);
    arcadd(&g,0,2);
    arcadd(&g,0,3);
    arcadd(&g,1,0);
    arcadd(&g,1,2);
    arcadd(&g,2,0);
    arcadd(&g,2,1);

    g.arcnum=7;

    printf_outarc(&g);
    printf("\n");
    printfinarc(&g);
    return 0;
}