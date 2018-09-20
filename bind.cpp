#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
//_1,_n定在std::placeholders里面
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz){
  return s.size() >= sz;
}
bool shorter(const string &a, const string &b){
  return a.size() < b.size();
}
ostream& print(ostream& os, const string &s, const char &c){
  //c = ',';
  return os << s << c;
}
int main(){
  
  /*
  //用bind实现了和lambda一样的功能
  vector<string> svec{"aab","d","aa","bb","e","bbb"};
  stable_sort(svec.begin(),svec.end(),[](const string &a, const string &b){
      return a.size() < b.size();
    });
  string::size_type sz = 3;
  auto idx = find_if(svec.begin(),svec.end(),bind(check_size, _1, sz));
  cout << *idx << endl;
  idx = find_if(svec.begin(),svec.end(),[sz](const string &s){
      return s.size() >= sz;
    });
  cout << *idx << endl;
  */

  /*
  //用bind改变原来函数的参数的位置
  //升序
  vector<string> svec{"aab","d","aa","bb","e","bbb"};
  sort(svec.begin(), svec.end(), shorter);
  for(auto const &s : svec){
    cout << s << " ";
  }
  cout << endl;
  //由于调换了shorter参数的位置，所以变成了降序
  sort(svec.begin(), svec.end(),bind(shorter, _2, _1));
  for(auto const &s : svec){
    cout << s << " ";
  }
  cout << endl;
  */  

  //bind引用,必须使用ref或者cref函数，把对象转化成引用，不能用&
  ostream &os = cout;
  const char c = ' ';
  vector<string> svec{"aab","d","aa","bb","e","bbb"};
  for_each(svec.begin(),svec.end(),[&os, c](const string &s){
      os << s << c;
    });
  os << endl;
  for_each(svec.begin(),svec.end(),bind(print, ref(os), _1, cref(c)));
  os << endl;
  cout << c << endl;

}
