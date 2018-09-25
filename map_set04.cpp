#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(){
  map<int , int> mp{{2,22},{3,33},{1,11},{4,44}};
  for(auto const &s : mp){
    cout << s.first << "," << s.second << endl;
  }
  cout << "-----------------" << endl;
  map<int, int>::const_iterator it = mp.cbegin();
  //map,set,list迭代器不支持加法，减法运算，但可以++,--。
  //auto it2 = it + 2;//NG 
  auto it2 = mp.find(2);
  auto rt2 = mp.erase(it, it2);//删除1,rt2指向(2,22)
  cout << rt2->first << ":" << rt2->second << endl;
  auto rt1 = mp.erase(it2);//删除2
  cout << rt1->first << ":" << rt1->second << endl;
  auto rt = mp.erase(3);//删除3,返回值为1或者0，因为3存在所以返回1
  for(auto const &s : mp){
    cout << s.first << "," << s.second << endl;
  }
}
