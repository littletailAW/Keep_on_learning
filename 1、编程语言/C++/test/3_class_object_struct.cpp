/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-01 00:52:37
 * @LastEditTime: 2021-03-01 02:21:27
 */
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#define PI 3.14
/*******************************************************************************
 *                                  封装
 * 1、概念    将属性和行为作为一个整体，表现生活中的事物
 *            将属性和行为通过权限控制
 * 2、类class
 * 语法：class 类名{ 访问权限：属性或行为}； 属性 和 行为放在不同权限下 灵活控制
 *       class name{
 *          public:
 *              int a;      //属性
 *          public:
 *              void test();//行为 完成一件事情
 *          }
 * 访问权限：1、public          公有   类内可以 类外都可以访问
 *          2、protected       保护   类内可以 类外不可以
 *          3、private         私有   类内可以 类外不可以
 * 成员属性：一般设置为私有的(1、自己控制读写权限 2、写可以检测数据有效性)
 * 3、对象object
 * 概念：通过一个类(可以理解为一种类型) 创建的对象(变量或实体)
 * 4、struct和class区别  默认权限不同
 *    struct 默认权限为公共的
 *    class  默认权限为私有的
 * 
*******************************************************************************/
/* 1、通过求圆的周长的例子理解 类、对象*/
/* 定义一个类*/
class Circle
{
public:      //访问权限 公共的
    int m_r; //属性 圆的半径
public:
    double calculate() //行为 求圆的周长
    {
        return 2 * PI * m_r;
    }
};
/* 设计一个学生类 属性学号姓名*/
class Student
{
public:
    void show_student() //显示姓名和学号
    {
        cout << "name=" << m_name << "\tid=" << m_id << endl;
    }
    void set_name(string name) //设置姓名
    {
        m_name = name;
    }
    void set_id(int id) //设置学号
    {
        m_id = id;
    }

public:
    string m_name;
    int m_id;
};
/******************************************************************************/

int main(int argc, char *argv[])
{
    Circle c1; //通过类 创建一个对象(通过一个类型 定义一个该类型变量)
    c1.m_r = 10;
    cout << "calculate=" << c1.calculate() << endl; //62.8=2*3.14*10

    Student s1; //创建一个对象
    s1.set_id(1);
    s1.set_name("zhangsan");
    s1.show_student();

    system("pause");
    return 0;
}