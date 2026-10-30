#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    
    ll cur=0;
    ll ans=LLONG_MIN; //“求最大用最小垫底，求最小用最大封顶”。

    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        cur=max(x,cur+x);
        ans=max(ans,cur);
    }
    cout<<ans<<'\n';

    return 0;
}