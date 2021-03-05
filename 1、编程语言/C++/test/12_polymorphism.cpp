/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-05 14:40:43
 * @LastEditTime: 2021-03-05 20:32:41
 */
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*******************************************************************************
 * 多态
 * 1、概念
 *    两类:静态多态：也就是函数重载、运算符重载
 *         动态多态：派生类和虚函数
 *    区别：静态多态的函数地址 在编译阶段确定了
 *         动态多态 运行阶段
 * 2、动态多态的条件
 *    1.有继承
 *    2.子类重写父类虚函数 重写(函数返回值 名 参数都相同) virtual可加可不加
 * 3、动态多态的使用
 *    父类指针或引用 执向子对象
 * 4、多态原理
 *    虚函数指针vfptr指向虚函数表vftable(记录虚函数地址 作用域加虚函数) 继承后子类对父
 *    类中的虚函数等全部拷贝一份，当重写后子类中的虚函数表内部会替换成子类的虚函数地址
 * 5、多态优点
 *    1.代码结构清晰
 *    2.可读性强
 *    3.利于前后期维护
 * ****************************************************************************/
/* 静态多态和动态多态 */
#if 0
// 动态即虚函数
class Animal
{
public:
    /* 虚函数*/
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};
//执行说话的函数
//不加virtual时  在编译阶段就 确定了地址
//加virtual后 实现我们想要的
void do_speak(Animal &animal)
{
    animal.speak();
}
void test1()
{
    Cat c;
    /* 猫说话*/
    do_speak(c); //当没有加virtual时候 传进来猫实质是动物在说话
}
#endif
/******************************************************************************/
/* 多态案例*/
/* 通过普通实现和多态实现计算器 体验多态*/
/* 1、普通写法*/
#if 0
class Calculator
{
public:
    int get_res(string oper)
    {
        if (oper == "+")
            return m_num1 + m_num2;
        else if (oper == "-")
            return m_num1 + m_num2;
    }
    int m_num1;
    int m_num2;
};
void test2()
{
    Calculator c;
    c.m_num1 = 10;
    c.m_num2 = 20;
    cout << "num1+num2=" << c.get_res("+") << endl;
}
#endif
/* 2、多态实现 */
class Calculator
{
public:
    virtual int get_res()
    {
        return 0;
    }
    int m_num1;
    int m_num2;
};
/* 加法类*/
class add : public Calculator
{
    virtual int get_res()
    {
        return m_num1 + m_num2;
    }
};
/* 减法类*/
class sub : public Calculator
{
    virtual int get_res()
    {
        return m_num1 - m_num2;
    }
};
void test3()
{
    Calculator *c = new add;
    c->m_num1 = 10;
    c->m_num2 = 10;
    cout << c->m_num1 << "+" << c->m_num2 << "= " << c->get_res() << endl;
    delete c;
}
int main(int argc, char *argv[])
{
#if 0
    test1();
#endif
    //  test2();
    test3();
    system("pause");
    return 0;
}