//设计立方体类，求出立方体的面积和体积，用全局函数和成员函数判断两个立方体是否相等
#include <iostream>
using namespace std;

class cube{
    public:
        void seth(double h){
            m_h=h;
        }
        void setl(double l){
            m_l=l;
        }
        void setw(double w){
            m_w=w;
        }
        // 表面积
        double area() const {
            return 2 * (m_l * m_w + m_l * m_h + m_w * m_h);
        }
        // 体积
        double volume() const {
            return m_l * m_w * m_h;
        }
        // 获取私有成员的只读接口，便于类外比较
        double getH() const { return m_h; }
        double getL() const { return m_l; }
        double getW() const { return m_w; }
        // 成员函数版：判断两个立方体是否相等
        bool jdcude(const cube &c2) const {  //已知c1，只需传c2
            return (m_h == c2.m_h) && (m_l == c2.m_l) && (m_w == c2.m_w);
        }
    private:
        double m_h;
        double m_l;
        double m_w;
};

// 全局函数版：通过公共接口判断两个立方体是否相等
bool isSame(const cube& a, const cube& b){
    return (a.getH() == b.getH()) && (a.getL() == b.getL()) && (a.getW() == b.getW());
}

int main(){
    cube c1;
    c1.seth(3);
    c1.setl(4);
    c1.setw(5);

    cube c2;
    c2.seth(3);
    c2.setl(3);
    c2.setw(5);

    cout << "c1 的表面积为：" << c1.area() << endl;
    cout << "c1 的体积为：" << c1.volume() << endl;
    //三目表达式
    cout << (c1.jdcude(c2) ? "成员函数：两个立方体相同" : "成员函数：两个立方体不相同") << endl;
    cout << (isSame(c1, c2) ? "全局函数：两个立方体相同" : "全局函数：两个立方体不相同") << endl;
}