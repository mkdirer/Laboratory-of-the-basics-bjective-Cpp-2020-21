#include "MyString.h"
#include <iostream>
#include <string>
//MyString a;


void init(MyString &data, const std::string word)
{
  data.str = word;
}

MyString join(const MyString &data1, const MyString &data2){
  MyString newData;
  newData.str = data1.str + data2.str;
  return newData;
}

void swap(MyString &data1, MyString &data2)
{
  std::string temp = data1.str;
  data1.str = data2.str;
  data2.str = temp;
}

void swap(MyString *&data1, MyString *&data2)
{
  MyString* temp = data1;
  data1 = data2;
  data2 = temp;
}

void del(MyString& one, MyString& two, MyString& three, MyString& four,MyString& five){
  if(!one.str.empty()){
    std::cout<<"deleting "<<one.str <<std::endl;
    one.str.clear();
  }

  if(!two.str.empty()){
    std::cout<<"deleting "<<two.str <<std::endl;
    two.str.clear();
  }

  if(!three.str.empty()){
    std::cout<<"deleting "<<three.str <<std::endl;
    three.str.clear();
  }

  if(!four.str.empty()){
    std::cout<<"deleting "<<four.str <<std::endl;
    four.str.clear();
  }

  if(!five.str.empty()){
    std::cout<<"deleting "<<five.str <<std::endl;
    five.str.clear();
  }

}


