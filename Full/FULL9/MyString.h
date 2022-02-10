#pragma once
#include <cstring>

static int number = 1;

class MyString {
private:
    char* _str{};
    int _id;
public:
    MyString(){
        _id = number;
        number++;
        fillstring("\0");
    }

    explicit MyString(const char* data){
        _id = number;
        number++;
        fillstring(data);
    }

    ~MyString() {
        del();
    }
    static MyString create(const char* data);
    void fillstring(const char* data);
    void print();
    void join(const MyString& sec_str);
    void replace(const char* data);
    inline const char* str();
    void del();
};

void swap(MyString& str1, MyString& str2);

