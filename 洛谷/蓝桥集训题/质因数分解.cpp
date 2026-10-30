#include <iostream>
using namespace std;



int main(){
    

    long long  n;
    cin>>n;

    for(long long i=2;i<=n/i;i++){     //i<=n/i等价于i*i<=n
        if(n%i==0){
            cout<<n/i<<'\n';    //n/i比i大，因为i从2开始
            return 0;
        }
    }

    return 0;
}