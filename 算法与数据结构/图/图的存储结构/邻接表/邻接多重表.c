//一条边只用一个节点表示，节省空间
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTX 100

typedef char vertextype;
typedef int infotype;

//边节点
typedef struct ebox{
    int ivex,jvex;    //边依附的两个顶点
    struct ebox *ilink;   //指向依附ivex的下一条边
    struct ebox *jlink;
    infotype *info; 
}ebox;

//顶点节点
typedef struct vexbox{
    vertextype data;
    ebox *firstedge;   //指向第一条依附该顶点的边
}vexbox;

//邻接多重表
typedef struct {
    vexbox adjlist[MAXVERTX];
    ebox edge;
    int vertxnum;
    int edgenum;
}AMLgraph;

int visited[MAXVERTX];

//初始化顶点
void initvertx(AMLgraph *g,vertextype vertx[],int n){
    g->vertxnum=n;
    g->edgenum=0;

    for (int i=0;i<g->vertxnum;i++){
        g->adjlist[i].data=vertx[i];
        g->adjlist[i].firstedge=NULL;
    }
}

//添加一条无向边（vi,vj）
void edgeadd(AMLgraph *g,int vi,int vj){
    ebox *e=(ebox*)malloc(sizeof(ebox));
    if (e==NULL ){
        printf("内存分配失败\n");
        exit(1);  //立即终止整个函数程序
    }
    e->ivex=vi;
    e->jvex=vj;
    e->info=NULL;

     e->ilink=g->adjlist[vi].firstedge;
     g->adjlist[vi].firstedge=e;

     e->jlink=g->adjlist[vj].firstedge;
     g->adjlist[vj].firstedge=e;

     g->edgenum++;   //函数执行多少次，自动计算出边的条数
}

//打印每个顶点的所有邻接点
void print_ad(AMLgraph *g){
    printf("各顶点的邻接点为:\n");
    for (int i=0;i<g->vertxnum;i++){
        printf("V%d(%c):",i,g->adjlist[i].data);
        ebox *p=g->adjlist[i].firstedge;
        while (p!=NULL){
            int neibor=(p->ivex==i)?p->jvex:p->ivex;
            printf("V%d ",neibor);
            //沿顶点i的链继续
            if (p->ivex==i) p=p->ilink;
            else p=p->jlink;   //ivex无下一条边时转向jvex
        }
        printf("\n");
    }
}

int main(){
    AMLgraph g;
    vertextype vertx[]={'1','2','3','4'};
    int n=sizeof(vertx)/sizeof(vertx[0]);

    initvertx(&g,vertx,n);

    edgeadd(&g,0,1);
    edgeadd(&g,0,2);
    edgeadd(&g,0,3);
    edgeadd(&g,1,2);
    edgeadd(&g,2,3);

    print_ad(&g);

    return 0;
}