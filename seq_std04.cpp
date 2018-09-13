#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

int main(){
  //test1 forward_list容器的使用
  //insert_after,emplace_after,erase_after
  /*
  forward_list<int> fl{0,1,2,3,4,5};
  //返回头迭代器
  auto head = fl.before_begin();
  //在head的后面插入6，并返回指向6的迭代器,第一个元素是6
  auto it = fl.insert_after(head, 6);
  cout << *it << endl;
  for(auto s : fl){
    cout << s << " ";
  }
  cout << endl;
  auto it1 = fl.erase_after(it);
  cout << *it1 << endl;
  for(auto s : fl){
    cout << s << " ";
  }
  cout << endl;
  fl.pop_front();
  for(auto s : fl){
    cout << s << " ";
  }
  cout << endl;
  */

  //test2 resize
  //如果当前容器的大小大于所要求的大小，容器后部的元素会被删除；
  //如果当前容器的大小小于所要去的大小，会讲新元素添加到容器的后部
  list<int> li(5,11);
  cout << li.size() << endl;
  for(auto s : li){
    cout << s << " ";
  }
  cout << endl;
  li.resize(7,2);
  cout << li.size() << endl;
  for(auto s : li){
    cout << s << " ";
  }
  cout << endl;
  li.resize(3,8);//因为3小于原来容器的大小7，所以第二个参数8就被忽略了
  cout << li.size() << endl;
  for(auto s : li){
    cout << s << " ";
  }
  cout << endl;
}
