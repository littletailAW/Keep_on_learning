/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-02-28 22:02:46
 * @LastEditTime: 2021-03-01 00:30:41
 */
#include <iostream>
#include <windows.h>
using namespace std;

/*                           函数
*  1、在C++中函数形参可以有默认值。void test(int a=10,b=20);
*     调用函数时如果有传入值用传入的 没有则用默认值
*     注意: 1、当某一个位置有默认参数 那么后面(左到右)的参数都必须有默认值 
*           test(int a,int b=20, c=30)//b有了默认之后的必须也有
*           2、函数声明和函数实现 只能由一个存在默认值 两种情况
*           声明test(int a,int b); 实现 test(int a=10,int b=20)
*           声明test(int a=10,int b=20); 实现 test(int a,int b)
*
*  2、函数形参 可以用来做占位 调用函数时必须填补占位
*      void fun(int a,int) 使用时必须填参 fun(10,10);
*     占位参数可以有默认值  void fun(int a,int=10);
*  
*  3、函数重载------函数名可以相同 复用
*     重载的条件：1、同一个作用域下
*                2、函数名相同
*                3、函数参数类型不同、个数不同、顺序不同 都可以
*     注意：1、函数返回值不可以作为重载条件
*           2、引用做函数重载 void fun(int &a) | void fun(const int &a)需要用时必须传常量
*           3、带有默认参数  void fun(int a,int b=10) |void fun(int a) 传一个参数报错 注意二义性
*/
/******************************************************************************/
/* 1、函数形参可以有默认值*/
int test(int a, int b = 20)
{
    return a + b;
}
/******************************************************************************/
/* 2、占位参数 也可以由默认参数*/
void test1(int a, int)
{
    cout << "dadwa" << endl;
}
/* 具有默认参数*/
void test2(int a, int = 10)
{
    cout << "dadwa" << endl;
}
/******************************************************************************/
/* 3、函数重载*/
void test3()
{
    cout << "test3(void)" << endl;
}
void test3(int a)
{
    cout << "test3(int a)" << endl;
}
void test3(int b, int a)
{
    cout << "test3(int b,int a)" << endl;
}
void test3(double a)
{
    cout << "test3(double a)" << endl;
}
/* 引用做重载条件*/
void fun(int &a)
{
    cout << "fun(int &a)" << endl;
}
void fun(const int &a)
{
    cout << "fun(const int &a)" << endl;
}
/* 具有默认参数*/
void fun1(int a, int b = 10)
{
    cout << "fun1(int a,int b)" << endl;
}
void fun1(int a)
{
    cout << "fun1(int a)" << endl;
}

int main(int argc, char *argv[])
{
#if 0
    cout << test(10, 30) << endl; //输出40
    cout << test(10) << endl;     //输出30
#endif
#if 0
    test1(10, 10); //调用时必须填满参数
    test2(10);     //有默认参数 可以不填
    test2(10, 10);
#endif
#if 0
    test3();       //输出test3(void)
    test3(10);     //输出test3(int)
    test3(10, 20); //输出test3(int b,int a)
    test3(7.123);  //test3(double a)
#endif
#if 0
    int a = 10;
    fun(a);  //fun(int &a)
    fun(10); //入参为常量即可 fun(const int &a)
#endif
#if 1
    // fun1(10); //传一个参数报错 二义性
    fun1(10, 20); //fun1(int a,int b=10)
#endif
    system("pause");
    return 0;
}