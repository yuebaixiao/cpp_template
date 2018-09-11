#include <iostream>
#include <vector>

using namespace std;

int main(){

  //test1 数组就是指针
  /*
  string ar[] = {"aa","bb"};
  string* p = ar;
  *p = "cc";
  string* p1 = &ar[1];
  *p1 = "dd";
  for(auto s : ar){
    cout << s;
  }
  cout << endl;
  */

  //test2 用auto声明，得到的是指针
  /*
  int ia[] = {1,2,3,5};
  //ia1为整数指针
  auto ia1(ia);
  *ia1 = 9;
  auto ia2(&ia[3]);
  *ia2 = 8;
  for(auto s : ia){
    cout << s << ",";
  }
  cout << endl;
  */

  //test3 用decltype声明，得到的不是指针
  /*
  int ia[3];
  decltype(ia) ia3 = {2,3,4};
  //ia3 = &ia[0];//编译错误
  ia3[2] = 9;
  for(auto s : ia3){
    cout << s << ",";
  }
  cout << endl;
  */

  //test4 用指针模拟end
  /*
  int arr[] = {0,1,2};
  int* end = &arr[3];
  for(int* beg = arr;beg != end; ++ beg){
    cout << *beg;
  }
  cout << endl;
  */

  //test5 标准库函数std::begin，std::end
  /*
  int arr[] = {0,1,2};
  int* beg = std::begin(arr);
  //int* end = &arr[3];
  int* end = std::end(arr);
  for(;beg != end; ++ beg){
    cout << *beg;
  }
  cout << endl;
  */

  //test6 ptrdiff_t和size_t
  //ptrdiff是数组下标相加减的值的类型，size_t是数组下标的类型
  /*
  int arr[] = {1,2,3,4,5};
  int* b = std::begin(arr);
  int* e = std::end(arr);
  ptrdiff_t juli = e - b - 1;
  cout << juli << endl;
  size_t sz = juli;
  cout << arr[sz] << endl;
  */

  //test7 数组的下标可以是负值，标准库的string,vector的下标也可以是负值
  /*
  int ia[] = {1,2,3,4,5};
  int* p = &ia[2];
  int j = p[1];//相当于*(p + 1),也就是ia[3]
  cout << j << endl;
  int k = p[-2];//相当于*(p - 2)，也就是ia[0]
  cout << k << endl;
  string s("abcde");
  char* p1 = &s[2];
  cout << p1[-1] << endl;
  vector<int> v{1,2,3,4};
  int* p2 = &v[3];
  cout << p2[-2] << endl;
  */

  //test8 用数组初始化vector,注意生成的vector里的元素不包括第二个参数
  /*
  int ia[] = {0,1,2,3,4,5,6};
  vector<int> v(std::begin(ia), std::end(ia));
  for(auto s : v){
    cout << s << ",";
  }
  cout << endl;
  vector<int> v1(ia + 1, ia + 4);
  for(auto s : v1){
    cout << s << ",";
  }
  cout << endl;
  */

}
