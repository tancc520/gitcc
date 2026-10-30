#include <stdio.h>
#include <stdlib.h>
#define MAX 0x7fffffff
#define MAXVERTX 100

typedef char vertxtype;
typedef int edgetype;

typedef struct {
    vertxtype vertx[MAXVERTX];
    edgetype arc[MAXVERTX][MAXVERTX];
    int vertxnum;
    int edgenum;
}mat_graph;

//造图(MAX表示无穷，指两顶点没有连接)
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
            if (i==j){
                g->arc[i][j]=0;
            }
            else g->arc[i][j]=MAX;
        }
    }
    g->arc[0][1]=10;g->arc[0][5]=11;
    g->arc[1][6]=16;g->arc[1][2]=18;g->arc[1][8]=12;
    g->arc[2][8]=8;g->arc[2][3]=22;
    g->arc[3][6]=24;g->arc[3][4]=20;g->arc[3][7]=16;
    g->arc[4][5]=26;g->arc[4][7]=7;
    g->arc[5][6]=17;
    g->arc[6][7]=19;
    for (int i=0;i<g->vertxnum;i++){
        for (int j=0;j<g->vertxnum;j++){
            g->arc[j][i]=g->arc[i][j];
        }
    }
}

//prim算法
void prim(mat_graph *g){
    int j,k;
    int min;
    int weight[MAXVERTX];   //候选边
    int vex_index[MAXVERTX];   //值表示出发点，下标表示到达点

    weight[0]=0;
    vex_index[0]=0;

    for (int i=1;i<g->vertxnum;i++){
        weight[i]=g->arc[0][i];
        vex_index[i]=0;
    }
    for (int i=1;i<g->vertxnum;i++){
        min=MAX;
        j=0;
        k=0;
        //寻找这一行中值最小的weight
        while (j<g->vertxnum){
            if (weight[j]!=0 && weight[j]<min){
                min=weight[j];
                k=j;
            }
            j++;
        }
        printf("(%c %c)\n",g->vertx[vex_index[k]],g->vertx[k]);
        weight[k]=0;  //防止产生回路

        //寻找待选路径
        for (int j=0;j<g->vertxnum;j++){
            if (weight[j]!=0 && g->arc[k][j]<weight[j]){
                weight[j]=g->arc[k][j];
                vex_index[j]=k;  
            }
        }
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    printf("prim算法遍历:\n");
    prim(&g);
    return 0;
}