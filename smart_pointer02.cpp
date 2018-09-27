#include <memory>
#include <iostream>
#include <vector>

using namespace std;

class Test{
public:
  Test(int d = 0):data(d){cout << "cr:" << data << endl;}
  ~Test(){cout << "fr:" << data << endl;}
  void fun(){
    cout << "Test func(" << data << ")" << endl;
  }
  void setData(int d){
    data = d;
  }
private:
  int data;
};

//test3 智能指针作为函数的返回值
shared_ptr<Test> hun(int d){
  return make_shared<Test>(d);
}
void use_hun1(int d){
  shared_ptr<Test> p = hun(d);
  p->fun();
}//p离开作用域后，它指向的内存会被自动释放
shared_ptr<Test> use_hun2(int d){
  shared_ptr<Test> p = hun(d);//计数器为1
  return p;//返回p时，计数器递增，为2
}//离开作用域后，计数器递减，为1，因为不为0，所以不会释放
int main(){
  //test1 shared_ptr和unique_ptr都支持的操作
  /*
  //shared_ptr<Test> sp = make_shared<Test>();
  Test* pt = new Test();
  shared_ptr<Test> sp(pt);
  if(sp){
    cout << "sp指向了对象" << endl;
  }
  (*sp).fun();
  shared_ptr<int> isp;
  if(!isp){
    cout << "isp没有指向对象" << endl;
  }
  Test* tmp1 = sp.get();
  auto sp1 = make_shared<Test>(10);
  Test* tmp2 = sp1.get();
  swap(sp, sp1);
  tmp1->fun();
  tmp2->fun();
  sp.get()->fun();
  sp1.get()->fun();
  */

  //test2 shared_ptr独有的操作
  /*
  shared_ptr<Test> tsp = make_shared<Test>(11);
  cout << tsp.use_count() << endl;//1
  //tsp1和tsp指向相同的对象，这个对象的计数器加1
  shared_ptr<Test> tsp1(tsp);
  cout << tsp.use_count() << endl;//2
  //用tsp1改变了对象的data的值,所以用tsp再访问这个对象，发现对象被改变了
  tsp1->setData(111);
  tsp->fun();//111

  shared_ptr<Test> q(new Test(20));
  cout << q.use_count() << endl;//1
  cout << tsp.use_count() << endl;//2
  //如果q不是智能指针,q指向的Test(20)这块内存就泄露了
  //q是智能指针，所以自动释放了Test(20)这块内存
  q = tsp;
  cout << q.use_count() << endl;//3
  cout << tsp.use_count() << endl;//3
  if(!q.unique()){
    cout << "不是只有一个智能指针指向了某个对象" << endl;
  }
  */

  //test3 智能指针作为函数的返回值
  /*
  auto ap = use_hun2(22);
  ap->fun();
  use_hun1(33);
  */

}
