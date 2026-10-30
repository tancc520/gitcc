#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char vertxtype;
typedef int edgetype;

typedef struct {
    vertxtype vertx[MAXSIZE];
    edgetype arc[MAXSIZE][MAXSIZE];
    int vertxnum;
    int edgenum;
}mat_graph;

int visited[MAXSIZE];

//造图
void creategraph(mat_graph *g){
    g->vertxnum=9;
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

    for (int i=0;i<g->vertxnum;i++){
        for (int j=0;j<g->vertxnum;j++){
            g->arc[i][j]=0;
        }
    }
    g->arc[0][1]=1;g->arc[0][5]=1;
    g->arc[1][6]=1;g->arc[1][2]=1;g->arc[1][8]=1;
    g->arc[2][8]=1;g->arc[2][3]=1;
    g->arc[3][6]=1;g->arc[3][4]=1;g->arc[3][7]=1;
    g->arc[4][5]=1;g->arc[4][7]=1;
    g->arc[5][6]=1;
    g->arc[6][7]=1;

    for (int i=0;i<g->vertxnum;i++){
        for (int j=0;j<g->vertxnum;j++){
            g->arc[j][i]=g->arc[i][j];
            }
        }
}

//深度优先搜索(递归)
void dfs(mat_graph *g,int i){
    visited[i]=1;
    printf("%c ",g->vertx[i]);
    for (int j=0;j<g->vertxnum;j++){
        if (g->arc[i][j]==1 && visited[j]==0){
            dfs(g,j);
        }
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    for (int i=0;i<g.vertxnum;i++){
        visited[i]=0;
    }
    printf("深度优先算法的遍历顺序为:\n");
    dfs(&g,0);
    return 0;
}