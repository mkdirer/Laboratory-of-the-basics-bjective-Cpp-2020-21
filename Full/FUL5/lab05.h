#pragma once

#include <iostream>

using namespace std;

struct node {
    char data[100];
    struct node* next = nullptr;
};

 struct List {
    node* head = nullptr;
};


void prepare(List*);

void add(List*, char*);

int empty(const List*);

void dump(const List*);

void clear(List*);
