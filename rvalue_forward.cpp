#include <iostream>
using namespace std;

void rvalue_call(int& v){
  cout << "& call" << endl;
}
void rvalue_call(int&& v){
  cout << "&& call" << endl;
}
void rvalue_call(const int& v){
  cout << "const & call" << endl;
}
void rvalue_call(const int&& v){
  cout << "const && call" << endl;
}

template<typename T>
void func(T&& a){
  rvalue_call(std::forward<T> (a));
}

int main(void){
  int x = 1;
  func(x);//实参为左值
  int& y = x;
  func(y);//实参为左值引用
  func(std::move(y));//实参为右值引用
  func(100);

  const int a = 11;
  func(a);
  func(std::move(a));
}
