#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(){
  //test1 4种插入方式
  /*
  map<int, int> mp{{1,2},{2,3}};
  //方式1
  mp.insert({1,3});//insert不成功,因为key1已经存在
  //方式2
  mp.insert(make_pair(3,4));
  //方式3
  mp.insert(pair<int,int>(4,1));
  //方式4
  mp.insert(map<int,int>::value_type(5,1));
  for(auto &s : mp){
    cout << s.first << "," << s.second << endl;
  }
  */

  //test2 map insert的返回值
  /*
  map<string, size_t> cnt;
  string wd;
  while(cin >> wd){
    //map和setinsert的返回值类型如下,用auto也可以
    pair<map<string, size_t>::iterator, bool> ret = 
      cnt.insert({wd, 1});
    //auto ret = cnt.insert({wd, 1});
    if(!ret.second){
      ++ret.first->second;
    }
  }
  for(auto &s : cnt){
    cout << s.first << ":" << s.second << endl;
  }
  */

  //test3 multimap insert的返回值
  multimap<string, size_t> aus;
  aus.insert({"aaa", 1});
  //multi的返回值类型如下
  map<string, size_t>::iterator ret = aus.insert({"aaa", 2});
  cout << ret->first << ":" << ret->second << endl;
}
