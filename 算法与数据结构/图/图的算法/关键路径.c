//带权有向图
//edv:最早发生时间
//ltv:最晚发生时间
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff

typedef int vertextype;
typedef int edgetype;

typedef struct {
    vertextype vertex[MAXSIZE];
    edgetype arc[MAXSIZE][MAXSIZE];
    int vertexnum;
    int edgenum;
}mat_graph;

typedef struct edgenode{
    int edge_vex;
    int weight;
    struct edgenode *next;
}edgenode;

typedef struct vertexnode{
    int in;
    vertextype data;
    edgenode *firstedge;
}vertexnode;

typedef vertexnode adjlist[MAXSIZE];

typedef struct {
    adjlist adjlist;
    int vertexnum;
    int edgenum;
}adjgraph;

typedef adjgraph *adjlist_graph;

void creategraph(mat_graph *g){
    g->vertexnum=10;
    g->edgenum=13;

    for (int i=0;i<g->vertexnum;i++){
        g->vertex[i]=i;
    }
    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            if (i==j) g->arc[i][j]=0;
            else g->arc[i][j]=MAX;
        }
    }
    g->arc[0][1]=3;
    g->arc[0][2]=4;
    g->arc[1][3]=5;
    g->arc[1][4]=6;
    g->arc[2][3]=8;
    g->arc[2][5]=7;
    g->arc[3][4]=3;
    g->arc[4][6]=9;
    g->arc[4][7]=4;
    g->arc[5][7]=6;
    g->arc[6][9]=2;
    g->arc[7][8]=5;
    g->arc[8][9]=3;
}

//邻接矩阵转表
void create_adjgraph(mat_graph *g,adjlist_graph *alg){
    edgenode *e;
    //初始化邻接表
    *alg=(adjgraph*)malloc(sizeof(adjgraph));   // alg 是 adjgraph**，*alg 才是 adjgraph*
    (*alg)->vertexnum=g->vertexnum;
    (*alg)->edgenum=g->edgenum;
    for (int i=0;i<g->vertexnum;i++){
        (*alg)->adjlist[i].in=0;
        (*alg)->adjlist[i].data=g->vertex[i];
        (*alg)->adjlist[i].firstedge=NULL;
    }
    //初始化邻接表
    for (int i = 0; i < g->vertexnum; i++){
        for (int j=0;j<g->vertexnum;j++){
            if (g->arc[i][j]!=0&& g->arc[i][j]<MAX){
                e=(edgenode*)malloc(sizeof(edgenode));
                e->edge_vex=j;
                e->weight=g->arc[i][j];
                e->next=(*alg)->adjlist[i].firstedge;
                (*alg)->adjlist[i].firstedge=e;
                (*alg)->adjlist[j].in++;   // 修正：入度加在终点 j 上（原来错写成 i）
            }
        }
    }
}

void critical_path(adjlist_graph alg){
    edgenode *e;
    int top=-1;
    int top2=-1;
    int stack[MAXSIZE];
    int stack2[MAXSIZE];   //出栈stack后压入第二个栈
    int etv[MAXSIZE];   
    int ltv[MAXSIZE];
    int curr;
    int k;
    for (int i=0;i<alg->vertexnum;i++){
        if (alg->adjlist[i].in==0){
            top++;
            stack[top]=i;
        }
    }
    for (int i=0;i<alg->vertexnum;i++){
        etv[i]=0;
    }
    while (top!=-1){
        curr=stack[top];
        top--;
        top2++;
        stack2[top2]=curr;
        e=alg->adjlist[curr].firstedge;
        while (e!=NULL ){
            k=e->edge_vex;
            alg->adjlist[k].in--;
            if (alg->adjlist[k].in==0){
                top++;
                stack[top]=k;
            }
            //最早发生时间
            if (etv[curr]+e->weight>etv[k]){
                etv[k]=etv[curr]+e->weight;
            }
            e=e->next;
        }
    }
    printf("etv:");
    for (int i=0;i<alg->vertexnum;i++){
        printf("%d -> ",etv[i]);
    }
    printf("END\n");
    //最晚发生时间
    for (int i=0;i<alg->vertexnum;i++){
        ltv[i]=etv[alg->vertexnum-1];  //将最后一个顶点的最早发生时间做为起点
    }
    while (top2!=-1){
        curr=stack2[top2];
        top2--;
        e=alg->adjlist[curr].firstedge;
        while (e!=NULL ){
            k=e->edge_vex;
            if (ltv[k]-e->weight<ltv[curr]){
                ltv[curr]=ltv[k]-e->weight;
            }
            e=e->next;
        }
    }
    printf("ltv:");
    for (int i=0;i<alg->vertexnum;i++){
        printf("%d ->",ltv[i]);
    }
    printf("END\n");

    //关键路径
    printf("关键路径为:\n");
    for (int i=0;i<alg->vertexnum;i++){
        if(etv[i]==ltv[i]){
            printf("V%d -> ",i);
        }
    }
    printf("END\n");
} 

int main(){
    mat_graph g;
    adjlist_graph alg;      // 修正：声明为指针，与 create_adjgraph 的 *alg 参数类型一致
    creategraph(&g);
    create_adjgraph(&g,&alg);
    critical_path(alg);     // 修正：alg 本身已是指针，不再取地址
    return 0;
}