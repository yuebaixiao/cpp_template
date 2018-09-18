#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <list>
#include <deque>
#include <numeric>
#include <forward_list>

using namespace std;

//删除重复的元素
void delDups(vector<string> &svec){
  sort(svec.begin(),svec.end());
  auto end_u = unique(svec.begin(),svec.end());
  svec.erase(end_u, svec.end());
}
//自定义的排序规则
bool shorter(const string s1, const string s2){
  return s1.size() < s2.size();
}
//用lambda作为参数
void bigger(vector<string> &words,
	    vector<string>::size_type sz){
  delDups(words);
  //用lambda作为第三个参数
  stable_sort(words.begin(), words.end(),
	      [](const string &s1, const string &s2){
		return s1.size() < s2.size();
	      });
  auto idx = find_if(words.begin(),words.end(),
		     [sz](const string &s){
		       return s.size() >= sz;
		     });
  auto cnt = words.end() - idx;
  cout << cnt << " word's length >= " << sz << endl;
  for_each(idx, words.end(),[](const string &s){
      cout << s << " ";
    });
  cout << endl;
}
int main(){
  //test1 自定义排序算法
  /*
  vector<string> svec{"the","quick","red","fox","jumps",
      "over", "the","slow","red","turtle"};
  delDups(svec);
  //先按长度排序，长度相同的，再用字典顺序排序
  stable_sort(svec.begin(),svec.end(),shorter);
  for(const auto &s : svec){
    cout << s << " ";
  }
  cout << endl;
  */

  //test2 用lambda作为参数
  vector<string> svec{"the","quick","red","fox","jumps",
      "over", "the","slow","red","turtle"};
  bigger(svec, 4);

}
