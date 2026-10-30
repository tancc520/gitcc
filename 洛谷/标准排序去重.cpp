#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    
    /*
    unique(begin, end) 的前提是区间已排序。它把相邻重复的元素移到末尾，
    返回最后一个不重复元素的后一个位置。

    unique 不会改变容器大小，只是把有效数据挪到前面，
    所以必须配合 erase 把末尾的无用元素真正删掉，a.size() 才是正确的去重后个数。*/
    sort(a.begin(),a.end());  //排序
    a.erase(unique(a.begin(),a.end()),a.end());  //去重
    
    cout<<a.size()<<'\n';
    for(int i=0;i<(int)a.size();i++){
        cout<<a[i]<<(i+1==(int)a.size()?'\n':' ');
    }
    return 0;
}