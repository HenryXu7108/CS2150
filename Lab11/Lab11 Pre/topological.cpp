//file open and read in string code from fileio2.cpp

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <algorithm>
using namespace std;
/**
 *@brief perform a topological sort
 *@return return the sorted list of items
 *@todo need to write acceptence test 
 *@authur Wenhao Xu
 *@file topological.cpp
 */

// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    string s1, s2;
    map<string, int> mapp;
    vector<pair<string, string>> adj;
    
    while(true){
      file >> s1;
      file >> s2;
      if(s1 =="0" | s2 =="0"){
	break;
      }
      adj.push_back(pair<string, string>(s1, s2));
      if(mapp.find(s1)->second == 0){
	mapp.insert(pair<string,int>(s1, 1));
      }
      if(mapp.find(s2)->second == 0){
	mapp.insert(pair<string,int>(s2, 2));
      }else{
	mapp.find(s2)->second += 1;
      }
    }
    
    // close the file before exiting
    file.close();
      
 
    vector<string> output;
    map<string, int>::iterator itr;
    vector<string> classVec;
    for(itr = mapp.begin(); itr!= mapp.end(); itr++){
      classVec.push_back(itr->first);
    }
    
    for(itr = mapp.begin(); itr != mapp.end(); itr++){
      if(itr->second-1 ==0){
	output.push_back(itr->first);
	for(int i = 0; i<adj.size(); i++){
	  if(adj[i].first == itr->first){
	    mapp.find(adj[i].second)->second -= 1;
	  }
	}
	//	mapp.erase(itr);
      }
    }
    

    for(int i =0; i< output.size(); i++){
      cout<< output[i]<<" ";
    }
    cout<<endl;
}//end main()
