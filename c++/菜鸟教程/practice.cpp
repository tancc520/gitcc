#include <iostream>

class Base{
    public:
        static int class_var;
};

int Base::class_var=10;

void lei_bian_liang(){
    int class_var=9;
    std::cout<<class_var<<std::endl;
    std::cout<<Base::class_var<<std::endl;
}

//整数常量也可以带一个后缀，后缀是 U 和 L 的组合，U 表示无符号整数（unsigned），L 表示长整数（long）。
//后缀可以是大写，也可以是小写，U 和 L 的顺序任意。
int ao_te_man=10u;
int kjws=10l;

int er_jin_zhi=0x4b;

using namespace std;
int main(){
    cout<<"此为十六进制数(0x):"<<er_jin_zhi<<endl;
    return 0;   
}