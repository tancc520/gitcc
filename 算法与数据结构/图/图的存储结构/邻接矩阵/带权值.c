#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX 0x7fffffff   //用一个极大值表示无穷 

typedef char vert;
typedef int edt;

typedef struct {
    vert vertx[MAXSIZE];
    edt arc[MAXSIZE][MAXSIZE];
    int vert_num;
    int edt_num;
}mat_graph;

void creategraph(mat_graph *g){
    g->vert_num=4;
    g->edt_num=5;

    for (int  i = 0; i <g->vert_num; i++){
        g->vertx[i]='0'+i;
    }

    for (int i=0;i<g->vert_num;i++){
        for (int j=0;j<g->vert_num;j++){
            g->arc[i][j]=MAX;
            if(i==j){
                g->arc[i][j]=0;
            }
        }
    }
    g->arc[0][3]=3;
    g->arc[1][0]=5;
    g->arc[1][2]=2;
    g->arc[2][0]=6;
    g->arc[2][1]=4;
}

void printf_matgraph(mat_graph *g){
    printf("图的邻接矩阵如下（MAX表示无边）:\n");
    for (int i=0;i<g->vert_num;i++){
        for (int j=0;j<g->vert_num;j++){
            if (g->arc[i][j]==MAX){
                printf("MAX ");
            }
            else {
                printf("%3d ",g->arc[i][j]);
            }
        }
        printf("\n");
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    printf_matgraph(&g);
    return 0;
}