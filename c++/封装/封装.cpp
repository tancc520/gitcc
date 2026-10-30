#include <iostream>
using namespace std;
#include <string>

//class类的简单使用
/*
class Student{
    public:   //公共权限   
        //类中的属性和行为统一称为成员
        string m_name;
        int m_ID;
        void show(){
            std::cout<<"姓名为："<<m_name<<std::endl;
            std::cout<<"学号为:"<<m_ID<<std::endl;
        }
        void setname(string name){
            m_name=name; 
        }
        void setID(int ID){
            m_ID=ID;
        }
};

int main(){
    Student student;
} */

//public private protected 的区别
/*
//公共权限 public 成员类内和类外都可以访问
//保护权限 protected 类内可以访问 ，类外不可以访问  ：子级可以访问
//私有权限 private 类内可以访问 ，类外不可以访问     ：子级不可以访问

class person{
    public:
        string name;
    protected:
        string m_car;
    private:
        int password;
    
    public:
        void func(){
            name="zhangsan";
            m_car="宝马";
            password=8491374;
        }

};

int main(){
    person p1;
    p1.name="张三";
    // p1.m_car,p1.password在类外访问不到

} */

//class和struct的区别
/*
//struct与class的区别:
//struct 默认权限为公共，class默认权限为私有
class c1{
    int a1;
};
struct c2{
    int a2;
};

int main(){
    c1 dada;
    c2 dede;
    dada.a1=100;  //class默认权限为私有 因此不能访问dada.a1
    dede.a2=100;     

}
*/

//成员属性设为私有  可以自己控制读写权限，对于写可以检测数据有效性
/*
class person{
public:
    //设置姓名
    void setname(string name){
        m_name=name;
    }
    //获取姓名
    string getname(){
        return m_name;
    }
    //获取年龄
    int getage(){
        return m_age;
    }
    //设置idol
    void setidol(){
        m_idol="wyf";
    }
    void setage(int age){
        if (m_age>150 || m_age<0){
            cout<<"年龄输入有误，请重新输入"<<endl;
            return;
        }
        m_age=age;
    }
private:
    string m_name; //可读可写
    
    int m_age=18; //只读  可写（在0-150之间）
    
    string m_idol; //只写
};

int main(){
    person p1;
    p1.setname("zhangsan");
    cout<<"姓名为："<<p1.getname()<<endl;
    cout<<"年龄为："<<p1.getage()<<endl;

}
*/
