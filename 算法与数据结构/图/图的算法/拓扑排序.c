//持续寻找度为0的顶点，然后入栈，出栈 
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100

typedef int vertextype;
typedef int edgetype;

//边节点
typedef struct edgenode{
    int adjvex;   //邻接点在顶点数组的下标
    struct edgenode *next;
}edgenode;

//顶点节点
typedef struct {
    int in;
    vertextype data;
    edgenode *firstedge;
}vertexnode,adjlist[MAXVEX];

//图的结构体
typedef struct {
    adjlist adjlist;  //表示顶点数组
    int vertexnum;
    int edgenum;   
}graph_adjlist;

typedef graph_adjlist *adj_list_graph;

//邻接矩阵
typedef struct {
    vertextype vertex[MAXVEX];
    edgetype arc[MAXVEX][MAXVEX];
    int vertexnum;
    int edgenum;
}mat_graph;

int top=-1;
int stack[MAXVEX];

void push(int e){
    if (top>=MAXVEX-1){          // 修正：栈满判断（合法下标最大为 MAXVEX-1）
        printf("栈已满\n");
        return;
    }
    top++;
    stack[top]=e;
}

int pop(){
    if (top==-1){
        return 0;
    }
    return stack[top--];         //先取栈顶，再自减
}

int isempty(){
    if (top==-1){
        return 1;                
    }
    return 0;
}

void creategraph(mat_graph *g){
    g->vertexnum=14;
    g->edgenum=20;
    for (int i=0;i<g->vertexnum;i++){
        g->vertex[i]=i;
    }
    for (int i=0;i<g->vertexnum ;i++){
        for (int j=0;j<g->vertexnum;j++){
            g->arc[i][j]=0;
        }
    }
    g->arc[0][4] = 1;
    g->arc[0][5] =1;
    g->arc[0][11]= 1;
    g->arc[1][2]=1;
    g->arc[1][4]=1;
    g->arc[1][8]=1;
    g->arc[2][5]=1;
    g->arc[2][6]=1;
    g->arc[2][9]=1;
    g->arc[3][2] =1;
    g->arc[3][13] = 1;
    g->arc[4][7] = 1;
    g->arc[5][8] = 1;
    g->arc[5][12] = 1;
    g->arc[6][5]=1;
    g->arc[8][7]=1;
    g->arc[9][10]=1;
    g->arc[9][11]=1;             
    g->arc[10][13]=1;
    g->arc[12][9]=1;
}

//将邻接矩阵转换为邻接表
void create_adj_graph(mat_graph *g,adj_list_graph *alg){
    edgenode *e;
    //初始化邻接表
    *alg=(graph_adjlist*)malloc(sizeof(graph_adjlist));  // 修正：类型应为 graph_adjlist*
    (*alg)->vertexnum=g->vertexnum;
    (*alg)->edgenum=g->edgenum;
    for (int i=0;i<g->vertexnum;i++){
        (*alg)->adjlist[i].in=0;
        (*alg)->adjlist[i].data=g->vertex[i];
        (*alg)->adjlist[i].firstedge=NULL;
    }
    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            if (g->arc[i][j]==1){
                e=(edgenode*)malloc(sizeof(edgenode));
                //头插法
                e->adjvex=j;
                e->next=(*alg)->adjlist[i].firstedge;
                (*alg)->adjlist[i].firstedge=e;
                (*alg)->adjlist[j].in++;   //入度+1
            }
        }
    }
}

void topological_sort(adj_list_graph alg){
    edgenode *e;
    int curr;
    int k;

    for (int i=0;i<(alg)->vertexnum;i++){
        if (alg->adjlist[i].in==0){
            push(i);
        }
    }
    while (isempty()==0){        
        curr=pop();
        printf("V%d -> ",alg->adjlist[curr].data);
        e=alg->adjlist[curr].firstedge;
        while (e!=NULL){
            k=e->adjvex;   //顶点的下标(v4、V3......)
            alg->adjlist[k].in--;  //节点的入度减少
            if (alg->adjlist[k].in==0){
                push(k);
            }
            e=e->next;
        }
    }
}

int main(){
    mat_graph g;
    adj_list_graph alg;
    creategraph(&g);
    create_adj_graph(&g,&alg);
    topological_sort(alg);
    return 0;
}
