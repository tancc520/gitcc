#include <iostream>
using namespace std;

bool isprime(long long n){
    if (n<2) return false;
    if (n==2 || n==3) return true;
    if (n%2==0) return false;
    for (long long i=3;i<=n/i;i+=2){
        if (n%i==0) return false;
    }
    return true;
}

void printprime(int l){
    int sum=0;
    int i=2;
    int cnt=0;
    while (sum<l){
        if (isprime(i)){
            if (sum+i>l) break;
            sum+=i;
            cnt++;
            cout<<i<<endl;
        }
        i++;
    }
    cout<<cnt<<endl;
}

int main(){
    int l;
    cin>>l;
    printprime(l);
}
