#include <iostream>
#include <string>
#include "huffmanNode.h"
#include "heap.h"
#include "huffmanTree.h"

huffmanTree::huffmanTree(huffmanNode* Root){
  root = Root;
}

huffmanTree::~huffmanTree(){}

void huffmanTree::printAndMap(huffmanNode* Root, string code){
  if(Root->chara != (char) 0){
    Root->prefix = code;
    mapping.insert(pair<char, string>(Root->chara, Root->prefix));//i.e.(a 01)
    if(isspace(Root->chara) == true){
      cout<< "space" << " " << Root->prefix << endl;
    }else{
      cout<< Root->chara << " " << Root->prefix << endl;
    }
  }else{
    if(Root->left != NULL){
      string Code = code;
      Code += "0";
      printAndMap(Root->left,Code);
    }
    if(Root->right != NULL){
      string Code = code;
      Code += "1";
      printAndMap(Root->right,Code);
    }
    
  }
}
