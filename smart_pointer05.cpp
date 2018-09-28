#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test{
public:
  Test(int d = 0) : data(d){cout << "new" << data << endl;}
  ~Test(){cout << "del" << data << endl;}
private:
  int data;
};
void my_deleter(Test* t){
  cout << "worked" << endl;
}
unique_ptr<int> cl1(int p){
  return unique_ptr<int>(new int(p));
}
unique_ptr<int> cl2(int p){
  unique_ptr<int> rt(new int(p));
  return rt;
}
void fl1(unique_ptr<int> p){
  *p = 100;
}

int main(){
  //test1 不可以拷贝和赋值
  /*
  unique_ptr<int> p1(new int(11));
  //unique_ptr<int> p2(p1);//NG
  unique_ptr<int> p3(new int(10));
  //p3 = p1;//NG
  */

  //test2 自定义删除器
  //不再调用Test的析构函数了
  //unique_ptr<Test, decltype(my_deleter)*> u(new Test(1), my_deleter);

  //test3 reset和release的使用
  /*
  unique_ptr<Test> p1(new Test(1));
  unique_ptr<Test> p2(p1.release());//将p1置为空，p2指向了原来p1指向的对象
  unique_ptr<Test> p3(new Test(3));
  p2.reset(p3.release());//先释放了p2所指向的内存，让p2指向了原来p3指向的对象,p3被置为空
  p2.release();//错误，p2不会释放内存，而且丢失了能够释放内存的指针
  auto p = p2.release();//正确，但必须要记得delete(p)
  */

  //test4 unique_ptr作为函数的返回值
  /*
  unique_ptr<int> p1 = cl1(11);
  cout << *p1 << endl;
  unique_ptr<int> p2 = cl2(22);
  cout << *p2 << endl;
  //fl1(p2);//NG 编译不过
  */
}
