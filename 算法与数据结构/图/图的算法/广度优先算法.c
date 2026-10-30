#include <stdio.h>
#include <stdlib.h> 
#define MAXVERTX 100

typedef char vertxtype;
typedef int edgetype;

typedef struct {
    vertxtype vertx[MAXVERTX];
    edgetype arc[MAXVERTX][MAXVERTX];
    int vertxnum;
    int egdenum;
}mat_graph;

int visited[MAXVERTX];
int queue[MAXVERTX];
int rear=0;
int front=0;

//造图
void creategraph(mat_graph *g){
    g->vertxnum=9;
    g->egdenum=15;
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

//广度优先遍历
void bfs(mat_graph g){
    int i=0;
    visited[i]=1;
    printf("%c ",g.vertx[i]);
    queue[rear]=i;
    rear++;
    while (front!=rear){
        i=queue[front];
        front++;
        for (int  j = 0; j <g.vertxnum; j++){
            if (g.arc[i][j]!=0 && visited[j]==0){
                visited[j]=1;
                printf("%c ",g.vertx[j]);
                queue[rear]=j;
                rear++;
            }
        }
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    for (int  i = 0; i <g.vertxnum; i++){
        visited[i]=0;
    }
    printf("广度优先遍历:\n");
    bfs(g);
    return 0;

}