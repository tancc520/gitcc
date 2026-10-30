#include <stdio.h>
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int A[100][100],B[100][100];
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            B[i][j]=A[j][i];    
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            printf("%d",B[i][j]);
            if (j!=n-1){ //转置后j！=n-1而不是m-1
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}