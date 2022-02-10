#include <iostream>
#include "funkcje.h"
int wczytajLiczbeWyrazow()
{
	int liczba; //podana przez uzytkownika liczba wyrazow ciagu fib
	std::cout<<"podaj liczbe wyrazow ciagu fib\n";
	std::cin>>liczba;
	return liczba;
}
void wypiszBinarnie(int liczba)
{
	int tab[31];
	int i=0;
	int k=0;
	for(int o=0; o<31; o++)
	{
		tab[o] = 0;
	}
	while(liczba > 0)
	{
		if(liczba%2 == 1)
		{
			tab[i] = 1;
		}
		else
		{
			tab[i] = 0;
		}
		liczba = liczba / 2;
		i++;
	}
	
	for(int j = 30; j>=0; j--)
	{
		if(tab[j] == 1)
		{
			k++;		
		}
		if(k!=0)
		{
			std::cout<<tab[j];
		}
	}
}
int *inicjalizujCiagFibonacciego(const int numer)
{
	int *tablica = new int(numer);
	if(numer == 2)
	{
	tablica[0] = 1;
	tablica[1] = 1;
	return tablica;
	}
	else if(numer == 1)
	{
		tablica[0] = 1;
		return tablica;
	}
	else if(numer > 2)
	{
		tablica[0] = 1;
		tablica[1] = 1;
		for(int i=2; i<numer; i++)
		{
			tablica[i] = tablica[i-1] + tablica[i-2];
		}	
		return tablica;
	}
	else
	{
		std::cout<<"bledna liczba wyrazow\n";
		return NULL;
	}
}
void wypisz(const int *tab, int numer)
{
	for(int i=0; i<numer; i++)
	{
		std::cout<<*(tab+i)<<",  ";
	}
	std::cout<<"\n";
}
void suma(const int *tab, int numer)
{
	if(tab != NULL)
	{
		int suma=0;
		for(int i=0; i<numer; i++)
		{
			suma += tab[i];
		}
		std::cout<<"suma: "<<suma<<"\n";
	}
	else
	{
		std::cout<<"bledna tablica\n";
	}
}
void iloczyn(const int *tab, int numer)
{
	if(tab != NULL)
	{
		int iloczyn = 1;
		for(int i=0; i<numer; i++)
		{
			iloczyn *= tab[i];
		}
		std::cout<<"iloczyn: "<<iloczyn<<"\n";
	}
	else
	{
		std::cout<<"bledna tablica\n";
	}
}
void suma(const int *tab1, int numer1, const int *tab2, int numer2)
{
		if(tab1 != NULL && tab2 != NULL)
	{
		int suma=0;
		for(int i=0; i<numer1; i++)
		{
			suma += tab1[i];
		}
		for(int i=0; i<numer2; i++)
		{
			suma += tab2[i];
		}
		std::cout<<"suma dwoch tablic: "<<suma<<"\n";
	}
}
void max(const int *tab1, int numer1, const int *tab2, int numer2)
{
	if(numer1 > numer2)
	{
		std::cout<<"maximum: "<<tab1[numer1-1]<<"\n";
		wypisz(tab1,numer1);
		std::cout<<"(ciag1)";
	}
	if(numer1 == numer2)
	{
		std::cout<<"ciagi sa rowne\n";
	}
	if(numer1 < numer2)
	{
		std::cout<<"maximum: "<<tab2[numer2-1]<<"\n";
		wypisz(tab2,numer2);
		std::cout<<"(ciag2)";
	}
}
void UsunCiag(const int *tab)
{
	delete tab;
}






