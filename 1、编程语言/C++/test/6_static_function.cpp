/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-01 03:28:08
 * @LastEditTime: 2021-03-01 03:40:02
 */
#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 *                              静态成员函数
 * 静态成员变量：
 *     1、所有对象共享同一个数据
 *     2、编译阶段分配内存
 *     3、类内声明 类外初始化
 * 静态成员函数：
 *     1、所有对象共享同一个函数
 *     2、静态成员函数只能访问静态成员变量
 * 访问方式：
 *     1、ss1.func(); //通过对象访问
 *     2、SS::func(); //通过类名访问
 * 成员变量成员函数分开存储
 *     非静态成员变量 占内存
 *     静态不占
 * ****************************************************************************/

class SS
{
public:
    static void func() //静态成员函数
    {
        m_a = 100;
        cout << "static fun()" << endl;
    }
    static int m_a; //静态成员变量
};
int SS::m_a = 0;
void test()
{
    SS ss1;
    ss1.func(); //通过对象访问
    SS::func(); //通过类名访问
}
int main(int argc, char *argv[])
{
    test();
    system("pause");
    return 0;
}