#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

class Test{
public:
  Test(int d = 0):data(d){}
  bool operator<(const Test& s)const{
    return s.data < data;
  }
  const int& getData()const{
    return data;
  }
private:
  int data;
};
int main(){
  //test1 map的下标操作
  /*
  map<string,int> smap{{"aa",12},{"bb",10}};
  unordered_map<int, int> imap{{1,11},{2,22}};
  map<string,int>::mapped_type m1 = smap["aa"];//m1为int
  cout << m1 << endl;
  unordered_map<string,int>::mapped_type m2 = imap[2];//m2为int
  cout << m2 << endl;
  smap["aa"] = 33;
  cout << smap["aa"] << endl;
  smap["cc"] = 13;//想smap添加{"cc",13}
  cout << smap["cc"] << endl;
  cout << smap.at("cc") << endl;
  //cout << smap.at("ccd") << endl;//抛出out_of_range异常
  map<string,int>::mapped_type m3 = smap.at("aa");
  cout << m3 << endl;
  //想smap里添加了{"dd", 0},
  cout << smap["dd"] << endl;
  for(auto const &s : smap){
    cout << s.first << "," << s.second << endl;
  }
  */

  //test2 map 用自定义类型的下标操作
  /*
  map<Test,int> tmap{{Test(10), 10},{Test(11), 11}};
  tmap[Test()] = 1;
  for(auto const &s : tmap){
    cout << s.first.getData() << "," << s.second << endl;
  }
  */

  //test3 map的查找
  /*
  map<int, int> imap{{1,1},{3,3},{2,2},{5,5},{4,4}};
  map<int,int>::iterator it1 = imap.find(1);
  cout << it1->first << endl;
  map<int,int>::iterator it2 = imap.find(4);//返回imap.end()
  if(it2 == imap.end()){cout << "it2 is end" << endl;}
  cout << imap.count(2) << endl;
  auto it3 = imap.lower_bound(2);//{2,2}
  cout << it3->first << "," << it3->second << endl;
  auto it4 = imap.upper_bound(4);//{5,5}
  cout << it4->first << "," << it4->second << endl;
  */

  //test4 multimap的查找
  multimap<string, string> autrs{{"aaa","n1"},{"bbb","n1"},{"aaa","n2"},
							     {"aaa","n3"}};
  string sch("aaa");
  //方法1
  auto cnt = autrs.count(sch);
  auto it = autrs.find(sch);
  while(cnt){
    cout << it->second << endl;
    ++it;
    --cnt;
  }
  cout << "-----------------" << endl;
  //方法2
  for(auto beg = autrs.lower_bound(sch),end = autrs.upper_bound(sch);
      beg != end; ++beg){
    cout << beg->second << endl;
  }
  cout << "-----------------" << endl;
  //方法3
  for(auto pos = autrs.equal_range(sch);pos.first != pos.second;++pos.first){
    cout << pos.first->second << endl;
  }
}
