#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int main(){

  //find vector<int>
  /*
  int val = 121;
  vector<int> ivec{1,2,3,12,34};
  vector<int>::const_iterator result = find(ivec.cbegin(), ivec.cend(),
					    val);
  cout << *result << endl;
  */

  //find list<string>
  /*
  string s("aaa");
  list<string> li{"ddd","aaa1","aaa","dds"};
  list<string>::const_iterator result = 
    find(li.cbegin(), li.cend(), s);
  cout << *result << endl;
  */

  //find 内置数组
  int val = 22;
  int ar[] = {1,22,33,4};
  int* result = find(begin(ar), end(ar), val);
  cout << *result << endl;
  auto res1 = find(ar, ar + 4, val);
  cout << *res1 << endl;
}
