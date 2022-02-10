#include "MyString.h"
#include <iostream>
#include <string.h>

MyString::MyString(const char *tekst){
  _napis = new char [strlen(tekst) + 1];
  strcpy(_napis, tekst);
}

MyString::MyString(const MyString &a){
  _napis = new char [strlen(a._napis) + 1];
  strcpy(_napis, a._napis);
}

MyString::MyString(){
  _napis = nullptr;
}

MyString::~MyString(){
  delete[] _napis;
}

MyString::operator char*() const{
  return _napis;
}

MyString MyString::operator+ (const MyString a){
  MyString nowy;
  int rozmiar = strlen(a._napis) + strlen(_napis) + 1;
  char* tmp = new char [strlen(_napis) + 1];
  strcpy(tmp, _napis); 
  nowy._napis = new char [rozmiar];
  strcpy(nowy._napis, tmp);
  strcat(nowy._napis, a._napis);
  delete[] tmp;
  return nowy;

}

MyString & MyString::operator=(const char *tekst){
  delete[] _napis;
  _napis = new char [strlen(tekst) + 1];
  strcpy(_napis, tekst);
  return *this;
}

MyString operator*(int a, MyString b){
  MyString tmp;
  int rozmiar = a*strlen(b.getNapis()) + 1;
  tmp._napis = new char[rozmiar];
  strcpy(tmp._napis, b.getNapis());
  for(int i = 0; i < a - 1; ++ i){
    strcat(tmp._napis, b.getNapis());
  } 
  return tmp;
}

MyString MyString::operator *(const int a){
  int rozmiar = a*strlen(_napis) + 1;
  char *tmp = new char [strlen(_napis) + 1];
  strcpy(tmp, _napis);
  delete[] _napis;
  _napis = new char [rozmiar];
  strcpy(_napis, tmp);
  for(int i = 0; i < a - 1; ++ i){
    strcat(_napis, tmp);
  }
  delete[] tmp;
  return *this;
}

int MyString::operator==(const char *a){
  int wynik = strcmp(_napis, a);
  if(wynik == 0){
    return 1;
  } 
  else{
    return 0;
  }
}