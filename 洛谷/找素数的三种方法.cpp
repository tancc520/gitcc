#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//方法一：试除法——对每个数单独判断
bool isprime(int n){
    if (n<2) return false;
    for (int i=2;i*i<=n;i++){
        if (n%i==0) return false;
    }
    return true;
}

//方法一：返回 2~n 内的所有素数
vector<int> primesByTrial(int n){
    vector<int> res;
    for (int i=2;i<=n;i++){
        if (isprime(i)) res.push_back(i);
    }
    return res;
}

//方法二：埃氏筛(素数的整数倍一定是合数)，找出合数，剩下的就是素数
vector<int> primesByEratosthenes(int n){
    vector<bool> notp(n+1,false);   //notp[i]==true 表示 i 是合数，初始全假设为素数
    if (n>=0) notp[0]=true;
    if (n>=1) notp[1]=true;

    //遍历从2到sqrt(n)的所有数
    for (int i=2;i*i<=n;i++){
        if (!notp[i]){
            //标记 i 的所有倍数（从 i*i 开始，更小的倍数已被更小的素数筛过）
            for (int j=i*i;j<=n;j+=i){
                notp[j]=true;
            }
        }
    }

    vector<int> res;
    for (int i=2;i<=n;i++){
        if (!notp[i]) res.push_back(i);
    }
    return res;
}

//方法三：欧拉筛(每个合数只被它的最小素因子筛一次，避免重复标记)
vector<int> primesByEuler(int n){
    vector<bool> notp(n+1,false);
    vector<int> primes;

    for (int i=2;i<=n;i++){
        if (!notp[i]) primes.push_back(i);   //i 是素数

        //用已有素数去筛 i 的倍数
        for (int j=0;j<(int)primes.size()&&i*primes[j]<=n;j++){
            notp[i*primes[j]]=true;
            if (i%primes[j]==0) break;       //保证每个合数只被最小素因子筛掉
        }
    }
    return primes;
}

void printPrimes(const string& name,const vector<int>& p){
    cout<<name<<"共 "<<p.size()<<" 个: ";
    for (int x:p){
        cout<<x<<' ';
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    printPrimes("试除法  ",primesByTrial(n));
    printPrimes("埃氏筛  ",primesByEratosthenes(n));
    printPrimes("欧拉筛  ",primesByEuler(n));

    return 0;
}
