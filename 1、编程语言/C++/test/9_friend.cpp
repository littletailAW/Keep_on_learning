/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-04 21:51:46
 * @LastEditTime: 2021-03-04 23:43:06
 */
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*******************************************************************************
 * 友元 
 *  1.目的 让一个函数或者类 访问别的类的私有成员(也就是让好朋友 看自己的宝贝)
 *  2.使用方式
 *    1.全局函数做友元  即可访问类中私有成员
 *      在需要访问的类中声明友元函数 eg:friend void good_friend(Build &build);
 *    2.类做友元
 *      在需要访问的类中声明友元类   eg:friend class Good_friend;  
 *    3.成员函数做友元
 *      在需要访问的类中声明其他类的成员函数为友元 eg:friend void Good_Gay::visit();      
 * ****************************************************************************/
//举一个好朋友访问自己家的例子
class Build;
class Good_Gay
{
public:
    Good_Gay();    //构造函数
    void visit();  //成员函数可以访问其他类的私有成员
    void visit1(); //不可以访问其他类的私有成员
    Build *building;
};
class Build
{
public:
    friend void good_friend(Build &build); //全局函数做友元函数
    friend class Good_friend;              //类做友元
    friend void Good_Gay::visit();         //声明友元函数

public:
    Build()
    {
        m_sitting_room = "客厅";
        m_bed_room = "卧室";
    }

public:
    string m_sitting_room; //客厅
private:
    string m_bed_room; //卧室
};

/* 1、全局函数做友元 */
void good_friend(Build &build)
{
    /* 1、普通函数(不声明为友元时)可以访问公有成员 不可以访问私有成员 */
    cout << "好朋友去" << build.m_sitting_room << endl;
    // cout << "好朋友去" << build.m_bed_room << endl;//error

    /* 2、作友元函数即可访问私有成员 */
    cout << "好朋友去" << build.m_bed_room << endl;
}
void test1()
{

    Build build;
    good_friend(build);
}
/******************************************************************************/
/* 2、做友元类*/
class Good_friend
{
public:
    Good_friend(); //构造函数
    void visit();
    Build *building;
};
/* 在类的外面声明构造函数 */
Good_friend::Good_friend()
{
    building = new Build; //指向堆区创建的对象
}
/* 成员函数外部定义 */
void Good_friend::visit()
{
    /* 1、类未声明为友元时 只能访问其他类公有的 私有的不可以*/
    cout << "好朋友去" << building->m_sitting_room << endl;
    //cout << "好朋友去" << building->m_bed_room << endl;//error

    /* 2、类声明为友元时 可以访问其他类私有的 */
    cout << "好朋友去" << building->m_bed_room << endl;
}
void test2()
{
    Good_friend p;
    p.visit();
}
/******************************************************************************/
/* 3、成员函数做友元*/

Good_Gay::Good_Gay()
{
    building = new Build; //指向堆区创建的对象
}
void Good_Gay::visit()
{
    /* 1、visit成员函数未声明为友元时 只能访问其他类公有的 私有的不可以*/
    cout << "好朋友去" << building->m_sitting_room << endl;
    //cout << "好朋友去" << building->m_bed_room << endl;//error

    /* 2、visit成员函数为友元时 可以访问其他类私有的 */
    cout << "好朋友去" << building->m_bed_room << endl;
}
void Good_Gay::visit1()
{
    /* 1、visit成员函数未声明为友元时 只能访问其他类公有的 私有的不可以*/
    cout << "好朋友去" << building->m_sitting_room << endl;
    //cout << "好朋友去" << building->m_bed_room << endl;//error
}
void test3()
{
    Good_Gay p1;
    p1.visit();  //可以访问私有
    p1.visit1(); //不可以访问私有
}

int main(int argc, char *argv[])
{
    // test1(); //全局函数做友元测试
    // test2(); //类做友元测试
    test3(); //成员函数做友元测试

    system("pause");
    return 0;
}