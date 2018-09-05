#include <iostream>
using namespace std;

class A{
public:
  void show(){cout << "A show" << endl;}
};
template<typename T>
class Iterator_1{
public:
  typedef T value_type;
  typedef value_type* ptn;
  typedef value_type& ref;
};
template<typename T>
class Iterator_2{
public:
  typedef T value_type;
  typedef value_type* ptn;
  typedef value_type& ref;
};

template<typename T>
struct Traits{};

template<typename T>
struct Traits<T *>{
  typedef T value_type;
  typedef value_type* ptn;
  typedef value_type& ref;
};

int main(){
  Iterator_1<int>::value_type t1 = 100;
  cout << t1 << endl;
  Iterator_2<double>::value_type t2 = 1.23;
  cout << t2 << endl;
  Traits<double*>::value_type t3 = 4.45;
  cout << t3 << endl;

  Iterator_1<A>::ptn p;
  p->show();
}
