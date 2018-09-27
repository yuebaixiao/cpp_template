#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test{
public:
  Test(int d = 0) : data(d){cout << "new:" << data << endl;}
  ~Test(){cout << "del:" << data << endl;}
private:
  int data;
};
void my_deleter(Test* t){
  cout << "my_deleter is work" << endl;
}
void pro(shared_ptr<int> ptr){

}
int main(){
  //test1 reset
  /*
  Test* tp = new Test(1);
  shared_ptr<Test> stp(tp);
  shared_ptr<Test> stp1(stp);
  stp.reset();
  cout << stp << endl;
  */

  //test2 自定义删除器
  /*
  Test* tp = new Test(1);
  //不会调用Test的析构函数了，只调用my_deleter函数
  shared_ptr<Test> stp(tp, my_deleter);
  shared_ptr<Test> stp1(stp);
  cout << stp.use_count() << endl;
  Test* tp1 = new Test(2);
  stp1.reset(tp1, my_deleter);
  */

  //test3 不要混用普通指针和智能指针
  /*
  shared_ptr<int> p(new int(42));//计数器为1
  pro(p);//p作为参数会进行copy递增它的计数器，在pro内部计数器是2
  int i = *p;//计数器为1
  cout <<  i << endl;

  int* bad =  new int(11);
  //pro(bad);//编译错误
  pro(shared_ptr<int>(bad));//合法，但出了pro，bad所指向的内存会被释放
  int j = *bad;//解指针bad就会产生难以预料的结果
  */

  //test4 get的错误使用
  /*
  shared_ptr<int> p(new int(12));
  int* q = p.get();
  {
    shared_ptr<int> tmp(q);
  }//程序块结束后，q所指向的对象被释放
  int f = *p;//解指针p就会产生难以预料的结果   
  cout << f << endl;
  */
}
