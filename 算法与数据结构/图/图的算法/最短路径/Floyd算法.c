#include <stdio.h> 
#include <stdlib.h>
#define MAX 0x10000
#define MAXEGDE 200
#define MAXSIZE 100

typedef char vertextype;
typedef int edgetype;

typedef struct {
    vertextype vertx[MAXSIZE];
    edgetype arc[MAXSIZE][MAXSIZE];
    int edgenum;
    int vertexnum;
}mat_graph;

//造图
void creategraph(mat_graph *g){
    g->vertexnum=9;
    g->edgenum=16;
    for (int i=0;i<g->vertexnum;i++){
        g->vertx[i]=i;
    }
    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            if (i==j){
                g->arc[i][j]=0;
            }
            else g->arc[i][j]=MAX;
        }
    }
    g->arc[0][1]=1;g->arc[0][2]=5;
    g->arc[1][2]=3;g->arc[1][3]=7;g->arc[1][4]=5;
    g->arc[2][5]=7;g->arc[2][4]=1;
    g->arc[3][4]=2;g->arc[3][6]=3;
    g->arc[4][5]=3;g->arc[4][6]=6;g->arc[4][7]=9;
    g->arc[5][7]=5;
    g->arc[6][7]=2;g->arc[6][8]=7;
    g->arc[7][8]=4;
    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            g->arc[j][i]=g->arc[i][j];
        }
    }
}

void Folyd(mat_graph *g){
    int path[MAXSIZE][MAXSIZE];
    int distanace[MAXSIZE][MAXSIZE];

    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            distanace[i][j]=g->arc[i][j];
            path[i][j]=j;
        }
    }
    //i:起始顶点,j:中转顶点，k:终止顶点
    for (int i=0;i<g->vertexnum;i++){
        for (int j=0;j<g->vertexnum;j++){
            for (int k=0;k<g->vertexnum;k++){
                if (distanace[j][k]>distanace[j][i]+distanace[i][k]){
                    distanace[j][k]=distanace[j][i]+distanace[i][k];
                    path[j][k]=path[j][i];
                }
            }
        }
    }
    int k;
    for (int i=0;i<g->vertexnum;i++){
        for (int j=i+1;j<g->vertexnum;j++){
            printf("V%d - V%d weight:%d",i,j,distanace[i][j]);
            k=path[i][j];
            printf("path:V%d",i);
            while (k!=j){
                printf("->%d",k);
                k=path[k][j];
            }
            printf("->V%d\n",j);
        }
        printf("\n");
    }
}

int main(){
    mat_graph g;;
    creategraph (&g);
    Folyd(&g);
    return 0;
}