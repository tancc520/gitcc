#include <stdio.h>
int main() {
    int n;
    printf("请输入一个正整数n(1000<n<1000000):");
    scanf("%d",&n);
    printf("它的后三位为%d\n",n%1000);
    return 0;
}