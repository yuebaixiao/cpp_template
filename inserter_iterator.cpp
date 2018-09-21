#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
  //copy函数不会改变容器的大小，但是使用了插入迭代器后，
  //就会改变容器的大小了
  /*
  list<int> lst{1,2,3,4};
  list<int> lst2,lst3;
  //运行错误，因为lst2是空list,copy函数不会增加容器的大小
  //copy(lst.cbegin(), lst.cend(), lst2.begin());
  copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
  copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
  for(auto const &s : lst2){
    cout << s << " ";
  }
  cout << endl;
  for(auto const &s : lst3){
    cout << s << " ";
  }
  cout << endl;
  */

  //unique_copy 拷贝不重复的元素到新的容器
  vector<int> ivec{1,2,1,2,3,4,3,3,3,2,2,1,1,1};
  list<int> lst;
  sort(ivec.begin(),ivec.end());
  unique_copy(ivec.cbegin(), ivec.cend(),back_inserter(lst));
  for(auto const &s : lst){
    cout << s << " ";
  }
  cout << endl;

}
