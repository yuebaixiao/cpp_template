#include <iostream>

using namespace std;

int main(){
  //test1 初始化多维数组
  /*
  int ia[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
  };
  //ia2和ia完全相同
  int ia2[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
  //只初始化每行的首元素,其他元素为默认值
  int ia3[3][4] = {{1},{4},{8}};
  int ia4[2][3][4] = {1};
  //用ia4的首元素为ia最后一行最后一列的最后一个元素赋值
  ia[2][3] = ia4[0][0][0];
  //把row绑定到ia的第二行上
  int (&row)[4] = ia[2];
  for(auto s : row){
    cout << s << ",";
  }
  cout << endl;
  */

  //test2 遍历多维数组,除了最内层循环外，其他所有层都必须是引用类型
  /*
  constexpr size_t rowCnt = 3,colCnt = 4;
  int ia[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
  };
  for(size_t i = 0; i < rowCnt; ++i){
    for(size_t j = 0; j < colCnt; ++j){
      cout << ia[i][j] << ",";
    }
    cout << endl;
  }
  //除了最内层循环外，其他所有层都必须是引用类型
  for(auto &row : ia){
    for(auto &col : row){
      cout << col << ",";
    }
    cout << endl;
  }
  */

  //test3 指针和多维数组
  int ia[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
  };
  //普通遍历
  for(auto p = ia; p != ia + 3; ++p){
    for(auto q = *p; q != *p + 4; ++q){
      cout << *q << ",";
    }
    cout << endl;
  }
  //利用库函数begin和end
  for(auto p = std::begin(ia); p != std::end(ia); ++p){
    for(auto q = std::begin(*p); q != std::end(*p); ++q){
      cout << *q << ",";
    }
    cout << endl;
  }
  //利用别名
  using iar = int[4];
  for(iar* p = ia; p != ia + 3; ++p){
    for(int* q = *p; q != *p + 4;++q){
      cout << *q << ",";
    }
    cout << endl;
  }
}
