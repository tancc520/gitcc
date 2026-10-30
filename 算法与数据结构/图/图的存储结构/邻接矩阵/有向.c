#include <stdio.h>
#define MAXSIZE 100

typedef char vert;
typedef int egt;

typedef struct {
    vert vertx[MAXSIZE];
    egt arc[MAXSIZE][MAXSIZE];
    int vertx_num;
    int edt_num;
}mat_graph;

void create_graphtoward(mat_graph *g){
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

    g->arc[0][3]=1;
    g->arc[1][0]=1;g->arc[1][2]=1;
    g->arc[2][0]=1;g->arc[2][1]=1;
}
void printf_graph(mat_graph *g){
    printf("邻接矩阵（有向）如下：\n");
    for (int i=0;i<g->vertx_num;i++){
        for (int j=0;j<g->vertx_num;j++){
            printf("%d ",g->arc[i][j]);
        }
        printf("\n");
    }
}


int main(){
    mat_graph g;
    create_graphtoward(&g);
    printf_graph(&g);
    return 0;
}