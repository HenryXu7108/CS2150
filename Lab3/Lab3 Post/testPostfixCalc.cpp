#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

#include "postfixCalculator.h"

int main(){
  string token;
  postfixCalculator postfixCalculator;
  while (cin >> token) {
    if(token == "+"){
      postfixCalculator.addition();
    }
    else if(token == "-"){
      postfixCalculator.substraction();
    }
    else if(token == "*"){
      postfixCalculator.multiplication();
    }
    else if(token == "/"){
      postfixCalculator.division();
    }
    else if(token == "~"){
      postfixCalculator.unary_negation();
    }else{
      int num = stoi(token);
      postfixCalculator.calstack.push(num);

    }
    
  }
  cout<<postfixCalculator.calstack.top()<<endl;
  postfixCalculator.calstack.pop();
}





  
