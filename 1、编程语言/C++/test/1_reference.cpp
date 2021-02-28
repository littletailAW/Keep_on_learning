/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-02-28 19:27:15
 * @LastEditTime: 2021-02-28 22:02:05
 */
#include <iostream>
#include <windows.h>
using namespace std;

/*             
*                 引用               (变量的别名)实质操作地址
*
*  语法： 数据类型 &别名 =原名
*  eg:   int a = 10; int &b = a;     b是a的引用
*
*  注意：1、引用必须初始化  int &b = a；
*       2、初始化后不可以再做其他变量的引用 
*       eg； int c=10; int &b=c; (前面已经是a的引用了) 
*
*  作用: 1、做函数参数     简化指针修改实参
*       2、作为函数返回值  调用函数可以作为左值 注意：不要返回局部变量
*  本质：引用的实现就是     指针常量  int* const a=&b;
*
*  常量引用：void test(const int &a);
*  作用：    修饰形参 防止实参被修改
*/

/* 1、引用做函数参数*/
void my_swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
/* 2、引用做函数返回值*/
//不要返回局部变量的引用
int &test1()
{
    int a = 10; //在栈中
    return a;
}
//调用函数作为左值
int &test2()
{
    static int a = 20; //在全局区中
    return a;
}
int main(int argc, char *argv[])
{
#if 0
    int a = 10;
    int &b = a;

    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    // ↑ 输出 a =10 b=10

    b = 20;
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    // ↑ 输出 a =20 b=20
#endif
#if 0
    int a = 10, b = 20;
    //↓  输入 a=10  b=20
    my_swap(a, b);
    cout << "a =" << a << endl;
    cout << "b =" << b << endl;
    // ↑ 输出 a =20 b=10
#endif
#if 1
    int &a = test2();
    cout << "a =" << a << endl; //输出 a=20
    test2() = 99;
    cout << "a =" << a << endl; //输出 a=99

#endif
    system("pause");
    return 0;
}