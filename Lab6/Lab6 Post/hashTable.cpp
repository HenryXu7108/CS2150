#include "hashTable.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

hashTable::hashTable(int size){
  if(checkprime(size) == true){
    tableSize = size*2;
  }else{
    tableSize = getNextPrime(size*2);
  }
  list<string> list;
  for (int i = 0; i<tableSize;i++){
    table.push_back(list);
  }


}

//from primenumber.cpp//
bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}
//from primenumber.cpp//
int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}

int hashTable::hashindex(string word){
  unsigned long i =0;
  unsigned long x =1;
  for (int j =0; j<word.length();j++){
    i += (int)word[0]*x;
    x = x*7;
  }

  return i % tableSize;
}

void hashTable::insert(string word){
  if(word.length()>2){
    table[hashindex(word)].push_back(word); 
  }
}
bool hashTable::find(string word){
  int index = hashindex(word);
  list<string>::iterator i = table[index].begin();
  for( i ; i != table[index].end();i++){
    if(*i == word){
      return true;
    }
  }
  return false;

}


