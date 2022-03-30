#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include <string>
#include "huffmanNode.h"
#include "heap.h"
#include <map>
using namespace std;

class huffmanTree{
 public:
  huffmanTree(huffmanNode* Root);
  ~huffmanTree();
  void printAndMap(huffmanNode* Root, string code);
  map<char, string> mapping;

private:
  huffmanNode* root;
};
#endif
