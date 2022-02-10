#pragma once 

struct Bits{
  int data[32]={0};
  int size;
};

void set(Bits*, const int*, int);
void print(const Bits*);
Bits add_up(const Bits*, const Bits*);
void bit_and(Bits*, const Bits*);
void bit_xor(Bits*, const Bits*);
void doOperation(void (*f)(Bits*, const Bits*), Bits*, const Bits*);
int to_decimal(const Bits*);