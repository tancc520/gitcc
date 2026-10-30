//迪杰斯特拉算法解决的是单源最短路径问题，前提是所有边权非负
//松弛：看看能不能抄近路
#include <stdio.h>
#include <stdlib.h>
#define MAXVERTX  100
#define  MAX 0x7fffffff

typedef char vertextype;
typedef int edgetype;

typedef struct {
    vertextype vertx[MAXVERTX];
    edgetype arc[MAXVERTX][MAXVERTX];
    int vertexnum;
    int edgenum;
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

//返回下一次要观察哪个顶点
int choose(int distance[],int found[],int vert_num){
    int min=MAX;
    int minpos=-1;
    for (int i=0;i<vert_num;i++){
        //寻找两个顶点之间的最短路径
        if (distance[i]<min && found[i]==0){
             min=distance[i];
             minpos=i;
        }
    }
    return minpos;
}

//dijstra算法
void dijstra(mat_graph *g,int begin){
    int found[MAXVERTX];
    int path[MAXVERTX];
    int distace[MAXVERTX];
    for (int i=0;i<g->vertexnum;i++){
        found[i]=0;
        path[i]=-1;
        distace[i]=g->arc[begin][i];
    }
    found[begin]=1;
    distace[begin]=0;
    int next;
    for (int i=1;i<g->vertexnum;i++){
        next=choose(distace,found,g->vertexnum);
        if(next==-1) break;          // 没有可达顶点了，防止 found[-1] 越界 //防止图不连通
        found[next]=1;
        for (int j=0;j<g->vertexnum;j++){
            if(found[j]==0){
                // 只有存在边（arc≠MAX）时才松弛，否则 MAX 相加会溢出成负数
                if(g->arc[next][j]!=MAX && distace[next]+g->arc[next][j]<distace[j]){
                    /*松弛直觉：去 j 原来要 distace[j]，
                    现在绕道先到 next 再到 j 只要 distace[next] + arc[next][j]，更短就更新。*/
                    distace[j]=distace[next]+g->arc[next][j];
                    path[j]=next;  //记录前驱
                }
            }
        }
    }
    for (int i=1;i<g->vertexnum;i++){
        printf("V0 -> V%d: %d\n",i,distace[i]);
        int j=i;
        printf("V%d<-",i);
        //path[j]是一个前驱数组，只会告诉上一个是谁，所以只能倒序输出
        while(path[j]!=-1){
            printf("V%d <-",path[j]);
            j=path[j];
        }
        printf("V0\n");
    }
}

int main(){
    mat_graph g;
    creategraph(&g);
    dijstra(&g,0);
    return 0;
}