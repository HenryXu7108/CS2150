#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include <stack>
using namespace std;

postfixCalculator::postfixCalculator(){
  stack<int> calstack;
}

postfixCalculator::~postfixCalculator(){
  
}


void  postfixCalculator::addition(){
  int a = calstack.top();
  calstack.pop();
  int b = calstack.top();
  calstack.pop();
  calstack.push(a+b);

  
}

void  postfixCalculator::substraction(){
  int a = calstack.top();
  calstack.pop();
  int b = calstack.top();
  calstack.pop();
  calstack.push(b-a);

}


void postfixCalculator::multiplication(){
  int a = calstack.top();
  calstack.pop();
  int b = calstack.top();
  calstack.pop();
  calstack.push(a*b);
}


void postfixCalculator::division(){
  int a = calstack.top();
  calstack.pop();
  int b = calstack.top();
  calstack.pop();
  calstack.push(b/a);
}


void postfixCalculator::unary_negation(){
  int a = calstack.top();
  calstack.pop();
  a = a*-1;
  calstack.push(a);
}


