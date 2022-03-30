//puzzle.cpp
#include<iostream>
#include<sstream>
#include"board.h"
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
/**
 *@brief solve a puzzle game with minimum steps
 *@author Wenhao Xu
 *@file puzzle.cpp
 *@todo need to write acceptence tests
 *@return the minimum step it takes to solve the input puzzle
 */
int main(){
  string line1;
  string line2;
  string line3;
  cout<< "Enter puzzle"<<endl;
  getline(cin, line1);
  getline(cin, line2);
  getline(cin, line3);
  
  vector<int> vec;
  vec.push_back(line1[0]-48);
  vec.push_back(line1[2]-48);
  vec.push_back(line1[4]-48);
  vec.push_back(line2[0]-48);
  vec.push_back(line2[2]-48);
  vec.push_back(line2[4]-48);
  vec.push_back(line3[0]-48);
  vec.push_back(line3[2]-48);
  vec.push_back(line3[4]-48);
  board Board(vec);

  vector<int> endState = {1,2,3,4,5,6,7,8,0};
  if(Board.boardVec == endState){
    cout<<"Solving puzzle"<<endl;
    cout<<"0"<<endl;
    return 0;
  }


  if(Board.impossible() == true){
    cout<<"Solving puzzle"<<endl;
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
  }


  
  map<vector<int>, int> map;
  map.insert(pair<vector<int>, int>(vec, 0));
	     
  bool end = false;
  queue<vector<int>> que;
  que.push(vec);

  while(end == false){
    vector<int> curstate= que.front();
    Board.setBoard(curstate);
 
    que.pop();
    vector<vector<int>> nextStates = Board.next();

    if(curstate == endState){
      end = true;
      cout<<"Solving puzzle"<<endl;
      cout<<map[curstate]<<endl;
      return 0;
    }else{
 
      for(int i =0; i<nextStates.size();i++){
 
	vector<int> temp = nextStates[i];
	if(map.count(temp) == 0 ){
	  map[temp] = map[curstate]+1;
	  que.push(temp);
	 
	}
      }
      
   
    }
 
    
  }//end while loop
  
  while(!que.empty()){
    que.pop();
  }//clear queue
  
  

  
  return 0;
}
