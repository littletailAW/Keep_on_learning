/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-05 23:23:46
 * @LastEditTime: 2021-03-05 23:44:00
 */
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*******************************************************************************
 * 虚析构和纯虚析构
 * 1.作用：当多态中 子类的属性开辟到堆内存 父类指针在释放时候无法调用子类析构 会造成内存泄漏
 *   通过虚析构和纯虚析构解决
 * 2.两者的相同点
 *   解决父类指针无法释放子类对象
 *   需要具体的函数实现
 * 3.两者的不同点
 *   纯虚析构 是抽象类 无法实例化对象
 * 4.语法
 *   虚析构：virtual ~类名(){}
 *   纯虚析构：virtual ~类名()=0；
 * 
*******************************************************************************/
class Aniaml
{
public:
    Aniaml()
    {
        cout << "Aniaml的构造" << endl;
    }
/* 虚析构*/
#if 0
    virtual ~Aniaml()
    {
        cout << "Aniaml的析构" << endl;
    }
#endif
    /* 纯虚析构*/
    virtual ~Aniaml() = 0;
    virtual void sperk() = 0;
};
Aniaml::~Aniaml()
{
    cout << "Aniaml的析构" << endl;
}

class cat : public Aniaml
{
public:
    cat(string name)
    {
        cout << "cat的构造" << endl;

        m_name = new string(name);
    }
    virtual void sperk()
    {
        cout << *m_name << "猫在说话" << endl;
    }
    ~cat()
    {
        if (NULL != m_name)
        {
            cout << "cat的析构" << endl;
            delete m_name;
            m_name = NULL;
        }
    }
    string *m_name;
};
void test1()
{
    Aniaml *a = new cat("tom");
    a->sperk();
    delete a; //父类调用析构 子类不会 会造成内存泄漏 解决方法 在父类析构变为虚析构
}
int main(int argc, char *argv[])
{
    test1();
    system("pause");
    return 0;
}