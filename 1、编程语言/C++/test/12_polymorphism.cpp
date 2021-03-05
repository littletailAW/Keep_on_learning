/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-05 14:40:43
 * @LastEditTime: 2021-03-06 00:06:26
 */
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
/*******************************************************************************
 * 多态
 * 1、概念
 *    两类:静态多态：也就是函数重载、运算符重载
 *         动态多态：派生类和虚函数
 *    区别：静态多态的函数地址 在编译阶段确定了
 *         动态多态 运行阶段
 * 2、动态多态的条件
 *    1.有继承
 *    2.子类重写父类虚函数 重写(函数返回值 名 参数都相同) virtual可加可不加
 * 3、动态多态的使用
 *    父类指针或引用 执向子对象
 * 4、多态原理
 *    虚函数指针vfptr指向虚函数表vftable(记录虚函数地址 作用域加虚函数) 继承后子类对父
 *    类中的虚函数等全部拷贝一份，当重写后子类中的虚函数表内部会替换成子类的虚函数地址
 * 5、多态优点
 *    1.代码结构清晰
 *    2.可读性强
 *    3.利于前后期维护
 * ****************************************************************************/
/* 静态多态和动态多态 */
#if 0
// 动态即虚函数
class Animal
{
public:
    /* 虚函数*/
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
class Cat : public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};
//执行说话的函数
//不加virtual时  在编译阶段就 确定了地址
//加virtual后 实现我们想要的
void do_speak(Animal &animal)
{
    animal.speak();
}
void test1()
{
    Cat c;
    /* 猫说话*/
    do_speak(c); //当没有加virtual时候 传进来猫实质是动物在说话
}
#endif
/******************************************************************************/
/* 多态案例*/
/* 通过普通实现和多态实现计算器 体验多态*/
/* 1、普通写法*/
#if 0
class Calculator
{
public:
    int get_res(string oper)
    {
        if (oper == "+")
            return m_num1 + m_num2;
        else if (oper == "-")
            return m_num1 + m_num2;
    }
    int m_num1;
    int m_num2;
};
void test2()
{
    Calculator c;
    c.m_num1 = 10;
    c.m_num2 = 20;
    cout << "num1+num2=" << c.get_res("+") << endl;
}
#endif
/* 2、多态实现 */
#if 0
class Calculator
{
public:
    virtual int get_res()
    {
        return 0;
    }
    int m_num1;
    int m_num2;
};
/* 加法类*/
class add : public Calculator
{
    virtual int get_res()
    {
        return m_num1 + m_num2;
    }
};
/* 减法类*/
class sub : public Calculator
{
    virtual int get_res()
    {
        return m_num1 - m_num2;
    }
};
void test3()
{
    Calculator *c = new add;
    c->m_num1 = 10;
    c->m_num2 = 10;
    cout << c->m_num1 << "+" << c->m_num2 << "= " << c->get_res() << endl;
    delete c;
}
#endif
/* 多态案例2*/
//给老师来一杯卡布奇诺
#if 0
class AbstractDrinking
{
public:
    /* 1.煮水*/
    virtual void boil() = 0;
    /* 2.冲泡*/
    virtual void brew() = 0;
    /* 3.倒入杯子里*/
    virtual void input_cap() = 0;
    /* 4.加入东西*/
    virtual void add_thing() = 0;
    /* 5.制作成品*/
    void make_drink()
    {
        boil();
        brew();
        input_cap();
        add_thing();
    }
};
//咖啡
class coffee : public AbstractDrinking
{
    virtual void boil()
    {
        cout << "煮矿泉水" << endl;
    }

    virtual void brew()
    {
        cout << "冲咖啡" << endl;
    }

    virtual void input_cap()
    {
        cout << "倒入杯子" << endl;
    }

    virtual void add_thing()
    {
        cout << "加入牛奶" << endl;
    }
};
//茶水
class tea : public AbstractDrinking
{
    virtual void boil()
    {
        cout << "煮矿泉水" << endl;
    }

    virtual void brew()
    {
        cout << "泡茶叶" << endl;
    }

    virtual void input_cap()
    {
        cout << "倒入杯子" << endl;
    }

    virtual void add_thing()
    {
        cout << "加入大枣" << endl;
    }
};
//制作
void do_drink(AbstractDrinking *abs)
{
    abs->make_drink();
    delete abs;
}
void test4()
{
    do_drink(new coffee);
    do_drink(new tea);
}
#endif
/* 多态案例3*/
#if 1
/* CPU*/
class CPU
{
public:
    //抽象的计算函数
    virtual void calculate() = 0;
};
/* 显卡*/
class Video
{
public:
    //抽象的显示函数
    virtual void display() = 0;
};
/* 内存条*/
class memory
{
public:
    //抽象的存储函数
    virtual void storage() = 0;
};

//电脑
class computer
{
public:
    computer(CPU *cpu, Video *vi, memory *mem)
    {
        m_cpu = cpu;
        m_vi = vi;
        m_mem = mem;
    }
    void work()
    {
        m_cpu->calculate();
        m_vi->display();
        m_mem->storage();
    }
    ~computer()
    {
        if (NULL != m_cpu)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        if (NULL != m_vi)
        {
            delete m_vi;
            m_vi = NULL;
        }
        if (NULL != m_mem)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }

private:
    CPU *m_cpu;
    Video *m_vi;
    memory *m_mem;
};
class inter_cpu : public CPU
{
    virtual void calculate()
    {
        cout << "inter cpu doing" << endl;
    }
};
class inter_vi : public Video
{
    virtual void display()
    {
        cout << "inter video doing" << endl;
    }
};
class inter_mem : public memory
{
    virtual void storage()
    {
        cout << "inter mem doing" << endl;
    }
};
void test5()
{
    CPU *intercpu = new inter_cpu;
    Video *intervideo = new inter_vi;
    memory *intermem = new inter_mem;

    computer *com = new computer(intercpu, intervideo, intermem);
    com->work();
    delete com;
}
#endif
int main(int argc, char *argv[])
{
    // test1();
    // test2();
    /* 多态案例1*/
    // test3();
    /* 多态案例2*/
    // test4();
    test5();
    system("pause");
    return 0;
}