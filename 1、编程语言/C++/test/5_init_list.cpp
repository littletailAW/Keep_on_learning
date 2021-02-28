/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-01 03:19:47
 * @LastEditTime: 2021-03-01 03:25:52
 */

#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 *                              初始化列表
 * 语法：构造函数():属性1(值1) 属性2(值2) {}
 * 
 * 
 * ****************************************************************************/

class CH
{
public:
    CH(int a, int b, int c) //传统初始化
    {
        m_a = a;
        m_b = b;
        m_c = c;
    }
    CH(int a, int b, int c) : m_a(10), m_b(20), m_c(30) //初始化列表项
    {
    }
    int m_a;
    int m_b;
    int m_c;
};
int main(int argc, char *argv[])
{
    system("pause");
    return 0;
}