#include "lab05.h"
#include <iostream>
#include <cstring>

void prepare(List* lista)
{
  lista->head=nullptr;
}

void add(List *lista, char dane[])
{
  node *newElem = new node;
  strcpy(newElem->data, dane);
  if(lista->head == nullptr)
  {
    lista->head=newElem;
  }else{
    node* ptr = lista->head;
    while(ptr->next != nullptr)
    {
      ptr=ptr->next;
    }
    ptr->next = newElem;
  }
}

int empty(const List* lista)
{
  if(lista->head != nullptr) return 0;
  else return 1;
}

void dump(const List* lista)
{
  if(lista->head != nullptr)
  {
    node* ptr = lista->head;
    while(ptr->next != nullptr)
    {
      cout<<ptr->data<<" ";
      ptr = ptr->next;
    }
    cout<<ptr->data;
  }
}

void clear(List* lista)
{
  struct node* elem = lista->head;
  struct node* elem2 = elem->next;
  while(elem2->next != nullptr)
  {
    delete elem;
    elem= elem2;
    elem2 = elem2->next;
  }
  delete elem;
  delete elem2;
  lista->head=nullptr;
}
