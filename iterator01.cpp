#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

  //test1
  /*
  string s("abc bdc");
  auto it = s.begin();
  while(it != s.end()){
    *it = toupper(*it);
    ++it;
  }
  cout << s << endl;
  */

  //test2
  /*
  string s("abd ddd");
  for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it){
    *it = toupper(*it);
  }
  cout << s << endl;
  */

  //test3 不可改变vector::const_iterator类型
  /*
  vector<int>:: iterator it;
  vector<int>:: const_iterator it2;
  vector<int> v(5,1);
  it = v.begin();
  it2 = v.begin();
  vector<int> const cv(5,2);
  //it = cv.begin();//it是可改变的vector::iterator，所以编译错误
  for(auto s : v){
    cout << s;
  }
  cout << endl;
  */

  //test4 不可改变string::const_iterator类型
  /*
  string::iterator sit;
  string::const_iterator sit2;
  string s1("abc");
  sit2 = s1.begin();
  while(sit2 != s1.end()){
    //*sit2 = toupper(*sit2);
    cout << *sit2;
    ++sit2;
  }
  cout << endl;
  */

  //test5 cbegin和cend,返回const类型的iterator
  /*
  string s1("aaaa");
  auto it1 = s1.cbegin();
  //*it1 = 'c';//不可以通过const类型的iterator改变原来的对象
  cout << s1 << endl;

  vector<int> v(4,2);
  auto vit1 = v.cbegin();
  //*vit1 = 5;//不可以通过const类型的iterator改变原来的对象
  */

  //test6 string迭代器运算
  /*
  string s("abcd");
  string s1("abc");
  vector<int> v(5,3);
  auto it1 = s.begin();
  auto it2 = s.begin();
  if(it1 == it2){
    cout << "=" << endl;
  }
  ++it1;
  it1 += 1;
  if(it1 > it2){
    cout << ">" << endl;
    cout << it1 - it2 << endl;
  }
  string::difference_type juli = it1 - it2;
  cout << juli << endl;
  */

  //test7 vector迭代器运算
  /*
  vector<string> s(4,"abcd");
  vector<string> s1(5,"abc");
  auto it1 = s.begin();
  auto it2 = s.begin();
  if(it1 == it2){
    cout << "=" << endl;
  }
  
  ++it1;
  it1 += 1;
  if(it1 > it2){
    cout << ">" << endl;
    cout << it1 - it2 << endl;
  }
  vector<string>::difference_type juli = it1 - it2;
  cout << juli << endl;
  */

  //test8 利用迭代器实现二分法
  vector<string> v{"a","b","c","d","e"};
  string target("b");
  vector<string>::size_type idx = 0;
  auto beg = v.begin();
  auto mid = v.begin() + v.size() / 2;
  auto end = v.end();
  while(mid != end && *mid != target){
    if(target < *mid)
      end = mid;
    else
      beg = mid + 1;
    mid = beg + (end - beg) / 2;
  }
  if(mid == end){
    cout << "not found" << endl;
  }
  else{
    idx = mid - v.begin();
    cout << idx << ":" << *mid << endl;
  }
}
