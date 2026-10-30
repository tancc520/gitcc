#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef char vert;
typedef int edt;

typedef struct{
    vert vertx[MAXSIZE];
    edt arc[MAXSIZE][MAXSIZE];
    int vertx_num;
    int edt_num;
}mat_graph;

//造图
void create_graph(mat_graph *g){
    g->vertx_num=4;
    g->edt_num=5;
    
    g->vertx[0]='0';
    g->vertx[1]='1';
    g->vertx[2]='2';
    g->vertx[3]='3';

    for (int i=0;i<g->vertx_num;i++){
        for (int j=0;j<g->vertx_num;j++){
            g->arc[i][j]=0;
        }
    }

    g->arc[0][1]=1;g->arc[0][2]=1;g->arc[0][3]=1;
    g->arc[1][2]=1;g->arc[1][0]=1;
    g->arc[2][0]=1;g->arc[2][1]=1;g->arc[2][3]=1;
    g->arc[3][0]=1;g->arc[3][2]=1;
}
void printf_graph(mat_graph *g){
    printf("邻接矩阵（无向）如下：\n");
    for (int i=0;i<g->vertx_num;i++){
        for (int j=0;j<g->vertx_num;j++){
            printf("%d ",g->arc[i][j]);
        }
        printf("\n");
    }
}

int main(){
    mat_graph g;
    create_graph(&g);
    printf_graph(&g);
    return 0;
}