#include <iostream>
#include <string>
#include "my_array.h"

using namespace std;

int main(){
  Array<int, 5> ary;
  for(int i = 0; i < ary.size(); ++i){
    ary.set(i * 10, i);
    cout << ary.get(i) << " ";
    cout << ary[i] << ", ";
  }
  cout << endl;

  Array<string, 3> asr(4);
  for(int i = 0; i < asr.size(); ++i){
    asr.set("AAA", i);
    cout << asr.get(i) << " ";
    cout << asr[i] << ", ";
  }
  cout << endl;
  return 0;
}
