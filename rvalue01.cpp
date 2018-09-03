#include <iostream>
using namespace std;

class Test{
public:
  Test(int d) : data(d){cout << "create:" << data << endl;}
  ~Test(){cout << "free:" << data << endl;}
  
  Test& operator = (const Test& other){
    //data = other.data;
    cout << "operator" << endl;
    return *this;
  }
  
  int get_data() const {return data;}
  void set_data(int d){data = d;}
private:
  int data;
};

Test getTest(){
  int static i = 0;
  return Test(i++);
}

void func(Test& t){
  cout << "func:" << t.get_data() << endl;
}
int main(){
  //1
  //(getTest() = Test(1)).set_data(12);
  //getTest() = Test(2);
  //getTest().set_data(20);

  //2 只能用const引用接收右值引用
  //const Test& ref = getTest();
  //Test& ref1 = getTest();//error

  //3
  //func(getTest());
  func(getTest() = getTest());
}
