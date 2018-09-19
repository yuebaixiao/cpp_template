#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  //test1 值捕获
  /*
  int i = 1;
  auto f = [i]{return i;};
  i = 10;
  int j = f();
  cout << j << endl;
  */

  //test2 引用捕获
  /*
  int i = 1;
  auto f = [&i]{return i;};
  i = 10;
  int j = f();
  cout << j << endl;//3
  */

  //test3 隐式值捕获
  /*
  int i = 1;
  int j = 2;
  auto f = [=]{return i + j;};
  i = 3;
  int m = f();
  cout << m << endl;
  */

  //test4 隐式引用捕获
  /*
  int i = 1;
  int j = 2;
  auto f = [&]{return i + j;};
  i = 3;
  int m = f();
  cout << m << endl;//5
  */

  //test5 隐式，显式混合1
  /*
  int i = 1;
  int j = 2;
  //i为值捕获，j为引用捕获
  auto f = [=,&j]{return i + j;};
  i = 3;
  int m = f();
  cout << m << endl;//3
  */

  //test5 隐式，显式混合2
  /*
  int i = 1;
  int j = 2;
  //i为引用捕获，j为值捕获
  auto f = [&,j]{return i + j;};
  i = 3;
  int m = f();
  cout << m << endl;//5
  */

  //test6 可变lambda
  /*
  int i = 10;
  auto f = [i] () mutable{return ++i;};
  int j = f();
  cout << j << endl;
  */
  /*
  const int i = 10;
  //编译错误，因为i为const
  auto f = [i] () mutable{return ++i;};
  int j = f();
  cout << j << endl;
  */

  //test7 lambda的返回类型
  vector<int> ivec{-12,2,-22,3,0};
  //改变ivec里的值，负数变成整数
  //此lambda不写返回类型没有问题.
  //transform(ivec.begin(),ivec.end(),ivec.begin(),
  //	    [](int i){return i < 0 ? -i : i;});
  //此lambda不写返回类型也没有问题.
  transform(ivec.begin(),ivec.end(),ivec.begin(),
  	    [](int i){if(i < 0) return -i;
	      else return i;});
  for(const auto &s : ivec){
    cout << s << " ";
  }
  cout << endl;
}
