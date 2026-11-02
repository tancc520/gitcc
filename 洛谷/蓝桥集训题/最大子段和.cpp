#include <bits/stdc++.h>  
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    int n;
    cin>>n;

    ll sum=0,maxsum=LLONG_MIN;   //求最大用最小垫底
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum+=x;
        maxsum=max(maxsum,sum);
        if(sum<0) sum=0;
    }
    cout<<maxsum<<"\n";

    return 0;
}