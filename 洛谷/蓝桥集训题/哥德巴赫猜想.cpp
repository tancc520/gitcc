#include <iostream>
using namespace std;

const int MAXN=10005;
bool notprime[MAXN];

int main(){
    int n;
    cin>>n;

    notprime[0]=notprime[1]=true;
    for (int i=2;i*i<=n;i++){
        if (!notprime[i]){
            for (int j=i*i;j<=n;j+=i) notprime[j]=true;
        }
    }
    for (int i=4;i<=n;i+=2){
        for (int a=2;a<=i/2;a++){
            if (!notprime[a]&&!notprime[i-a]){
                cout<<i<<"="<<a<<"+"<<i-a<<endl;
                break;
            }
        }
    }
    return 0;
}