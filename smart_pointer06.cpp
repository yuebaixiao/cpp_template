#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test{
public:
  Test(int d = 0) : data(d){cout << "new" << data << endl;}
  ~Test(){cout << "del" << data << endl;}
  void func(){cout << "func" << endl;}
private:
  int data;
};

//test4 循环引用，导致即使是智能指针也不能释放内存
class teacher;
class student;
class teacher{
public:
  teacher(){cout << "teacher()" << endl;}
  ~teacher(){cout << "del teacher" << endl;}
  shared_ptr<student> stu;
};
class student{
public:
  student(){cout << "student()" << endl;}
  ~student(){cout << "del student" << endl;}
  //如果换成shared_ptr<teacher> tea;就会形成循环引用，导致内存泄漏
  weak_ptr<teacher> tea;
};
int main(){
  //test1 weak_ptr不增加引用计数
  /*
  shared_ptr<Test> sp1 = make_shared<Test>(1);
  cout << sp1.use_count() << endl;//1
  weak_ptr<Test> wp1 = sp1;
  cout << wp1.use_count() << endl;//1
  */

  //test2 weak_ptr没有->和*操作
  //wp1->func();
  //(*wp1).func();

  //test3 lock使用
  /*
  shared_ptr<int> sptr;
  sptr.reset(new int);
  *sptr = 10;
  weak_ptr<int> weak1 = sptr;
  sptr.reset(new int);
  *sptr = 5;
  weak_ptr<int> weak2 = sptr;
  // weak1 is expired!
  if(auto tmp = weak1.lock())
    cout << *tmp << '\n';
  else
    cout << "weak1 is expired\n";
  // weak2 points to new data (5)
  if(auto tmp = weak2.lock())
    cout << *tmp << '\n';
  else
    cout << "weak2 is expired\n";
  */

  //test4 循环引用，导致即使是智能指针也不能释放内存
  //用weak_ptr解决了循环引用，导致的内存不能释放的问题
  shared_ptr<teacher> tptr(new teacher);//计数器1
  shared_ptr<student> sptr(new student);//计数器1
  tptr->stu = sptr;//sptr的计数器2
  sptr->tea = tptr;//不增加tptr的引用计数,因为tea是weak指针
  cout << tptr.use_count() << endl;//1
  cout << sptr.use_count() << endl;//2

  return 0;
}
