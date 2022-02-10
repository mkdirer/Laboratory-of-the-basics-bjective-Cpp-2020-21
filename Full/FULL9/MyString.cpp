#include <iostream>
#include "MyString.h"

MyString MyString::create(const char* data) {
    MyString newstr(data);
    return newstr;
}

void MyString::fillstring(const char* data) {
    _str = new char[strlen(data)+1];
    strcpy(_str, data);
}

void MyString::print() {
    std::cout << "ID: " << _id << "str: " << _str << std::endl;
}

void MyString::join(const MyString& sec_str) {
    char temp[strlen(_str)+1];
    strcpy(temp, _str);
    delete [] _str;
    _str = new char[strlen(temp)+strlen(sec_str._str)+1];
    strcpy(_str, temp);
    strcat(_str, sec_str._str);
}

void MyString::replace(const char* data) {
    delete [] _str;
    fillstring(data);
}

void MyString::del() {
    std::cout << "- deleting " << _str << std::endl;
    delete [] _str;
}

inline const char* MyString::str() {
    return _str;
}

void swap(MyString& str1, MyString& str2) {
    char* temp = new char[strlen(str1.str())+1];
    strcpy(temp, str1.str());
    str1.replace(str2.str());
    str2.replace(temp);
    delete [] temp;
}