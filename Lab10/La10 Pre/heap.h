//code get from lecture slides
//Wrote by Aaron Bloomfield, 2014
//Modified by Wenhao Xu
#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include "huffmanNode.h"
using namespace std;

class heap{
 public:
  heap();
  heap(vector<huffmanNode*> vec);
  ~heap();
  bool find(char x);
  huffmanNode* getNode(int i);
  huffmanNode* findMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  void print();
  void insert(huffmanNode* x);
  void percolateUp(int hole);
  void percolateDown(int hole);
  huffmanNode* deleteMin();

  
 private:
  vector<huffmanNode*> Heap;
  unsigned int heap_size;
  friend class huffmanNode;
  friend class huffmanTree;


};
#endif

