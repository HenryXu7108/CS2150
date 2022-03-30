#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include<iostream>
#include"stack.h"



class postfixCalculator{
 public:
  postfixCalculator();

  ~postfixCalculator();

  void addition();

  void substraction();

  void multiplication();

  void division();

  void unary_negation();

  :: stack calstack;

private:
  

  friend class testPostCalc;
};

#endif
