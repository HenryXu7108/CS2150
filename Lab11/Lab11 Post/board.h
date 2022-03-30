#ifndef BOARD_H
#define BOARD_H

#include<vector>
#include<iostream>
using namespace std;

class board{
 public:
  board();
  board(vector<int> vec);
  void setBoard(vector<int> vec);
  void printBoard();
  vector<int> boardVec;
  bool impossible();
  vector<int> swapIndex();
  vector<vector<int>> next();
};
#endif
