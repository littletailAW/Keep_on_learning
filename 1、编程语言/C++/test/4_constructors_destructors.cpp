/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-01 02:28:53
 * @LastEditTime: 2021-03-01 03:14:41
 */
#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 *                          构造函数和析构函数
 * 1、构造函数：创建对象时对对象的成员属性的赋值 系统自动调用
 *       语法：类名(){}  不写void
 *       1、函数名和类名相同
 *       2、可以有参数 可以重载
 *       3、调用对象时系统自动调用 
 * 分类： 
 *        1、参数：有参构造   无参构造
 *        2、普通构造  拷贝构造(浅拷贝)
 * 调用方式:
 *        1、括号
 *        2、显示
 *        3、隐式转换
 * 拷贝构造：调用情况 
 *        1、用一个已经创建好的对象初始化新对象  Person p1; Person p2(p1);
 *        2、值转递的方式给参数传值
 *        3、以值的方式返回局部变量
 * 构造函数调用规则：
 *        1、定义有参构造 系统不提供无参 但提供拷贝
 *        2、定义拷贝  不提供构造
 * 深拷贝和浅拷贝
 *      浅拷贝:赋值  (默认拷贝)
 *      深拷贝：申请空间 进行拷贝
 * 注意：
 *      1、调用无参构造时不要用()  编译器会识别为一个函数声明
 * 2、析构函数：对象销毁前系统自动调用 清理数据
 *       语法：~类名(){}   不写void
 *       1、函数名和类名相同前面加 ~
 *       2、不可以有参数不可以重载
 *       3、对象销毁前系统自动调用
*******************************************************************************/
class Person
{
public:
    Person() //无参构造函数(默认)
    {
        cout << "Person()" << endl;
    }
    Person(int a) //有参构造函数
    {
        cout << "Person(int a)" << endl;
    }
    Person(const Person &a) //拷贝构造函数
    {
        m_age = a.m_age; //将传入的 拷贝到 自己
        cout << "Person(const Person &a)" << endl;
    }

    ~Person() //析构函数
    {
        cout << "~Person()" << endl;
    }

private:
    int m_age;
};
void test()
{
    Person p1;
}
void test1()
{
    //1、括号
    Person p1;     //调用无参构造
    Person p2(10); //调用有参构造
    Person p3(p2); //调用拷贝构造
    //2、显示
    Person p4;              //调用无参构造
    Person p5 = Person(10); //调用有参构造   Person(10)匿名对象 执行完马上被释放
    Person p6 = Person(p2); //调用拷贝构造
    //3、隐式转换
    Person p7 = 10; //Person p7 = Person(10);
    Person p8 = p7; //调用拷贝
}
int main(int argc, char *argv[])
{
/* 1、认识构造和析构*/
#if 0
    Person p1; //创建一个对象自动调用构造函数 Person()
    test();    //栈中创建对象 函数执行完 系统销毁 自动调用析构函数 Person() ~Person()
#endif
    system("pause");
    return 0;
}