#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
#include <string>
using namespace std;

class huffmanNode{
 public:
  huffmanNode();
  huffmanNode(int FREQ, char CHARA);
  ~huffmanNode();
  huffmanNode* left;
  huffmanNode* right;
  int freq;
  string prefix;
  char chara;

  friend class huffmanTree;
  friend class heap;
};
#endif
