/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-05 20:54:39
 * @LastEditTime: 2021-03-05 22:50:33
 */
#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 * 纯虚函数和抽象类
 * 1、纯虚函数：多态中父类虚函数实现无意义 将虚函数改为纯虚函数
 * 语法：virtual 返回类型 函数名(参数)=0;
 * 2、抽象类 类中有纯虚函数故叫抽象类
 * 特点：无法实例化对象
 *      子类必须重写抽象类中的纯虚函数 否则也是抽象类
 * ****************************************************************************/
//抽象类 有纯虚函数
class Base
{
public:
    virtual void fun() = 0; //纯虚函数
};
class Son : public Base
{
public:
    virtual void fun()
    {
        cout << "fun()" << endl;
    }
};
void test1()
{
    /* 1、抽象类无法实例化对象*/
    //Base b;
    /* 2、子类必须重写抽象类中的纯虚函数 否则也是抽象类*/
    Son s;
    s.fun();
}
int main(int argc, char *argv[])
{
    test1();
    system("pause");
    return 0;
}