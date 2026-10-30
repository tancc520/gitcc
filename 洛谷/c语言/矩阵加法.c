#include <stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    int A[100][100],B[100][100],C[100][100];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
        scanf("%d",&A[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
        scanf("%d",&B[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d",C[i][j]);
            if (j!=m-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
