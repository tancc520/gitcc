
#pragma once
#include <iostream>
#include "point.h"
using namespace std;

class circle{
    public:
        void setr(int r);
        void setct(point center);
        int getr() const;
        point getcenter() const;
    private:
        int m_r = 0;
        point m_center;
};