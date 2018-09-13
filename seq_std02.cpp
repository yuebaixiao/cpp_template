#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int main(){
  //test1 push_back
  //forward_list没有push_back方法
  /*
  vector<string> container;
  //list<string> container;
  //deque<string> container;
  //forward_list<string> container;//forward_list没有push_back方法
  string word;
  while(cin >> word){
    container.push_back(word);
  }
  for(auto const &s : container){
    cout << s << " ";
  }
  cout << endl;
  
  string s("abc");
  s.push_back('d');
  cout << s << endl;
  */
  
  //test2 push_front
  /*
  //list<string> container;
  deque<string> container;
  string word;
  while(cin >> word){
    container.push_front(word);
  }
  for(auto const &s : container){
    cout << s << " ";
  }
  cout << endl;
  */

  //test3 insert单个元素
  //vector和string虽然不支持push_front，但是支持在头部insert
  /*
  //vector<string> container{"aa","bb","cc"};
  //list<string> container{"aa","bb","cc"};
  deque<string> container{"aa","bb","cc"};
  //vector<string>::iterator it = container.begin();
  //list<string>::iterator it = container.begin();
  deque<string>::iterator it = container.begin();
  container.insert(++it, "ddd");
  for(auto const &s : container){
    cout << s << " ";
  }
  cout << endl;
  string str("abc");
  string::iterator it1 = str.begin();
  str.insert(++it1, 'd');
  for(auto const &s : str){
    cout << s << " ";
  }
  cout << endl;
  */

  //test4 insert范围
  /*
  vector<string> v{"aa","bb","cc"};
  list<string> sl{"dd","ff"};
  sl.insert(sl.begin(), v.end() - 2, v.end());
  for(auto const &s : sl){
    cout << s << " ";
  }
  cout << endl;
  sl.insert(sl.end(), {"ee","gg"});
  for(auto const &s : sl){
    cout << s << " ";
  }
  cout << endl;
  */

  //test5 使用insert的返回值
  //插入到指定的位置之前,返回新添加的第一个元素
  /*
  list<string> sl;
  auto it = sl.begin();
  string word;
  //下面的代码,相当于push_front
  while(cin >> word){
    it = sl.insert(it,word);
  }
  for(auto const &s : sl){
    cout << s << " ";
  }
  cout << endl;
  */

  //test6 emplace_front,emplace,emplace_back
  //直接在容器里构造对象
  class Test{
  public:
    Test(const string& d = "", int s = 2) : name(d), age(s){}
    string getName()const{
      return name;
    }
    int getAge()const{
      return age;
    }
  private:
    string name;
    int age;
  };
  list<Test> vc;
  vc.emplace_back("aa",10);
  vc.emplace_front("bb",12);
  vc.emplace(vc.begin(), "cc", 11);
  for(auto const &s : vc){
    cout << s.getName() << ":" << s.getAge() << endl;
  }
}
