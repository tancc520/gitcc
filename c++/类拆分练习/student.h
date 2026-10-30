// student.h：只放类的声明（成员变量的属性 + 成员函数的声明）
#pragma once
#include <iostream>
#include <string>
using namespace std;

class student{
    public:
        // 行为：设置姓名、年龄
        void setname(string name);
        void setage(int age);

        // 行为：获取姓名、年龄（只读接口）
        string getname() const;
        int getage() const;

        // 行为：打印学生信息
        void show() const;

    private:
        // 属性：姓名、年龄（私有，类外不能直接访问）
        string m_name;
        int m_age = 0;
};
