#include <iostream>
using namespace std;

template<typename T, typename U>
class traits{
public:
  typedef T value_type1;
  typedef T& ref1;
  typedef U value_type2;
  typedef U& ref2;
};

template<typename TA, typename UA>
class A : public traits<TA, UA>
{

};

int main(){
  A<int, double>::value_type1 a = 10;
  A<int, double>::ref1 b = a;
  cout << a << endl;
  cout << b << endl;
  A<int, double>::value_type2 a1 = 10.2;
  A<int, double>::ref2 b1 = a1;
  cout << a1 << endl;
  cout << b1 << endl;
}
