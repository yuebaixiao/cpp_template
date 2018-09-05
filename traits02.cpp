#include <iostream>
using namespace std;

/*
template<typename _A1, typename _A2, typename _R>
struct bina{
  typedef _A1 arg1;
  typedef _A2 arg2;
  typedef _R rtn;
};
*/

class Test1;
class Test2;

template<typename T>
class TypeTb1{};

template<>
class TypeTb1<Test1>{
public:
  typedef char ret_type;
  typedef int p1_type;
  typedef double p2_type;
};
template<>
class TypeTb1<Test2>{
public:
  typedef double ret_type;
  typedef double p1_type;
  typedef int p2_type;
};
template<typename T>
class Test{
public:
  typename TypeTb1<T>::ret_type func(typename TypeTb1<T>::p1_type x,
			      typename TypeTb1<T>::p2_type y){
    return x;
  }
};
int main(){
  Test<Test1> t;
  cout << t.func(65, 6.18) << endl;
  Test<Test2> t2;
  cout << t2.func(6.18, 65) << endl;
}
