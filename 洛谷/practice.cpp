#include <bits/stdc++.h>  
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int n,m;
    cin>>n>>m;

    vector<vector<ll>>s(n+1,vector<ll>(m+1,0));  

    ll ans=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            cin>>x;
            if(x==1){
                //边长，有点像递归
                s[i][j]=min({s[i-1][j],s[i][j-1],s[i-1][j-1]})+1; 
                ans=max(ans,s[i][j]);
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}