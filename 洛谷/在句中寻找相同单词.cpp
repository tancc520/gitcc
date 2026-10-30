#include <iostream>
#include <string>
using namespace std;

int main(){
    string word,text;
    cin>>word;
    cin.ignore();
    getline(cin,text);

    for (char &c:word)  c=tolower(c);
    for (char &c:text)  c=tolower(c);

    int n=text.size(),m=word.size();
    int cnt=0,first=-1;

    for (int i=0;i+m<=n;i++){
        if (text[i-1]!=' '&& i>0)continue;   //开头
        if (text[i+m]!=' '&& i+m!=n) continue;  //结尾
        if (text.compare(i,m,word)!=0) continue;  //句中
        cnt++;
        if (first==-1) first=i;
    }
    if (cnt==0)cout<<-1<<endl;
    else cout<<cnt<<' '<<first<<endl;

    return 0;
}