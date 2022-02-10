#include "lab3.h"

int abs(int n)
{
  return (n>=0 ? n: -n);
}

int* initFibonacci(const int n)
{
  int* ciag = new int [n-1];
  for(int i=0; i<=n; i++)
  if(i==0)
  {
    *(ciag+i)=0;
  }else if(i==1)
  {
    *(ciag+i)=1;
  }else
  {
    *(ciag+i)=ciag[i-2]+ciag[i-1];
  }
  return ciag;
}

void print(const int* sequence,const int abs_n)
{
  cout<<"(";
  for(int i=0; i<=abs_n; i++)
  {
    cout<<sequence[i]<<", ";
  }
  cout<<")";
}

void deleteSequence(const int* sequence)
{
  delete[] sequence;
}


void addSequence(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow, int n)
{
  n=abs(n);
  if(*lista_ciagow==NULL)
  {
    int** ciagi = (int**)malloc(sizeof(int**));
    *lista_ciagow=ciagi;
  }
  
  int *ciag = initFibonacci(n);
  int** ciagi = (int**)realloc(*lista_ciagow, sizeof(int*)*(*ilosc_ciagow+1));
  *lista_ciagow=ciagi;
  (*lista_ciagow)[*ilosc_ciagow]=ciag;
  *ile_wyrazow=(int*)realloc(*ile_wyrazow, sizeof(int)*(*ilosc_ciagow+1));
  (*ile_wyrazow)[*ilosc_ciagow]=n;
  (*ilosc_ciagow)++;
}

void printSequence(int** lista_ciagow,int* ile_wyrazow, int n)
{
  cout<<"ciag nr"<<n<<": (";
  int dlugosc = ile_wyrazow[n];
  int* ciag= lista_ciagow[n];
  if(dlugosc>=0)cout<<ciag[0];
  for(int a=1; a<=dlugosc; a++)
  {
    cout<<", "<<ciag[a];
  }
  cout<<")\n";
}

void printAllSequences(int** lista_ciagow,int* ile_wyrazow,int ilosc_ciagow)
{
  for(int a=0; a<ilosc_ciagow; a++)
  {
    printSequence(lista_ciagow,ile_wyrazow,a);
  }
}

void swapSequence(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow, int n)
{
  int* ciag =(*lista_ciagow)[n];
  for(int a=0; a<(*ile_wyrazow)[n]/2;a++)
  {
    int temp = ciag[a];
    ciag[a]=ciag[(*ile_wyrazow)[n]-a];
    ciag[(*ile_wyrazow)[n]-a]=temp;
    print(ciag, (*ile_wyrazow)[n]);
  }
}

void deleteSequences(int* ilosc_ciagow,int*** lista_ciagow,int** ile_wyrazow)
{
  for(int i=0; i<*ilosc_ciagow; i++)
  {
    delete[](*lista_ciagow)[i];
  }
  free(*lista_ciagow);
  free(*ile_wyrazow);
}