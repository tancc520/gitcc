// student.cpp：写 student 类中成员函数的具体实现
#include "student.h"

// 成员函数实现时要加作用域 student::
void student::setname(string name){
    m_name = name;
}

void student::setage(int age){
    m_age = age;
}

string student::getname() const{
    return m_name;
}

int student::getage() const{
    return m_age;
}

void student::show() const{
    cout << "姓名：" << m_name << "，年龄：" << m_age << endl;
}
