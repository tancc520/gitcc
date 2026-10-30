#include <bits/stdc++.h>  //这是一个非标准头文件，意为“包含 C++ 标准库里所有头文件”
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   //输入或输出数据量 ≥1e5行，且用 cin/cout时候使用这两行

    int n;
    cin>>n;

    vector<long long> pre(n+1,0);  //创建动态数组
    for(int i=1;i<=n;i++){
        long long x;
        cin>>x;
        pre[i]=pre[i-1]+x;
    }

    int m;
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<'\n';

    }

    return 0;
}