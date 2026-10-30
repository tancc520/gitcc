#include "circle.h"

    void circle::setr(int r){
        m_r=r;
    }
    void circle::setct(point center){
        m_center=center;
    }
    int circle::getr() const {return m_r;}
    point circle::getcenter() const {return m_center;}