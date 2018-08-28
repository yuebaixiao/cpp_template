#include <iostream>
using namespace std;

class Foo{
public:
  Foo(int a, int b, int c) : x(a), y(b), z(c){}
  void show(){
    cout << x << "," << y << "," << z << endl;
  } 
private:
  int x, y, z;
};

template <typename T>
class Goo : public Foo{
public:
  Goo(T t, int a, int b, int c):Foo(a,b,c), data(t){}
  void show(){
    cout << data << endl;
    cout << "Goo show" << endl;
  }
private:
  T data;
};

class Hoo : public Goo<int>{
public:
  Hoo(int a1,int a2,int a3,int a4,int a5):
    Goo(a1,a2,a3,a4),ho(a5){}
  void show(){
    cout << "Hoo show" << endl;
  }
private:
  int ho;
};
int main(void){
  Hoo hoo(1,2,3,4,5);
  hoo.show();
  Goo<string> goo("abc",1,2,3);
  goo.show();
  return 0;
}
