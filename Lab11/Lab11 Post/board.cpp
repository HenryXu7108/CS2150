#include "board.h"
#include<iostream>
#include<vector>
using namespace std;


board::board(){}

board::board(vector<int> vec){
  boardVec = vec;

  
}
/**
 *@brief setboard with new vector
 *@param new vector
 */
void board::setBoard(vector<int> vec){
  boardVec = vec;

}
/**
 *@brief print out the board
 */
void board::printBoard(){
  cout<<boardVec[0]<< " "<<boardVec[1]<<" "<<boardVec[2]<<endl;
  cout<<boardVec[3]<< " "<<boardVec[4]<<" "<<boardVec[5]<<endl;
  cout<<boardVec[6]<< " "<<boardVec[7]<<" "<<boardVec[8]<<endl;

}
/**
 *@brief check if the board can be solved
 *@return bool value true if unsolveble, false otherwise
 */
bool board::impossible(){
  int inversion =0;
  bool result = false;
  if(boardVec.size()==0){
    throw"Board contains nothing";
  }
  for(int i =0; i<8; i++){
    for(int j =i+1; j<9; j++){
      if(boardVec[i] > boardVec[j] && boardVec[i] != 0 && boardVec[j] !=0){
	inversion +=1;
      }
    }
  }
  if(inversion % 2 ==0){
    result = false;
  }else{
    result = true;
  }
  return result;
}

/**
 *@brief get the possible swap index of the board depending on positon of hole
 *@return a vector with index of zero at [0] and followed by possible swap index
 */
vector<int> board::swapIndex(){
  vector<int> swapIndex;

  int zeroindex = -1;
  for(int i = 0; i<boardVec.size();i++){
    if(boardVec[i] == 0){
      zeroindex = i;
    }
  }

  switch(zeroindex){
  case 0:
    swapIndex = {0,1,3};//{zeroindex,swapindex}
    break;
  case 1:
    swapIndex = {1,0,2,4};
    break;
  case 2:
    swapIndex = {2,1,5};
    break;
  case 3:
    swapIndex = {3,0,4,6};
    break;
  case 4:
    swapIndex = {4,1,3,5,7};
    break;
  case 5:
    swapIndex = {5,2,4,8};
    break;
  case 6:
    swapIndex = {6,3,7};
    break;
  case 7:
    swapIndex = {7,4,6,8};
    break;
  case 8:
    swapIndex = {8,5,7};
    break;
  }
  return swapIndex;
}

/**
 *@brief get the possible states after one move of the current board
 *@return a vector of vector<int>(boards) that are possible after one move
 */
vector<vector<int>> board::next(){
  vector<int> vec = swapIndex();
  vector<vector<int>> next;
  int zeroid = vec[0];

  for(int i = 1; i<vec.size();i++){
    vector<int> temp = boardVec;
    temp[zeroid] = temp[vec[i]];
    temp[vec[i]] = 0;
    next.push_back(temp);	       
  }
  return next;
}
