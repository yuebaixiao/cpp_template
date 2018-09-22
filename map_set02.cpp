#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main(){
  //test1 关联容器的别名 
  /*
  set<string>::value_type v1("aa");//v1是string类型
  set<string>::key_type v2("bb");//v2是string类型
  map<string, int >::value_type v3{"aa",12};//v3是pair<const string,int>类型
  map<string, int>::key_type v4("cc");//v4是string类型
  //只有map才有mapped_type
  map<string, int>::mapped_type v5(100);//v5是int类型
  */

  //test2 解关联容器的迭代器
  /*
  map<string, int> cnt{{"aa",1}, {"bb",2}};
  auto map_it = cnt.begin();
  //map_it->first = "new key";//错误，first为const
  ++map_it->second;
  cout << map_it->second << endl;//2
  set<int> iset{1,2,2,3,3,5};
  set<int>::iterator set_it = iset.begin();
  //*set_it = 10;//错误，不可以改变set的key
  */

  //test3 遍历关联容器
  /*
  map<string, int> cnt{{"dd",1}, {"cc",2},{"aa", 10}};
  map<string, int>::const_iterator  map_it = cnt.cbegin();
  while(map_it != cnt.cend()){
    cout << map_it->first << ":" << map_it->second << endl;
    ++map_it;
  }
  for(auto &s : cnt){
    cout << s.first << ":" << s.second << endl;
  }
  auto it = cnt.begin();
  pair<string, int> p1 = *it;
  */

  //test4 关联容器的通用算法
  multiset<string> c{"aa","aa","dd","cc"};
  vector<string> v{"ee","ff"};
  //copy(v.begin(),v.end(), inserter(c, c.end()));//OK
  //copy(v.begin(),v.end(), back_inserter(c));//NG，关联容器没有push_back
  //copy(c.begin(),c.end(), inserter(v, v.end()));//OK,并且c的begin到end时拍好序的
  copy(c.begin(),c.end(), back_inserter(v));
  for(auto &s : c){
    cout << s << " ";
  }
  cout << endl;
  for(auto &s : v){
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
