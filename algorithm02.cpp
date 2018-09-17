#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <numeric>
#include <forward_list>

using namespace std;

int main(){
  //只读算法
  //1，求容器里元素的和
  /*
  forward_list<int> fl{1,2,3,4,5};
  //第三个参数为sum的初始值
  int sum = accumulate(fl.cbegin(),fl.cend(),0);
  cout << sum << endl;
  vector<string> svec{"aa","bb","cc"};
  string str = accumulate(svec.cbegin(),svec.cend(),string(""));
  //错误：const char*上没有定义+运算符
  //string err = accumulate(svec.cbegin(),svec.cend(),"");
  cout << str << endl;
  */

  //2，比较2个容器里的元素
  //如果把svec里放的是const char*，执行结果和string一样
  /*
  vector<string> svec{"aa","bb","cc","dd"};
  list<const char*> lc{"bb","cc"};
  //头2个参数为第一个容器的区间，第三个参数为第二个容器的首元素
  auto result = equal(svec.cbegin()+1,svec.cend()-1, lc.cbegin());
  cout << result << endl;
  */

  //写算法
  //1，填充fill算法
  /*
  array<int, 6> ar{1,2,3,4,5,6};
  cout << ar.size() << endl;
  //vector<int> ar{1,2,3,4,5};
  //把指定范围内的值变为9
  fill(ar.begin(),ar.begin() + ar.size()/2,9);
  for(auto const &s : ar){
    cout << s << " ";
  }
  cout << endl;
  cout << ar.size() << endl;
  */
  //2，填充fill_n算法
  /*
  int ir[] = {1,2,3,4,5,6};
  //指定位置开始，后3个元素变为9
  fill_n(begin(ir)+1,3,9);
  for(auto const &s : ir){
    cout << s << " "; 
  }
  cout << endl;
  */
  //3，插入迭代器back_inserter
  //在容器末尾插入元素
  /*
  vector<int> ivec{1,0};
  auto it = back_inserter(ivec);
  fill_n(it,3,99);
  for(auto const &s : ivec){
    cout << s << " ";
  }
  cout << endl;//1,0,99,99,99
  */
  //4，copy算法
  /*
  int a1[] = {1,2,3,4,5};
  int a2[sizeof(a1) / sizeof(*a1)];
  //把a1指定范围里的值拷贝给a2,ret指向a2最后一个元素的下个元素
  auto ret = copy(begin(a1), end(a1), a2);
  //ret-1为数组a2的最后一个元素的地址
  *(ret-1) = 100;
  for(auto const &s : a2){
    cout << s << " ";
  }
  cout << endl;
  //ret和end(a2)指向同一个地址
  if(ret == end(a2)){
    cout << "true" << endl;
  }
  else{
    cout << "false" << endl;
  }
  */
  //5，replace算法
  /*
  list<int> il{1,2,2,2,5};
  //把范围内的2替换成23
  replace(il.begin(), il.end(),2,43);
  for(auto const &s : il){
    cout << s << " ";
  }
  cout << endl;
  list<int> ila{1,2,2,2,5};
  vector<int> ivec;
  replace_copy(ila.begin(),ila.end(),back_inserter(ivec),2,23);
  for(auto const &s : ivec){
    cout << s << " ";
  }
  cout << endl;
  //不改变ila
  for(auto const &s : ila){
    cout << s << " ";
  }
  cout << endl;
  */

  //重新排列算法(链表list和forward_list不支持sort)
  //实现删除重复的元素
  deque<string> sli = 
    {"one","two","one","three","two","four","two"};
  for(auto const &s : sli){
    cout << s << " ";
  }
  cout << endl;
  //从小到大排序
  sort(sli.begin(),sli.end());
  for(auto const &s : sli){
    cout << s << " ";
  }
  cout << endl;
  //把有重复的元素放到末尾，并返回不重复元素的下一位置
  auto end_unique = unique(sli.begin(),sli.end());
  //删除掉重复的元素
  sli.erase(end_unique, sli.end());
  for(auto const &s : sli){
    cout << s << " ";
  }
  cout << endl;
  cout << "size: " << sli.size() << endl;//size: 4
}
