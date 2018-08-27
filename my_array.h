#ifndef __my_array__
#define __my_array__
template<typename T, int n>
class Array {
public:
  Array();
  Array(int length);
  ~Array();
  T& get(int idx);
  T& operator[](int idx);
  void set(T data, int idx);
  int size();
private:
  T* pt;
  int size1;

};
//构造函数
template<typename T, int n>
Array<T, n>::Array(){
  pt = new T[n];
  size1 = n;
}
//构造函数
template<typename T, int n>
Array<T, n>::Array(int length){
  pt = new T[length];
  size1 = length;
}
//析构函数
template<typename T, int n>
Array<T, n>::~Array(){
  delete [] pt;
}
//取得数组元素的个数
template<typename T, int n>
int Array<T,n>::size(){
  return size1;
}
//得到指定下标的元素
template<typename T, int n>
T& Array<T, n>::get(int num){
  if(num >= size1 || num < 0){
    //异常
  }
  else{
    return pt[num];
  }
}
//设定指定下标元素的值
template<typename T, int n>
void Array<T, n>::set(T data, int num){
  if(num >= size1 || num < 0){
    //异常
  }
  else{
    pt[num] = data;
  }
}
//重载元素类型的[]函数
template<typename T, int n>
T& Array<T, n>::operator[](int num){
  if(num >= size1 || num < 0){
    //异常
  }
  else{
    return *(pt + num);
  }
}
#endif
