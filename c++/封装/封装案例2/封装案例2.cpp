//计算点类和圆类的关系
#include <iostream>
#include <cmath>
#include "circle.h"
#include "point.h"
using namespace std;


// 点到圆心距离的平方 <= 半径的平方，说明点在圆内（<= 包含点在圆上的情况）
bool isincircle(const circle& c, const point& p){
    point center = c.getcenter();
    return p.distance(center.getx(), center.gety()) <= c.getr() * c.getr();
}

int main(){
    int x, y, r;

    // 1. 输入待判断的点
    cout << "请输入点的坐标 x y：";
    if (!(cin >> x >> y)){
        cout << "输入格式有误，请输入两个整数" << endl;
        return 1;
    }
    point p;
    p.setx(x);
    p.sety(y);

    // 2. 输入圆心
    cout << "请输入圆心坐标 x y： ";
    if (!(cin >> x >> y)){
        cout << "输入格式有误，请输入两个整数" << endl;
        return 1;
    }
    point ct;
    ct.setx(x);
    ct.sety(y);

    // 3. 输入半径，并校验合法性
    cout << "请输入圆的半径：";
    if (!(cin >> r) || r <= 0){
        cout << "半径必须是正整数" << endl;
        return 1;
    }

    circle c;
    c.setr(r);
    c.setct(ct);

    cout << (isincircle(c, p) ? "此点在圆内" : "此点在圆外") << endl;
}