// 用于测试析构函数释放内存的顺序:
//1.函数内部的对象是局部对象，函数结束时便释放对象内存
//2.如果函数内部有多个对象，那么根据进出栈的顺序，后进先出，后定义的对象先释放
//3.在所有函数之外创建的对象是全局对象，它和全局变量类似，位于内存分区中的全局数据区，
//程序在结束执行时会调用这些对象的析构函数。
//4.new 创建的对象位于堆区，通过 delete 删除时才会调用析构函数；如果没有 delete，析构函数就不会被执行。
//5.static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。
//3) 静态成员变量必须初始化，而且只能在类体外进行。例如：
//int Student::m_total = 10;初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0。
//全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。

#include <iostream>
#include <string>
using namespace std;
class Demo{
public:
    Demo(string s);
    ~Demo();
private:
    string m_s;
};
Demo::Demo(string s): m_s(s){ }
Demo::~Demo(){ cout<<m_s<<endl; }
void func(){
    //局部对象
    Demo obj1("1");
}
//全局对象
Demo obj2("2");
int main(){
    //局部对象
    Demo obj3("3");
    Demo obj5("5");
    //new创建的对象
    Demo *pobj4 = new Demo("4");
    func();
    cout<<"main"<<endl;
  
    return 0;
}