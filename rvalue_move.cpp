#include <iostream>
using namespace std;

class Resource{};

class holder{
public:
  //构造函数
  holder(){res = new Resource();}
  //析构函数
  ~holder(){
    //res不为NULL，就释放res
    if (res)delete res;
  }
  //拷贝构造函数
  holder(const holder& other){
    cout << "holder&" << endl;
    res = new Resource(*other.res);
  }
  holder(holder& other){
    cout << "holder&1" << endl;
    res = new Resource(*other.res);
  }

  //右值
  holder(holder&& other){
    cout << "holder&&" << endl;
    res = other.res;
    other.res = nullptr;
  }

  //赋值
  holder& operator=(const holder& other){
    cout << "operator" << endl;
    delete res;
    res = new Resource(*other.res);
    return *this;
  }
  holder& operator=(holder& other){
    cout << "operator1" << endl;
    delete res;
    res = new Resource(*other.res);
    return *this;
  }

  //右值
  holder& operator=(holder&& other){
    cout << "operator &&" << endl;
    std::swap(res, other.res);
    return *this;
  }


private:
  Resource* res;
};

holder get_holer(){
  holder h;
  return h;
}

int main(void){
  holder h1,h11;
  holder h2(std::move(get_holer()));
  holder h3(get_holer());//编译器自动优化了，没有调用拷贝构造函数
  holder h4(h11);

  h1 = h2;//调用operator(holder&);
  h1 = get_holer();//调用operator(holder&);

}
