#include "huffmanNode.h"
using namespace std;

huffmanNode::huffmanNode(){
  left = NULL;
  right = NULL;
  chara = (char) 0;
  freq = 1;
  prefix = "";
  

}

huffmanNode::huffmanNode(int FREQ, char CHARA){
  freq = FREQ;
  chara = CHARA;
  prefix = "";
  left = NULL;
  right = NULL;

}
huffmanNode::~huffmanNode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}

