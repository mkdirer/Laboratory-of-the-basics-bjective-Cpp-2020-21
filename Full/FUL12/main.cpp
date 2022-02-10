/*
 * Do napisania jest kontener typu lista, trzymająca liczby całkowite.
 * 
 * Celem jest przygotowanie wielu różnych konstruktorów, pozwalających
 * na tworzenie takich list w różny sposób. Proszę zadbać o odpowiednią
 * implementacje konstruktorów, wykorzystanie list inicjalizujących,
 * zaimplementować konstruktor kopiujący przenoszący etc.
 * 
 * Aby użyć std::initializer_list<int> należy załadowąć nagłówek:
 * #include <initializer_list>
 * 
 * Implementując liste, warto trzymać informacje o początku (head)
 * jak i końcu listy (tail). Przyda się też trzymać jej rozmiar.
 * 
 * Zadanie jest nieoceniane. Poszczególne fragmenty można implementować
 * w dowolnej kolejności.
 */


#include "MyList.h"
#include <iostream>


///////////////////////////////////////////////////////////////
// Funkcja służąca do opisu listy, sprawdzająca czy jest pusta,
// wypisująca długość listy i jej zawartość, wykorzystuje 
// funkcje składowe MyList: empty, size i print         
void describeList(const MyList & l);                        

// Funkcja generująca listę zawierającą liczby od 0 do n-1    
// (w celu pokazania konstrukotra przenoszącego)              
MyList generateList(int n);                                   

// Funkcje generujące kolejne wartości na podstawie poprzednich:
int genNextAdd(MyNode * node);                                
int genNextMul(MyNode * node);                                
///////////////////////////////////////////////////////////////


int main()
{  
    
    std::cout << "\n---> Konstruktor bezparametrowy <---" << std::endl;
    {
        // Tworzy pustą listę
        MyList l;
        describeList(l);    
    }
    
    std::cout << "\n---> Konstruktor jednoparametrowy <---" << std::endl;
    {
        // Tworzy listę kolejnych liczb, zaczynając od zera
        // Jest to konstruktor delegujący (tak jak i inne poniżej)
        MyList l(3);
        describeList(l);
        
        // Liste można wyczyścić przed destruktorem,
        // ale wciąż wszystko powinno działać.
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.clear();
        describeList(l);
    }
    
    std::cout << "\n---> Konstruktor z lista inicjalizacyjna <---" << std::endl;
    {
        // Tworzy listę na podstawie przesłanej kombinacji
        // Konstruktor do napisania w oparciu o std::initializer_list<T>
        MyList l{1, 3, 5, 7, 9};
        describeList(l);
        
        // Po wyczyszczeniu listy, wciąż można dodawać elementy
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.clear();
        describeList(l);
        l.add(77);
        describeList(l);
    }
    
    std::cout << "\n---> Uwaga na następujace pulapki <---" << std::endl;
    {
        // Różne pułapki
        MyList l();
        std::cout << "To nie jest konstrukcja obiektu: \"MyList l();\"" << std::endl;
        std::cout << "Nie wywolal się konstruktor! \"l\" to funkcja!" << std::endl;
                
        std::cout << "Konstrukcja przy uzyciu nawiasow okraglych:" << std::endl;
        MyList l1(3);
        describeList(l1);
        
        std::cout << "Konstrukcja przy uzyciu nawiasow klamrowych:" << std::endl;
        MyList l2{3};
        describeList(l2);
        
        std::cout << "Powstaly dwa obiekty o roznaych rozmiarach!" << std::endl;
    }
    
    std::cout << "\n---> Konstruktor kopiujacy <---" << std::endl;
    {
        // Konstruktor do skopiowania
        MyList l(3);
        describeList(l);
        
        MyList copy = l;
        describeList(l);
        describeList(copy);
        
        // Modyfikujemy bazę:
        std::cout << "m.o.d.y.f.i.k.a.c.j.e" << std::endl;
        l.add(8);
        describeList(l);
        describeList(copy);
    }
    
    std::cout << "\n---> Konstruktor przenoszacy <---" << std::endl;
    {   //Prosze użyć std::exchange  

        // Wykorzystanie funkcji generującej  
        MyList move = generateList(4);
        describeList(move);
        
        // Wykorzystanie std::move
        std::cout << "\nstd::move" << std::endl;
        MyList l(3);
        describeList(l);
        
        MyList stdmove = std::move(l);
        describeList(l);
        describeList(stdmove);
    }
    
    std::cout << "\n---> Uwaga na nastepujace pulapki <---" << std::endl;
    {     
        // Tutaj uwaga: sama funkcja generujaca nie wywołuje
        // ani konstruktora kopiującego ani przenoszącego!
        // Zadziałał mechanizm RVO: return value optimization
        generateList(5);
        std::cout << "Nie ma kopiowania!" << std::endl;
    }
    
    std::cout << "\n---> Skomplikowany konstruktor <---" << std::endl;
    {     
        // Tu nie ma niejasności, mimo różnicy w nawiasach wiadomo
        // który konstruktor wywołać
        MyList addL(genNextAdd, 5);
        describeList(addL);
        
        MyList addM{genNextMul, 5};
        describeList(addM);
        
    }
                
    return 0;
}

void describeList(const MyList & l)
{
    std::cout << "List: ";
    if(l.empty())
    {
        std::cout << "empty";
    }
    else
    {
        std::cout << "size = " << l.size();
    }
    std::cout << " : ";
    l.print();
}

MyList generateList(int n)
{
    MyList l(n);
    return l;
}

int genNextAdd(MyNode * node)
{
    return node ? node->val() + 2 : 0;
}

int genNextMul(MyNode * node)
{
    return node ? node->val() * 2 : 1;
}    
