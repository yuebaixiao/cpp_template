#include <iostream>

using namespace std;

int main(void){
  //test1
  //string s1,s2;
  //cin >> s1 >> s2;
  //cout << s1 << ";" << s2 << endl;

  //test2
  //string wd;
  //while(cin >> wd){
  //  cout << wd << endl;
  //}

  //test3
  /*
  string line;
  while(getline(cin, line)){
    cout << line << endl;
  }
  */

  //test4
  /*
  string line;
  while(getline(cin, line)){
    if(!line.empty()){
      cout << line << endl;
    }
    else{
      cout << "empty" << endl;
    }
  }
  */

  //test5
  /*
  string line;
  while(getline(cin, line)){
    if(line.size() > 2){
      cout << line << endl;
    }
  }
  string::size_type len = string("1111111111111111abc").size();
  cout << len << endl;
  int n = -1;
  if(len < n){
    cout << "in" << endl;
  }
  */

  //test6
  /*
  string s("asdfdsf!!!");
  decltype(s.size()) cnt = 0;
  for(auto c : s){
    if(ispunct(c))
      ++cnt;
  }
  cout << cnt << "times" << endl;
  */

  //test7
  /*
  string s("aaasd!!!");
  for(auto& c : s){
    c = toupper(c);
  }
  cout << s << endl;
  */

  //test8
  /*
  string s("abc def");
  if(!s.empty())
    s[0] = toupper(s[0]);
  cout << s << endl;
  */

  //test9
  /*
  string s("one two");
  for(decltype(s.size()) idx = 0;
      idx != s.size() && !isspace(s[idx]); ++idx){
    s[idx] = toupper(s[idx]);
  }
  cout << s << endl;
  */

  //test10
  const string hex("0123456789ABCDEF");
  string result;
  string::size_type n;
  while(cin >> n){
    if(n < hex.size()){
      result += hex[n];
    }
  }
  cout << result << endl;

}
