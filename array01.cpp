#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main(){
  //test1 声明时必须指定数组的大小
  /*
  unsigned cnt = 42;
  constexpr unsigned sz = 42;
  int arr[10];
  int *parr[sz];
  string bad[cnt];
  bad[23] = "aaa";
  cout << bad[23] << endl;
  */

  //test2 初始化
  /*
  const unsigned sz = 3;
  int ia1[sz] = {1,2,3};//含有3个元素的数组，元素值：1,2,3
  int a2[] = {1,2,3};//含有3个元素的数组，元素值：1,2,3
  int a3[5] = {1,2,3};//含有5个元素的数组，元素值：1,2,3,0,0
  cout << a3[3] << a3[4] << endl;
  string a4[3] = {"ni", "go"};//含有3个元素的数组，元素值："ni","go",""
  cout << a4[2] << endl;
  //int a5[2] = {1,2,3};//错误
  */

  //test3 char数组
  /*
  char a1[] = {'a','b','c'};//列表初始化，没有尾部\0
  cout << a1 << endl;//因为没有尾部的\0，所以会一直打印到\0为止
  char a2[] = {'a','b','c', '\0'};//列表初始化，有尾部\0
  cout << a2 << endl;
  char a3[] = "abc";//自动添加尾部的\0
  cout << a3 << endl;
  //char a4[3] = "abc";//错误，指定了大小为3，无法在c后面加\0
  */

  //test4 数组拷贝和赋值
  /*
  int a[] = {1,2,3};
  //int a1[] = a;//不能拷贝数组
  int a2[] = {1,1,1};
  //a2 = a;//不能用数组给数组赋值
  */

  //test5 指针数组， 数组的指针， 数组的引用，指针数组的引用
  /*
  //指针数组
  int* pt[10];//ptr指向含有10个整型指针的数组
  //数组的指针
  int (*parr)[10];//parr指向一个含有10个整数的数组,应用于二维数组
  int br[2][10];
  parr = br;
  if(parr + 1 == &br[1]){
    cout << "==" << endl;
    parr[0][0] = 10;
    cout << br[0][0] << endl;
  }
  int arr[10];
  //数组的引用
  int (&af)[2][10] = br;
  af[0][1] = 123;
  cout << br[0][1] << endl;
  int (&arrRef)[10] = arr;
  arrRef[0] = 100;
  arrRef[1] = 10;
  cout << arrRef[0] << "," << arrRef[1] << endl;
  //指针数组的引用
  int* (&ar)[10] = pt;
  int a = 5;
  ar[0] = &a;
  *ar[0] = 500;
  cout << a << endl;
  */

  //test6 数组的范围for用法
  int ar[5] = {};
  for(auto &s : ar){
    s = s + 1;
  }
  //用size_t作为下标的类型，包括在cstddef头文件里
  size_t idx = 1;
  ar[idx] = 100;
  for(auto s : ar){
    cout << s << ",";
  }
  cout << endl;
}
