#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product(int,int);
extern "C" int power(int,int);

int main(){
  int num1;
  int num2;

  cout<<"Enter integer 1: ";
  cin >> num1;
  cout<<"Enter integer 2: ";
  cin >> num2;
  if (num1 <= 0 || num2 <= 0) {
        cerr << "Input integer must be greater than zero.\n";
        return 1;
    }
  int pro = product(num1,num2);
  int pow = power(num1,num2);


  cout<<"Product: "<<pro<<endl;
  cout<<"Power: "<<pow<<endl;

  return 0;
    }
