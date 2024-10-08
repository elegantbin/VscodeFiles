// 本例定义了两个类 Student 和 Address，
// 程序第 27 行将 Student 类的成员函数 show() 声明为 Address 类的友元函数，
// 由此，show() 就可以访问 Address 类的 private 成员变量了。

// 几点注意：
// ① 程序第 4 行对 Address 类进行了提前声明，是因为在 Address 类定义之前、在 Student 类中使用到了它，
// 如果不提前声明，编译器会报错，提示'Address' has not been declared。类的提前声明和函数的提前声明是一个道理。

// ② 程序将 Student 类的声明和实现分开了，而将 Address 类的声明放在了中间，
// 这是因为编译器从上到下编译代码，show() 函数体中用到了 Address 的成员 province、city、district
// ，如果提前不知道 Address 的具体声明内容，
// 就不能确定 Address 是否拥有该成员（类的声明中指明了类有哪些成员）。

// ③ 一个函数可以被多个类声明为友元函数，这样就可以访问多个类中的 private 成员。

// 关于友元，有两点需要说明：
// 友元的关系是单向的而不是双向的。如果声明了类 B 是类 A 的友元类，不等于类 A 是类 B 的友元类，
// 类 A 中的成员函数不能访问类 B 中的 private 成员。
// 友元的关系不能传递。如果类 B 是类 A 的友元类，类 C 是类 B 的友元类，不等于类 C 是类 A 的友元类。

#include <iostream>
using namespace std;
class Address;  //提前声明Address类
//声明Student类
class Student{
public:
    Student(char *name, int age, float score);
public:
    void show(Address *addr);
private:
    char *m_name;
    int m_age;
    float m_score;
};
//声明Address类
class Address{
private:
    char *m_province;  //省份
    char *m_city;  //城市
    char *m_district;  //区（市区）
public:
    Address(char *province, char *city, char *district);
    //将Student类中的成员函数show()声明为友元函数
    friend void Student::show(Address *addr);
};
//实现Student类
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
void Student::show(Address *addr){
    cout<<m_name<<"的年龄是 "<<m_age<<"，成绩是 "<<m_score<<endl;
    cout<<"家庭住址："<<addr->m_province<<"省"<<addr->m_city<<"市"<<addr->m_district<<"区"<<endl;
}
//实现Address类
Address::Address(char *province, char *city, char *district){
    m_province = province;
    m_city = city;
    m_district = district;
}
int main(){
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);
   
    Student *pstu = new Student("李磊", 16, 80.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu -> show(paddr);
    return 0;
}