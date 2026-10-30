#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

//定义边节点
typedef struct egdenode{
    int adjvex;       //邻接点在顶点数组的下标
    struct egdenode *next;
}egdenode;

//定义顶点表节点结构体 
typedef struct vertexnode{
    char data;
    egdenode *firstedge;   //顶点后的第一条边
}vertexnode,adjlist[MAXVEX]; 

//图的结构体
typedef struct {
    adjlist adjlist;    //等价于vertxnode adjlist[MAXVEX]   做一个数组表示顶点
    int vertxnum;    //顶点数
    int edgenum;   //边数
}graphadjlist;
  
void creategraph(graphadjlist *g){
    g->vertxnum=4;
    g->edgenum=5;

    //命名和初始化顶点
    for (int i=0;i<g->vertxnum;i++){
        g->adjlist[i].data='0'+i;
        g->adjlist[i].firstedge=NULL;
    }

    //边集合
    int edge[5][2]={{0,1},{0,2},{0,3},{1,2},{2,3}};

    for (int i=0;i<g->edgenum;i++){
        int from=edge[i][0];
        int to=edge[i][1]; //这里的0，1表下标
        
        //因为是无向图，所以要做from->to和to->from
        //过程如同头插法，所以最后输出是v0->3->2->1,并不是v0->1->2->3
        egdenode *e1=(egdenode*)malloc(sizeof(egdenode));
        e1->adjvex=to;
        e1->next=g->adjlist[from].firstedge;
        g->adjlist[from].firstedge=e1;

        //有向删除t0-from即可 
        //逆邻接表改为to-from即可
        egdenode *e2=(egdenode*)malloc(sizeof(egdenode));
        e2->adjvex=from;
        e2->next=g->adjlist[to].firstedge;
        g->adjlist[to].firstedge=e2;
    }
}

void print_graph(graphadjlist *g){
    printf("图的邻接链表如下:\n");
    for (int i=0;i<g->vertxnum;i++){
        printf("V%c->",g->adjlist[i].data);
        egdenode *p=g->adjlist[i].firstedge;
        while(p){
            printf("%d->",p->adjvex); 
            p=p->next;
        }
        printf("^\n");
    }
}

int main(){
    graphadjlist g;
    creategraph(&g);
    print_graph(&g); 
    return 0;
}