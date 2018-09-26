#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class my_auto_ptr{
public:
  my_auto_ptr(T* p = nullptr):own(p!=nullptr),ptr(p){}
  ~my_auto_ptr(){
    if(own){
      delete ptr;
    }
  }
  T& operator*()const{
    return *ptr;
  }
  T* operator->()const{
    return ptr;
  }
private:
  bool own;
  T* ptr;
};
class Test{
public:
  void fun(){
    cout << "func()" << endl;
  }
};
int main(){
  //test1 老版本的auto_ptr的使用，现在不推荐使用
  /*
  int *p = new int(10);
  auto_ptr<int> pa(p);
  cout << *pa << endl;

  string* ps = new string("aaa");
  auto_ptr<string> pas(ps);
  cout << pas->size() << endl;
  */

  //test2 自己实现auto_ptr
  int *p = new int(11);
  my_auto_ptr<int> pa(p);
  //delete p;
  *pa = 111;
  cout << *pa << endl;
  cout << *p << endl;

  Test* pt = new Test;
  my_auto_ptr<Test> pa1(pt);
  pa1->fun();

  return 0;
}
