#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int main(){
  //下面代码展示了size和capacity之间的相互作用
  vector<int> ivec;
  //size为0；capacity的值依赖于库的具体实现
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
  //想ivec添加24个元素
  for(vector<int>::size_type i = 0; i != 24; ++i){
    ivec.push_back(i);
  }
  //size为24；capacity大于等于24
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
  //用reserve预分配一些额外的空间
  ivec.reserve(50);
  //size还是24；capacity大于等于50
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
  //添加元素，用光多余容量
  while(ivec.size() != ivec.capacity()){
    ivec.push_back(0);
  }
  //size为50；capacity为50
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
  //再添加一个元素，vector就不得不重新分配空间
  ivec.push_back(51);
  //size为51；capacity的值依赖于库的具体实现
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
  //要求归还内存
  //shrink_to_fit只是一个请求，标准库并不保证退还内存
  ivec.shrink_to_fit();
  //size为51；capacity的值依赖于库的具体实现
  cout << " ivec:size: " << ivec.size()
       << " capaciy: " << ivec.capacity() << endl;
}
