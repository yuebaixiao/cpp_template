#include <iostream>
#include <memory>

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
  allocator<test> alloc;
  auto const p = alloc.allocate(2);
  alloc.construct(p, test(1));
  p->fun();
  auto q = p + 1;
  alloc.construct(q, test(2));
  q->fun();
  alloc.destroy(p);
  alloc.destroy(q);
  alloc.deallocate(p,2);
}
