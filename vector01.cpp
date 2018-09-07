#include <iostream>
#include <vector>

using namespace std;

class A{
public:
  A(){cout << "AA" << endl;}
};
int main(){

  //test1
  /*
  vector<int> v1;
  vector<vector<string>> v2;
  */

  //test2
  /*
  vector<A> v3(2);//创建2个元素的vector
  //因为v4所提供的值不能作为元素的初始值，
  //所以编译器尝试用默认值初始化vector，所以{4}的含义就变成了(4),
  //也就是创建了4个元素的vector
  vector<A> v4{4};//创建4个元素的vector
  vector<int> v5{15};//创建1个元素的vector
  for(auto a : v5){
    cout << a << endl;
  }
  */

  //test3
  /*
  vector<int> v1;//size:0
  cout << v1.size() << endl;
  vector<int> v2(10);//size:10
  cout << v2.size() << endl;
  vector<int> v3(10, 12);//size:10
  cout << v3.size() << endl;
  vector<int> v4{11};//size:1
  cout << v4.size() << endl;
  vector<int> v5{10, 12};//size:2
  cout << v5.size() << endl;
  vector<string> v6{10};//size:10
  cout << v6.size() << endl;
  vector<string> v7{10, "ab"};//size:10
  cout << v7.size() << endl;
  */

  //test4
  /*
  vector<int> v;
  int s;
  while(cin >> s){
    v.push_back(s);
  }
  cout << v.size() << endl;
  */
  
  //test5
  /*
  vector<string> v;
  string s;
  while(cin >> s){
    v.push_back(s);
  }
  cout << v.size() << endl;
  */

  //test6
  /*
  //vector::size_type t;编译不过，必须带<int>
  vector<int>::size_type t;
  */

  //test7
  /*
  vector<int> v(11, 0);
  int grade;
  while(cin >> grade){
    if(grade <= 100)
      ++v[grade / 10];
  }
  for(auto a : v){
    cout << a << " ";
  }
  cout << endl;
  */

}
