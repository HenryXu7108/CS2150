#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class hashTable{
 public:
  hashTable(int size);
  
  void insert(string word);
  bool find(string word);
  bool checkprime(unsigned int p);
  int getNextPrime(unsigned int n);
  vector < list<string> > table;

 private:
  int tableSize;
  int hashindex(string word);

  
};





#endif
