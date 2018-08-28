#include <iostream>
using namespace std;

template<typename T>
class Test{
public:
  Test(T t) : data(t){}
  virtual void show() = 0;
private:
  T data;
};

template<typename> class D;
template<typename T>
ostream& operator<< (ostream&, const D<T> &);

template<typename T>
class D : public Test<T>{
  //注意有<T>
  friend ostream& operator<< <T>(ostream& ,const D<T>&);
public:

  //注意不是Test(t1)
  D(T t1, T t2) : Test<T>(t1), x(t2){}
  void show(){
    cout << x << ", " << x << endl;
  }
private:
  T x;
};

template<typename T>
ostream& operator << (ostream& out,const D<T>& d){
  out << d.x;
  return out;
}

int main(void){
  Test<int> *p = new D<int>(10, 21);
  p->show();
  D<int> d(10,20);
  cout << d << endl;
  return 0;
}
