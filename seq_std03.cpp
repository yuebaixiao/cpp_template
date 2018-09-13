#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int main(){
  //test1 顺序容器的front, back(forward_list没有back),at成员函数
  //front返回容器里的头元素；back返回容器里的最后一个元素
  /*
  //在解引用一个迭代器或调用front，back之前要检查容器里是否有元素
  deque<int> li{1,2,3,4};
  if(!li.empty()){
    auto val = *li.begin();
    val = 9;//不会改变容器里头元素的值
    cout << li.front() << endl;
    auto val2 = li.front();
    val2 = 8;//不会改变容器里头元素的值
    cout << li.front() << endl;
    auto& val3 = *li.begin();
    val3 = 9;//会改变容器里头元素的值
    cout << li.front() << endl;
    auto& val4 = li.front();
    val4 = 8;//会改变容器里头元素的值
    cout << li.front() << endl;

    auto val5 = li.end();
    //得到容器的最后一个元素
    auto last = *(--val5);
    cout << last << endl;

    auto v = li.at(1);
    auto v1 = li[2];
    cout << v << " " << v1 << endl;
  }
  */

  //test2 pop_back, pop_front
  //pop_back:删除容器的最后一个元素；pop_front:删除容器的第一个元素
  /*
  list<int> li{1,2,3,4};
  if(!li.empty()){
    li.pop_back();
    cout << li.back() << endl;
    li.pop_front();
    cout << li.front() << endl;
  }
  */

  //test3 erase
  //删除指定位置的元素，并放回指向删除元素的下一个元素的迭代器
  vector<int> li{0,1,2,3,4,5,6,7,8};
  //删除奇数
  auto b = li.begin();
  while(b != li.end()){
    if(*b % 2){
      b = li.erase(b);
    }
    else{
      ++b;
    }
  }
  for(auto const &s : li){
    cout << s << " ";
  }
  cout << endl;

  auto it = li.begin();
  li.erase(it, it + 2);
  for(auto const &s : li){
    cout << s << " ";
  }
  cout << endl;

}
