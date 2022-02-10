#pragma once
#include <iostream>

struct MyString
{
  std::string str;
};

static MyString a= {};
/** inicjalizuje nowy napis
*@pragma ciag słów
*@pragma napis, dodawany do ciagu
*/

void init(MyString &data, const std::string word);

/** generujemy nowy napis sklejony z dwoch argumentow
*@pragma pierwszy napis
*@pragma drugi napis
*@retrun nowy napis
*/
MyString join(const MyString &data1, const MyString &data2);

/** zmienia kolejność napisów
*@pragma pierwszy napis
*@pragma drugi napis
*/
void swap(MyString &data1, MyString &data2);

/** zmienia kolejność napisów
*@pragma pierwszy napis
*@pragma drugi napis
*/

void swap(MyString *&data1, MyString *&data2);

/** kasujemy wszystkie napisy
*@pragma pierwszy napis
*@pragma drugi napis
*@pragma trzeci napis
*@pragma czwarty napis
*@pragma piąty napis
*/

void del(MyString& one, MyString& two = a, MyString& three = a, MyString& four = a, MyString& five = a);

