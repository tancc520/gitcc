#pragma once
#include <iostream>
using namespace std;

class point{
    public:
        void setx(int x);
        void sety(int y);
        int getx() const;
        int gety() const;
        // 返回两点间距离的平方：直接用乘法，避免 pow 返回 double 转 int 的精度隐患
        int distance(int x,int y) const;
    private:
        int m_x = 0;
        int m_y = 0;
};
