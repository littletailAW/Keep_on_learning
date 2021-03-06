/*
 * @Descripttion: 
 * @version: 0.0
 * @Author: Littletail
 * @Date: 2021-03-06 00:15:45
 * @LastEditTime: 2021-03-06 00:28:18
 */
#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;
/*******************************************************************************
 * 文件操作
 * 文件类型 二进制和文本文件
 * 1.加头文件<fstream>
 * 2.opt 
 *   1.ofstream 写
 *   2.ifstream 读
 *   3.fstream 读写
 * 3.写文件流程
 *   1.包含头文件 #include<fstream>
 *   2.创建流对象 ofstream ofs
 *   3.打开文件   ofs.open(”文件路径"，打开方式)
 *   4.写数据     ofs<<"写入数据"
 *   5.关闭文件   ofs.close()
 * 4.打开方式   可以通过|操作符 使用多个
 *   ios::in   为读文件而打开文件
 *   ios::out  为写文件而打开文件
 *   ios::ate  初始位置：文件尾
 *   ios::app  追加方式写文件
 *   ios::trunc 如果文件存在先删除再创建
 *   ios::binart 二进制方式
 * ****************************************************************************/
void test1()
{
    /* 1、创建流对象 */
    ofstream ofs;
    /* 2、指定文件路径及打开方式 */
    ofs.open("test.txt", ios::out);
    /* 3、写入内存 */
    ofs << "哈哈哈哈" << endl;
    /* 4、关闭文件 */
    ofs.close();
}
int main(int argc, char *argv[])
{
    test1();
    system("pause");
    return 0;
}