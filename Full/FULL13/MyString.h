#pragma once

class MyString{
  public:
      friend MyString operator*(int a, MyString b);
      MyString(const char *);
      MyString();
      MyString(const MyString &a);
      ~MyString();
      operator char*() const;
      MyString operator+ (const MyString a);
      MyString & operator=(const char *);
      MyString operator *(const int a);
      int operator==(const char *a);
      char *getNapis(){ return _napis; }
      
      /*std::ostream & operator<<(std::ostream &a, MyString b){
        return std::ostream &a << b._napis;
      }*/
  private:
      char *_napis = nullptr;
};

MyString operator*(int a, MyString b);