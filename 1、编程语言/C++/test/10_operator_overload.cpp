/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-04 23:54:25
 * @LastEditTime: 2021-03-05 11:18:11
 */
#include <iostream>
#include <windows.h>
using namespace std;

/*******************************************************************************
 * 运算符符重载
 * 1、含义 
 *    通过对运算符的重载(重新定义)实现对自定义类型的操作(eg:对两个对象相加)对加号重载
 * 2、重载方式
 *    1.通过成员函数重载
 *    2.通过全局函数重载
 *    在这些基础上还可以 函数重载
 * 3、“+”对加号运算符重载
 *    1.Person operator+(Person &p)              成员函数实现
 *    2.Person operator+(Person &p1, Person &p2) 全局函数实现
 * 4、“<<”左移重载
 * 5、“++”重载
 * 6、“=”赋值重载
 * 7、关系运算符(== !=)
 * 8、()函数调用 仿函数 写法灵活多变
*******************************************************************************/
#if 0
class Person
{
public:
/* 1、通过成员函数重载加号“+” */
#if 0
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_a = this->m_a + p.m_a;
        temp.m_b = this->m_b + p.m_b;

        return temp;
    }
#endif
    int m_a;
    int m_b;
};
/* 2、全局函数实现“+”加号重载 */
#if 1
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.m_a = p1.m_a + p2.m_a;
    temp.m_b = p1.m_b + p2.m_b;

    return temp;
}
/* 函数重载*/
Person operator+(Person &p1, int num)
{
    Person temp;
    temp.m_a = p1.m_a + num;
    temp.m_b = p1.m_b + num;

    return temp;
}
#endif
/* 重载加号实现对两个对象相加*/
void test1()
{
    Person p1;
    p1.m_a = 10;
    p1.m_b = 20;
    Person p2;
    p2.m_a = 20;
    p2.m_b = 30;
    /* 成员函数重载的本质 */
    // Person p3 = p1.operator+(p2);
    /* 全局函数重载的本质 */
    // Person p3 = operator+(p1, p2);
    Person p3 = p1 + p2;
    // 函数重载
    Person p4 = p1 + 100;
    cout << "p3 a=" << p3.m_a << "\tb=" << p3.m_b << endl;
    cout << "p4 a=" << p4.m_a << "\tb=" << p4.m_b << endl;
}
#endif
/******************************************************************************/
#if 0
/* 重载左移运算符*/
ostream &operator<<(ostream &cout, Person &p) //operator(cout,p)
{
    cout << "a=" << p.m_a << "\tb=" << p.m_b;
    return cout;
}
/* 重载左移运算符实现cout打印自定义类型 */
void test2()
{
    Person p1;
    p1.m_a = 23;
    p1.m_b = 47;
    cout << p1 << endl;
}
#endif
/******************************************************************************/
#if 0
/* 重载++运算符 */
/* 通过实现一个自定义类型的的前置++后置++*/
class MY_int
{
    friend ostream &operator<<(ostream &cout, MY_int &p);
    //friend ostream &operator<<(ostream &cout, MY_int p);

public:
    MY_int()
    {
        m_num = 0;
    }
    /* 实现前置++ */
    MY_int &operator++()
    {
        /* 1、先自增 */
        m_num++;
        /* 2、再返回*/
        return *this;
    }
    /* 实现后置++ */
    MY_int operator++(int) //通过占位参数 实现重载
    {
        /* 1、先记录当前结果 */
        MY_int temp = *this;
        /* 2、自增 */
        m_num++;
        /* 3、返回记录值 */
        return temp;
    }

private:
    int m_num;
};
ostream &operator<<(ostream &cout, MY_int &p) //operator(cout,p)
{
    cout << "num=" << p.m_num;
    return cout;
}

/* 自定义类型的++测试 */
void test3()
{
    MY_int p;
    cout << ++p << endl; //前置
    cout << p << endl;
    cout << p++ << endl; //后置 注意后置时重载的<<不能用引用
    cout << p << endl;
}
#endif
/******************************************************************************/
#if 0
/* 赋值运算符重载 */
/* 实现对两个对象的赋值 */
class Person
{
public:
    Person(int age)
    {
        m_age = new int(age); //new在堆区 需要释放
    }
    ~Person()
    {
        if (NULL != m_age)
        {
            delete m_age;
            m_age = NULL;
        }
    }
    /* 重载赋值=运算符 */
    Person &operator=(Person &p)
    {
        /* 1、先释放内存 */
        if (NULL != m_age)
        {
            delete m_age;
            m_age = NULL;
        }
        /* 2、深拷贝 */
        m_age = new int(*p.m_age);
        return *this;
    }
    int *m_age;
};
void test4()
{
    Person p1(17);
    Person p2(20);
    cout << "p1的年龄\t" << *p1.m_age << endl;
    cout << "p2的年龄\t" << *p2.m_age << "\n " << endl;
    /* 在没有析构释放内存时 p2=p1直接赋值是可以的 浅拷贝 */
    /* 在有析构时 p2=p1直接赋值奔溃 原因重复释放内存 解决 深拷贝(拷贝构造或重载=) */
    p2 = p1;
    cout << "p1的年龄\t" << *p1.m_age << endl;
    cout << "p2的年龄\t" << *p2.m_age << "\n " << endl;
    Person p3(22);
    p3 = p2 = p1;
    cout << "p1的年龄\t" << *p1.m_age << endl;
    cout << "p2的年龄\t" << *p2.m_age << endl;
    cout << "p3的年龄\t" << *p3.m_age << endl;
}
#endif
/******************************************************************************/
#if 0
/* 重载==关系运算符 */
/* 实现对两个对象对比 */
class Person
{
public:
    Person(string name, int age)
    {
        m_name = name;
        m_age = age;
    }
    bool operator==(Person &p)
    {
        if (this->m_name == p.m_name && this->m_age == p.m_age)
            return true;
        else
            return false;
    }
    bool operator!=(Person &p)
    {
        if (this->m_name != p.m_name || this->m_age != p.m_age)
            return true;
        else
            return false;
    }
    string m_name;
    int m_age;
};
void test5()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    Person p3("jony", 18);

    if (p1 == p2)
        cout << "p1==p2" << endl;
    else
        cout << "p1!=p2" << endl;
    if (p1 != p3)
        cout << "p1!=p3" << endl;
    else
        cout << "p1==p3" << endl;
}
#endif
/******************************************************************************/
#if 1
/* 重载函数调用()运算符 */
/* 仿函数 很像函数调用*/

/* 实现打印输出 */
class My_printf
{
public:
    void operator()(string input)
    {
        cout << input << endl;
    }
};
class My_add
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};
void test6()
{
    My_printf p;
    p("welcome to china");
    My_add add;
    cout << add(10, 20) << endl;
    /* 匿名函数对象*/
    cout << My_add()(10, 20) << endl;
}
#endif
int main(int argc, char *argv[])
{
    // test1(); //重载+测试
    // test2(); //重载<<测试
    // test3(); //重载++测试
    // test4(); //重载=测试
    // test5(); //重载==、!=测试
    test6(); //重载==、!=测试

    system("pause");
    return 0;
}