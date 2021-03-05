/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-05 11:29:55
 * @LastEditTime: 2021-03-05 14:39:39
 */
#include <iostream>
#include <windows.h>
using namespace std;
/*******************************************************************************
 * 继承
 * 1.概念 既有共性 也有特性 (一个菜单 然后又好多子菜单 子菜单又又好多子子菜单)
 * 2.语法 class 派生类(子类)：继承方式 (public private)+基类(父类)
 * 3.作用 提高代码复用性(减少重复代码)
 * 4.继承方式
 *   1.公有继承  子类中继承的成员属性 和 父类中成员属性 相同  私有无法访问
 *   2.私有继承  子类中继承的成员属性 公有变私有 保护变私有   私有无法访问
 *   3.保护继承  子类中继承的成员属性 公有变保护 保护还是保护 私有无法访问 
 * 5、继承后存储
 *   1.继承后 父类中所有非静态成员变量全部被子类继承(子类大小=父类大小+子类成员大小)
 * 6、继承后构造和析构顺序
 *    先构造父类 再构造子类 析构顺序与构造相反
 * 7、继承中同名成员处理方式
 *    访问子类同名成员 直接访问
 *    访问父类同名成员 加作用域
 *      1、静态和非静态访问方式一致(通过对象访问)
 *      2、静态还可以通过类名 访问子类中的Son::m_a  父类中的Son::Base::m_a
 * 8、多继承 继承多个
 *    语法：class 子类：继承方式 父类1，继承方式 父类2
 *    同名情况的话 加作用域即可
 * 9、菱形继承(钻石继承)
 *    具有相同成员 加作用域区分
 *    数据有多份  虚继承解决 继承方式前加virtual关键字 (一份数据)       
 *    两个父类继承下来是vbptr指针 通过指针偏移vbtable表        
 *            
 * 
*******************************************************************************/
/* 通过网页页面分类 抽象理解继承*/
#if 0
class MY_c
{
public:
    void header()
    {
        cout << "首页、公开课、收费课、资料 顶部" << endl;
    }
    void info()
    {
        cout << "c/c++、python、java..." << endl;
    }
    void content()
    {
        cout << "这是c/c++" << endl;
    }
    void end()
    {
        cout << "帮助、设置、咨询..." << endl;
    }
};
class MY_java
{
public:
    void header()
    {
        cout << "首页、公开课、收费课、资料 顶部" << endl;
    }
    void info()
    {
        cout << "c/c++、python、java..." << endl;
    }
    void content()
    {
        cout << "这是java" << endl;
    }
    void end()
    {
        cout << "帮助、设置、咨询..." << endl;
    }
};
/* 他们两个类 只有一个地方不同 没必要把前面相同的在定义*/
/* 继承实现*/
class MY_base //相同的
{
public:
    void header()
    {
        cout << "首页、公开课、收费课、资料 顶部" << endl;
    }
    void info()
    {
        cout << "c/c++、python、java..." << endl;
    }
    void end()
    {
        cout << "帮助、设置、咨询..." << endl;
    }
};
class MY_C : public MY_base //继承相同的
{
public:
    void content()
    {
        cout << "这是c" << endl;
    }
};
class MY_JAVA : public MY_base //继承相同的
{
public:
    void content()
    {
        cout << "这是java" << endl;
    }
};

void test1()
{
    MY_c c;
    cout << "c/c++如下" << endl;
    c.header();
    c.info();
    c.content();
    c.end();
    MY_java j;
    cout << "JAVA如下" << endl;
    j.header();
    j.info();
    j.content();
    j.end();
}
void test2()
{
    MY_C c;
    cout << "c/c++如下" << endl;
    c.header();
    c.info();
    c.content();
    c.end();
    MY_JAVA j;
    cout << "JAVA如下" << endl;
    j.header();
    j.info();
    j.content();
    j.end();
}
#endif
/******************************************************************************/
/* 继承方式 */
#if 0
/* 1、公有继承 */
class Base
{
public:
    int m_a;

protected:
    int m_b;

private:
    int m_c;
};
class Son1 : public Base1
{
public:
    void fun()
    {
        m_a = 10; //父类公有成员 子类还是 公有
        m_b = 10; //父类保护成员 子类还是 保护
        // m_c=10;//父类私有成员 子类无法访问 类内
    }
};
void test3()
{
    Son1 s1;
    s1.m_a = 10;
    //  s1.m_b = 12;// 父类保护成员  子类外无法访问 类内可以
    //  s1.m_c = 12;// 父类私有成员  子类内外都无法访问
}
/* 2、保护继承 */
class Son2 : protected Base
{
public:
    void fun()
    {
        m_a = 10; //父类公有成员 子类变为 保护
        m_b = 10; //父类保护成员 子类还是 保护
        // m_c=10;//父类私有成员 子类无法访问 类内
    }
};
void test4()
{
    Son2 s2;
    //  s2.m_a = 10;// 父类公有成员在子类中变为保护  子类外无法访问 类内可以
    //  s2.m_b = 12;// 父类保护成员  子类外无法访问 类内可以
    //  s2.m_c = 12;// 父类私有成员  子类内外都无法访问
}
/* 2、私有继承 */
class Son3 : private Base
{
public:
    void fun()
    {
        m_a = 10; //父类公有成员 子类变为 私有
        m_b = 10; //父类保护成员 子类还是 私有
        // m_c=10;//父类私有成员 子类内外都无法访问
    }
};
void test5()
{
    Son3 s3;
    //  s3.m_a = 10;// 父类公有成员在子类中变为私有  子类外无法访问 类内可以
    //  s3.m_b = 12;// 父类保护成员在子类中变私有    子类外无法访问 类内可以
    //  s3.m_c = 12;// 父类私有成员  子类内外都无法访问
}
#endif
/******************************************************************************/
/* 继承后的构造和析构的顺序 */
#if 0
class Base
{
public:
    Base()
    {
        cout << "base 构造" << endl;
    }
    ~Base()
    {
        cout << "base 析构" << endl;
    }
};
class Son1 : public Base
{
public:
    Son1()
    {
        cout << "Son1 构造" << endl;
    }
    ~Son1()
    {
        cout << "Son1 析构" << endl;
    }
};
void test6()
{
    // Base b;
    Son1 s;
}
#endif
/******************************************************************************/
/* 继承后同名成员处理方式 */
#if 0
class Base
{
public:
    Base()
    {
        m_a = 100;
    }
    void fun()
    {
        cout << "Base fun()" << endl;
    }
    int m_a;
};
class Son : public Base
{
public:
    Son()
    {
        m_a = 200;
    }
    void fun()
    {
        cout << "Son fun()" << endl;
    }
    int m_a;
};
/* 同名的成员属性*/
void test7()
{
    Son s;
    /* 子类直接访问 是自己的*/
    cout << "son =" << s.m_a << endl;
    /* 子类加作用域访问父类中的*/
    cout << "base =" << s.Base::m_a << endl;
}
/* 同名的成员函数*/
void test8()
{
    Son s;
    /* 子类直接访问 是自己的*/
    s.fun();
    /* 子类加作用域访问父类中的*/
    s.Base::fun();
}
#endif
/******************************************************************************/
/* 多继承*/
#if 0
class Base1
{
public:
    Base1()
    {
        m_a = 100;
    }
    void fun()
    {
        cout << "Base1 fun()" << endl;
    }
    int m_a;
};
class Base2
{
public:
    Base2()
    {
        m_a = 200;
        m_b = 200;
    }
    void fun()
    {
        cout << "Base2 fun()" << endl;
    }
    int m_b;
    int m_a;
};
/* 子类继承两个父类*/
class Son : public Base1, public Base2
{
public:
    Son()
    {
        m_b = 200;
    }
    int m_c;
};
void test9()
{
    Son s;
    /* 出现同名时 加作用域*/
    cout << "base1的a= " << s.Base1::m_a << endl;
    cout << "base2的a= " << s.Base2::m_a << endl;
}
#endif
/******************************************************************************/
/* 菱形继承 */
class Animal
{
public:
    int m_age;
};
/* 羊*/
class Sheep : virtual public Animal
{
public:
};
/* 骆驼*/
class Tuo : virtual public Animal
{
public:
};
/* 羊驼*/
class Sheep_Tuo : public Sheep, public Tuo
{
public:
};
void test10()
{
    Sheep_Tuo st;
    //两个父类有相同的属性 加作用域区分
    // st.m_age = 100;//没加虚继承前不可以 因为有多个数据
    st.Sheep::m_age = 18;
    st.Tuo::m_age = 28;
    cout << "sheep = " << st.Sheep::m_age << endl;
    cout << "tuo = " << st.Tuo::m_age << endl;

    //我们只需要一个数据 利用虚继承 之后只会有一份数据
    st.m_age = 100;
    cout << "sheeptuo = " << st.m_age << endl;
    cout << "sheep = " << st.Sheep::m_age << endl;
    cout << "tuo = " << st.Tuo::m_age << endl;
}
int main(int argc, char *argv[])
{
#if 0
    /* 理解继承*/
    test1();
    test2();
#endif
#if 0
    /* 构造析构顺序*/
    test6();
#endif
#if 0
    /* 同名成员处理方式*/
    test7();
    test8();
#endif
#if 0
    /* 多继承*/
    test9();

#endif
#if 1
    /* 菱形继承*/
    test10();

#endif
    system("pause");
    return 0;
}