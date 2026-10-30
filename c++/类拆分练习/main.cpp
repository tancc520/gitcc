// main.cpp：程序入口，使用 student 类
#include "student.h"

int main(){
    // 实例化一个学生对象
    student s1;
    s1.setname("张三");
    s1.setage(18);

    // 通过公共接口访问私有属性
    cout << s1.getname() << " 今年 " << s1.getage() << " 岁" << endl;

    // 调用成员函数打印信息
    s1.show();

    return 0;
}
