#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

class Book{
public:
  Book(string bn = "") : isbn(bn){}
  const string& getIsbn() const{
    return isbn;
  }
private:
  string isbn;
};
bool compareIsbn(const Book &b1, const Book &b2){
  return b1.getIsbn() < b2.getIsbn();
}
class Student{
public:
  Student(string n = "", int a = 0) : name(n), age(a){}
  bool operator < (const Student &s) const{
    return age < s.age;
  }
public:
  string name;
  int age;
};
int main(){
  //test1 map，set的使用
  /*
  set<string> exclude{"aa","bb"};
  map<string, int> wcnt;
  string word;
  while(cin >> word){
    if(exclude.find(word) == exclude.end())
      ++wcnt[word];
  }
  for(const auto &w : wcnt){
    cout << "key: " << w.first << " , value: " << w.second << endl;
  }
  */

  //test2 定义关联容器
  /*
  map<string, size_t> em;//空容器
  set<string> exclude{"the","The"};
  map<string,string> autos{{"key1","val1"},{"key2","val2"}};
  for(auto const &s : autos){
    cout << s.first << " " << s.second << endl;
  }
  */

  //test3 multimap, multiset
  /*
  vector<int> ivec;
  for(vector<int>::size_type i = 0; i != 10; ++i){
    ivec.push_back(i);
    ivec.push_back(i);
  }
  set<int> iset(ivec.cbegin(), ivec.cend());
  multiset<int> miset(ivec.cbegin(), ivec.cend());
  cout << ivec.size() << endl;//20
  cout << iset.size() << endl;//10
  cout << miset.size() << endl;//20
  */

  //test4 自定义关键字类型的比较函数,函数方式
  ///*
  multiset<Book, decltype(compareIsbn)*>
    bookstore(compareIsbn);
  //multiset<Book, bool (*)(const Book &, const Book &)>
  //  bookstore(compareIsbn);
  vector<Book> books;
  for(char c = '5'; c != '1'; --c){
    string tmp = "isbn_0";
    tmp.insert(tmp.size(), 1, c);
    books.push_back(Book(tmp));
  }
  for(auto const &s : books){
    cout << s.getIsbn() << " ";
  }
  cout << endl;
  bookstore.insert(books.cbegin(), books.cend());
  multiset<Book, decltype(compareIsbn)*>::iterator beg = bookstore.begin();
  cout << beg->getIsbn() << endl;
  for(auto const &s : bookstore){
    cout << s.getIsbn() << " ";
  }
  cout << endl;
 

  //test5 自定义关键字类型的比较函数,重载<方式
  /*
  multiset<Student> students;
  Student s1("C", 3);
  Student s2("A", 5);
  Student s3("A", 4);
  students.insert(s1);
  students.insert(s2);
  students.insert(s3);
  for(auto const &s : students){
    cout << s.name << ": " << s.age << endl;
  }
  */
}
