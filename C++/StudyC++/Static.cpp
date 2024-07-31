// 总人数 m_total 和总成绩 m_points 由各个对象累加得到，必须声明为 static 才能共享；
// getTotal()、getPoints() 分别用来获取总人数和总成绩，为了访问 static 成员变量，我们将这两个函数也声明为 static。

// 在C++中，静态成员函数的主要目的是访问静态成员。getTotal()、getPoints() 当然也可以声明为普通成员函数，
// 但是它们都只对静态成员进行操作，加上 static 语义更加明确。

// 和静态成员变量类似，静态成员函数在声明时要加 static，在定义时不能加 static。
// const常量函数必须在成员函数的声明和定义处同时加上 const 关键字；
// inline内联函数只需要在函数定义的时候添加inline关键字，在函数声明时添加没有用但也不报错。
// 静态成员函数可以通过类来调用（一般都是这样做），也可以通过对象来调用，上例仅仅演示了如何通过类来调用。

// 静态成员函数与普通成员函数的根本区别在于：普通成员函数有 this 指针，可以访问类中的任意成员；
// 而静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。

#include <iostream>
using namespace std;
class Student{
public:
    Student(char *name, int age, float score);
    void show();
public:  //声明静态成员函数
    static int getTotal();
    static float getPoints();
private:
    static int m_total;  //总人数
    static float m_points;  //总成绩
private:
    char *m_name;
    int m_age;
    float m_score;
};
int Student::m_total = 0;
float Student::m_points = 0.0;
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score){
    m_total++;
    m_points += score;
}
void Student::show(){
    cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}
//定义静态成员函数
int Student::getTotal(){
    return m_total;
}
float Student::getPoints(){
    return m_points;
}
int main(){
    (new Student("小明", 15, 90.6)) -> show();
    (new Student("李磊", 16, 80.5)) -> show();
    (new Student("张华", 16, 99.0)) -> show();
    (new Student("王康", 14, 60.8)) -> show();
    int total = Student::getTotal();
    float points = Student::getPoints();
    cout<<"当前共有"<<total<<"名学生，总成绩是"<<points<<"，平均分是"<<points/total<<endl;
    return 0;
}