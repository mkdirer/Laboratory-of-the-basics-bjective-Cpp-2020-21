#include "lab06.h"
#include <iostream>
#include <cmath>

void set(Bits* struktura, const int* data, int size)
{
  struktura->size = size;
  for(int elem = 0; elem<size; elem++)
  {
    struktura->data[elem]= data[size-elem-1];
  }
}

void print(const Bits* strukture){
  for(int elem = strukture->size-1; elem>=0; elem--)
  {
    std::cout<<strukture ->data[elem];
  }
  std::cout<<std::endl;
}

Bits add_up(const Bits* bits, const Bits* bits2){
  Bits result;
  int size;
  if(bits->size > bits2->size) result.size = bits->size;
  else result.size = bits2->size;

  int add=0;
  for(int i=0; i<result.size; i++){
    if(bits->data[i]+bits2->data[i] + add ==0 ){
      result.data[i] = 0;
      add = 0;
    }else if(bits->data[i]+bits2->data[i] + add ==1 ){
      result.data[i] = 1;
      add = 0;
    }else if(bits->data[i]+bits2->data[i] + add ==2 ){
      result.data[i] = 0;
      add = 1;
    }else{
      result.data[i]=1;
      add = 1;
    }
  }

  if(add == 1){
    result.data[result.size]=1;
    result.size++;
  }
  return result;
}

void bit_and(Bits* bits, const Bits* mask){
  Bits result;
  if(bits->size > mask->size) result.size = bits->size;
  else result.size = mask->size;

  for(int elem = 0; elem< result.size; elem++)
  {
    result.data[elem] = bits->data[elem] & mask -> data[elem];
  }
    for(int elem =0; elem<result.size; elem++)
    {
      bits->data[elem] = result.data[elem];
    }

    int newSize = result.size;
    while(result.data[newSize-1]==0){
      newSize--;
      result.size = newSize;
    }
}

void bit_xor(Bits* bits, const Bits* mask){
  Bits result;
  if(bits->size > mask->size) result.size = bits->size;
  else result.size = mask -> size;

  for(int elem=0; elem<result.size; elem++){
    result.data[elem] = bits->data[elem] ^ mask->data[elem];
  }

  for(int elem = 0; elem<result.size; elem++)
  {
    bits->data[elem]= result.data[elem];
  }
  int newSize = result.size;
  while(bits->data[newSize-1]==0){
    newSize--;
    bits->size = newSize; 
  }
}

void doOperation(void (*function)(Bits*, const Bits*), Bits* bits, const Bits* mask)
{
  (*function)(bits, mask);
}

int to_decimal(const Bits* bits)
{
  int result = 0;
  for(int i =0; i<bits->size; i++)
  {
    if(bits->data[i]==1)
    {
        result+=pow(2,i);
    }
  }
  return result;
}