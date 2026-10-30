//从边入手，找最小权值边
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTX 100
#define MAXEDGE  200
#define MAX  0x7fffffff

typedef char vertextype;
typedef int edgetype;

//邻接矩阵
typedef struct {
    vertextype vertx[MAXVERTX];
    edgetype arc[MAXVERTX][MAXVERTX];
    int vertexnum;
    int edgenum;
}mat_graph;

typedef struct {
    int begin;
    int end;
    int weight;
}edge;

//造图
void creategraph(mat_graph *g){
    g->vertexnum=9;
    g->edgenum=15;

    g->vertx[0]='A';
    g->vertx[1]='B';
    g->vertx[2]='C';
    g->vertx[3]='D';
    g->vertx[4]='E';
    g->vertx[5]='F';
    g->vertx[6]='G';
    g->vertx[7]='H';
    g->vertx[8]='I';

    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            if (i==j){
                g->arc[i][j]=0;
            }
            else g->arc[i][j]=MAX;   //两个顶点不连通 
        }
    }

    g->arc[0][1]=10;g->arc[0][5]=11;
    g->arc[1][6]=16;g->arc[1][2]=18;g->arc[1][8]=12;
    g->arc[2][8]=8;g->arc[2][3]=22;
    g->arc[3][6]=24;g->arc[3][4]=20;g->arc[3][7]=16;
    g->arc[4][5]=26;g->arc[4][7]=7;
    g->arc[5][6]=17;
    g->arc[6][7]=19;

    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            g->arc[j][i]=g->arc[i][j];
        }
    }
}

//swap和sortedges两个函数对边进行排序
void swap(edge* edges,int i,int j){
    int temp;
    temp=edges[i].begin;
    edges[i].begin=edges[j].begin;
    edges[j].begin=temp;

    temp=edges[i].end;
    edges[i].end=edges[j].end;
    edges[j].end=temp; 

    temp=edges[i].weight;
    edges[i].weight=edges[j].weight;
    edges[j].weight=temp;
}
//比较排序法
void sortedges(edge *edges,int edge_num){
    for (int i=0;i<edge_num;i++){
        for (int j=i+1;j<edge_num;j++){    // 从 i+1 开始，才是正确的选择排序（升序）
            if (edges[i].weight>edges[j].weight){
                 swap(edges,i,j);
            }
        }
    }
}

int find(int *parent,int index){
    while(parent[index]>0){
        index=parent[index];
    }
    return index;
}

void kruskal(mat_graph *g){
    edge edges[MAXEDGE];
    int k=0;
    //提取边：上界用 vertexnum（矩阵维度），j=i+1 去重，避免越界
    for (int i=0;i<g->vertexnum;i++){
        for (int j=i+1;j<g->vertexnum;j++){
            if (g->arc[i][j]<MAX){
                edges[k].begin=i;
                edges[k].end=j;
                edges[k].weight=g->arc[i][j];
                k++;
            }
        }
    }

    sortedges(edges, k);     

    int parent[MAXEDGE];
    for (int i=0;i<g->vertexnum;i++) parent[i]=0;

    int n,m,select=0;
    for (int i=0;i<k;i++){        // 遍历实际边数 k
        n=find(parent,edges[i].begin);
        m=find(parent,edges[i].end);
        if (n!=m){
            parent[n]=m;
            printf("(%c %c) %d\n",g->vertx[edges[i].begin],g->vertx[edges[i].end],edges[i].weight);
            select++;
            if (select==g->vertexnum-1) break;  // 选够 n-1 条边停止
        }
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    kruskal(&g);
    return 0;
}
