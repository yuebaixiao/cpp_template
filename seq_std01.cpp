#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <forward_list>
#include <array>

using namespace std;

int main(){
  //test1 容器的初始化
  /*
  list<string> au = {"MM","DD","YY"};
  vector<const char*> arti = {"a","b","c"};
  list<string> li(au);
  //deque<string> de(au);//错误：容易类型不匹配
  //vector<string> v(arti);//错误：容易类型不匹配
  deque<string> de(au.begin(), au.end());
  deque<string> d2(arti.cbegin(), arti.cend());
  vector<string> v1(au.begin(), au.end());
  vector<string> v2(arti.cbegin(), arti.cend());
  forward_list<string> f1(au.begin(),au.end());

  list<string> l(5,"aa");//包含5个"a"
  forward_list<int> iv(10);//包含10个0；
  deque<string> d(3);//包含3个空string
  */

  //test2 标准库array的初始化
  //标准库array的大小属于类型的一部分，内置数组不可以赋值和拷贝，但是array可以
  /*
  array<int,5> a1;
  array<string,3> a2;
  array<int,5>::size_type i;
  //array<int>::size_type j;//错误，没有提供数组的大小
  array<int,4> a3 = {1,2,3,4};
  array<int,3> a4 = {1};//a4[0]为1，其余为0
  for(auto s : a4){
    cout << s << " ";
  }
  cout << endl;
  int ia[] = {1,2,3};
  //int cpy[3] = ia;//错误
  array<int, 3> ia2 = {1};
  array<int, 3> ia3 = ia2;
  ia3 = {3,4};//ia3变成3,4,0
  for(auto s : ia3){
    cout << s << " ";
  }
  cout << endl;
  //array<int, 3> ia4(ia);//错误
  //array<int, 3> ia5 = ia;//错误
  */

  //test3 容器的赋值
  //assign的作用：先清空容器里所有的元素，再把新的元素添加进去
  /*
  list<string> li;
  vector<char*> ol;
  //li = ol;//错误，容器类型不匹配
  li.assign(ol.cbegin(), ol.cend());
  list<string> l2(3, "aa");
  l2.assign(2,"bb");
  for(auto const s : l2){
    cout << s << " ";
  }
  cout << endl;
  */

  //test4 容器的swap
  //swap不交换容器里的元素，只是交换两个容器内部的数据结构
  /*
  list<int> l1(3,10);
  list<int> l2(4,9);
  swap(l1, l2);
  for(auto const &s : l1){
    cout << s << " ";
  }
  cout << endl;
  for(auto const &s : l2){
    cout << s << " ";
  }
  cout << endl;
  */

  //test5 容器的比较(==,!=,>,>=,<,<=)
  //是否可以使用比较运算符，取决于容器里的元素是否重写了这个运算符
  vector<int> v1 = {1,3,5,7,9,12};
  vector<int> v2 = {1,3,9};
  vector<int> v3 = {1,3,5,7};
  vector<int> v4 = {1,3,5,7,9,12};
  cout << (v1 < v2) << endl;//true
  cout << (v1 < v3) << endl;//false
  cout << (v1 == v4) << endl;//true
  cout << (v1 == v2) << endl;//false
  class Test{};
  list<Test> l1(2);
  list<Test> l2(3);
  //cout << (l1 < l2) << endl;//错误，类Test没有重写<方法，所有无法比较

  return 0;
}
