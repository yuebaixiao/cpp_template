#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class test{
public:
  explicit test(int d = 0) : data(d){cout << "new" << data << endl;}
  ~test(){cout << "del" << data << endl;}
  void fun(){cout << data << endl;}
public:
  int data;
};
int main(){
  //test* t = new test[2];
  unique_ptr<test[]> up(new test[2]);
  up[0].data = 1;
  up[0].fun();
  up[1].fun();
  shared_ptr<test> sp(new test[2], [](test* p){delete [] p;});
  (sp.get())->data = 2;//数组的第一个元素
  sp->data = 10;
  test& st = *sp;
  st.data = 20;
  (sp.get() + 1)->data = 3;//数组的第二个元素
  return 0;
}
