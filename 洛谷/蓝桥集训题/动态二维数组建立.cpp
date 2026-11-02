#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,c;
    cin>>n>>m>>c;
    //初始化一个(n+1)*(m+1)动态二维数组
    //n+1和m+1做哨兵，防止越界(如访问 s[-1][...]))  
    vector<vector<ll>> s(n+1,vector<ll>(m+1,0));  //初始化一个(n+1)*(m+1)动态二维数组
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll x;
            cin>>x;
            //s[i][j] = 以 (1,1) 为左上角、以 (𝑖,𝑗)为右下角的矩形内所有数的和。
            //因为 s[i-1][j] 和 s[i][j-1] 这两个矩形有重叠，重叠的那块被加了两次。
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;  //-s[i-1][j-1]重复
        }
    }

    ll best=LLONG_MIN;
    int bx=1,by=1;

    for(int x=1;x+c-1<=n;++x){
        for(int y=1;y+c-1<=m;++y){
            int x2=x+c-1,y2=y+c-1;
            ll v=s[x2][y2]-s[x-1][y2]-s[x2][y-1]+s[x-1][y-1];  //同上
            if(v>best){
                best=v;
                bx=x;
                by=y;
            }
        }
    }

    cout<<bx<<' '<<by<<"\n";

    return 0;
}