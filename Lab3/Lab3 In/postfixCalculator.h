#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include<iostream>
#include<stack>
using namespace std;

class postfixCalculator{
 public:
  postfixCalculator();

  ~postfixCalculator();

  void addition();

  void substraction();

  void multiplication();

  void division();

  void unary_negation();

  stack<int> calstack;
 
};

#endif
