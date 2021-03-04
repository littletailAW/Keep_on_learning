/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-04 21:14:04
 * @LastEditTime: 2021-03-04 21:45:29
 */
#include <iostream>
#include <windows.h>
using namespace std;

/******************************************************************************
 * 1、常函数
 *   1.成员函数后加const  void show_person() const 
 *   2.对成员变量的值无法修改
 *   3.mutable修饰的成员可以修改 int m_b;//特殊变量  
 * 2、常对象
 *   1.在对象前加const 即为常对象     const Person p; 
 *   2.对成员无法修改  对mutable可以修改  同常函数 
 *   3.常对象只能调用常函数
 *
 * ****************************************************************************/
class Person
{
public:
    /* this指针本质 是一个指针常量  int *const this 指向不可以修改*/
    //在成员函数后加const this指针指向和值都不可以修改
    //也称为常函数
    void show_person() const //当这里加了const 相当于const int *const this
    {
        //m_a=100; 直接修改成员相当于 this->m_a=100;
        m_b = 100; //this->m_b
    }
    void fun()
    {
        m_a = 100;
    }
    int m_a;
    mutable int m_b; //特殊变量  常函数中  对加关键字mutable的变量 可以修改
};
void test()
{
    const Person p; //在对象前加const 即为常对象
    // p.m_a=100;不可以修改
    p.m_b = 100; //可以修改
    //p.fun(); 常对象不能调用普通成员函数(不允许修改属性)
    p.show_person(); //常对象 只能调用常变量
}
int main(int argc, char *argv[])
{
    system("pause");
    return 0;
}