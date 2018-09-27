#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class shared_vector{
public:
  typedef vector<string>::size_type size_type;
  shared_vector():data(make_shared<vector<string>>()){}
  shared_vector(initializer_list<string> il):
    data(make_shared<vector<string>>(il)){}
  size_type size()const{return data->size();}
  bool empty()const{return data->empty();}
  //尾部插入，删除元素
  void push_back(const string& s){data->push_back(s);}
  void pop_back(){data->pop_back();}
  //访问元素
  string& front(){return data->front();}
  string& back(){return data->back();}

private:
  shared_ptr<vector<string>> data;
};

class un_shared_vector{
public:
  typedef vector<string>::size_type size_type;
  un_shared_vector():data(vector<string>()){}
  un_shared_vector(initializer_list<string> il):data(il){}
  size_type size()const{return data.size();}
  bool empty()const{return data.empty();}
  //尾部插入，删除元素
  void push_back(const string& s){data.push_back(s);}
  void pop_back(){data.pop_back();}
  //访问元素
  string& front(){return data.front();}
  string& back(){return data.back();}

private:
  vector<string> data;
};

int main(){
  shared_vector sv{"aa","bb"};
  shared_vector sv1(sv);
  //因为sv和sv1共享同一个vector，
  //所以通过sv改变vector后，通过sv1也发现了相同的改变
  sv.push_back("cc");
  cout << sv1.back() << endl;

  un_shared_vector usv{"11","22"};
  un_shared_vector usv1(usv);
  //因为usv和usv1不共享同一个vector，
  //所以通过usv改变vector后，usv1里面的vector没有跟着变化
  usv.push_back("33");
  cout << usv1.back() << endl;
  cout << usv.back() << endl;
}
