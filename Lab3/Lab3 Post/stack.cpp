#include <iostream>
#include <string>
#include "stack.h"
#include"List.h"
#include"ListItr.h"
using namespace std;

stack::stack(){
  listStack = List();
}

stack::~stack(){}

void stack::push(int e){
  listStack.insertAtTail(e);

}

void stack::pop(){
  listStack.deleteLast();
  
}

int stack::top(){
  ListItr temp;
  temp = listStack.last();
  int x = temp.retrieve();
  return x;
  
}

bool stack::empty() const {
  return (listStack.size() == 0);
}
