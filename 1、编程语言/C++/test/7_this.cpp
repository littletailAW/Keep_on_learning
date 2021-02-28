/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-01 03:40:25
 * @LastEditTime: 2021-03-01 03:46:58
 */

#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 *                             this指针
 *this指针：指向被调用的成员函数所属的对象
 *1、当形参和成员变量同名时 this解决冲突
 *2、this返回对象本身
 * 
 * 
 * ****************************************************************************/

class SS
{
public:
    SS(int age)
    {
        this->age = age;
    }
    SS &test(SS s)
    {
        this->age += s.age;
        return *this;
    }
    int age;
};

int main(int argc, char *argv[])
{

    system("pause");
    return 0;
}