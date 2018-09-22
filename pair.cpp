#include <iostream>
#include <vector>

using namespace std;

pair<string, int> process(vector<string> &v){
  if(!v.empty()){
    return pair<string, int>(v.back(), v.back().size());
  }
  else{
    return pair<string, int>();
  }
}
int main(){
  pair<string, string> p1{"",""};
  pair<string, size_t> cnt{"last",5};
  pair<string, vector<int>> li;
  cout << cnt.first << " " << cnt.second << endl;
  vector<string> svec{"aa", "last"};
  pair<string, size_t> cnt2 = process(svec);
  cout << cnt2.first << " " << cnt2.second << endl;
  if(cnt2 == cnt){
    cout << "euqal" << endl;
  }
  if(cnt2 < cnt){
    cout << "less" << endl;
  }
  //由参数1和2推导出类型为<int, int>
  auto ap1 = make_pair(1, 2);
  pair<int, int> ap2(ap1);

}
