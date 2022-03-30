#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "bankAccount.h"
using namespace std;


bankAccount::bankAccount(){
  balance = 0.00;
}
bankAccount::bankAccount(double amount){
  balance = amount;
}

bankAccount::~bankAccount(){}

double bankAccount::withdraw(double amount){
  if(balance >= amount){
    balance = balance - amount;
    return balance;
  }else{
    return balance;
  }
}

double bankAccount::deposit(double amount){
  balance = balance + amount;
  return balance;
}

double bankAccount::getBalance() const {
  return balance;
}
