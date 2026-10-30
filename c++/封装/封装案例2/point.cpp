#include "point.h"

    void point::setx(int x){
        m_x=x;
    }
    void point::sety(int y){
        m_y=y;
    }
    int point::getx() const{return m_x;}
    int point::gety() const{return m_y;}
    // 返回两点间距离的平方：直接用乘法，避免 pow 返回 double 转 int 的精度隐患
    int point::distance(int x,int y) const{
        int dx = m_x - x;
        int dy = m_y - y;
        return dx*dx + dy*dy;
    } 
