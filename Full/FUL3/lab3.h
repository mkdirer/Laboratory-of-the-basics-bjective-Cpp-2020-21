#pragma one
#include <iostream>

using namespace std;

int abs(int n);
int* initFibonacci(const int abs_n);
void print(const int* sequence,const int abs_n);
void deleteSequence(const int* sequence);
void addSequence(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow, int n);
void printSequence(int** lista_ciagow,int* ile_wyrazow, int n);
void printAllSequences(int** lista_ciagow,int* ile_wyrazow,int ilosc_ciagow);
void swapSequence(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow, int n);
void deleteSequences(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow);