// const 成员变量的用法和普通 const 变量的用法相似，只需要在声明时加上 const 关键字。
// 初始化 const 成员变量只有一种方法，就是通过构造函数的初始化列表
// 必须在成员函数的声明和定义处同时加上 const 关键字
// 函数开头的 const 用来修饰函数的返回值，表示返回值是 const 类型，也就是不能被修改，
// 例如const char * getname()。
// 函数头部的结尾加上 const 表示常成员函数，这种函数只能读取成员变量的值，而不能修改成员变量的值，
// 例如char * getname() const

#include <iostream>
using namespace std;
class Student{
public:
    Student(char *name, int age, float score);
public:
    void show();
    char *getname() const;
    int getage() const;
    float getscore() const;
private:
    char *m_name;
    int m_age;
    float m_score;
};
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
char * Student::getname() const{
    return m_name;
}
int Student::getage() const{
    return m_age;
}
float Student::getscore() const{
    return m_score;
}
int main(){
    const Student stu("小明", 15, 90.6);
    //stu.show();  //error
    cout<<stu.getname()<<"的年龄是"<<stu.getage()<<"，成绩是"<<stu.getscore()<<endl;
    const Student *pstu = new Student("李磊", 16, 80.5);
    //pstu -> show();  //error
    cout<<pstu->getname()<<"的年龄是"<<pstu->getage()<<"，成绩是"<<pstu->getscore()<<endl;
    return 0;
}