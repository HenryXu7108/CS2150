//huffmanenc.cpp
//code modified from fileio.cpp
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include "huffmanNode.h"
#include "heap.h"
#include "huffmanTree.h"
#include <bits/stdc++.h>
using namespace std;
//compare two pairs of<charactor, frequence>
//inspried from "geeksforgeeks.org/sorting-a-vector-in-c/"
bool cmp(pair<char, int>& x, pair<char, int>& y){
  return x.second < y.second;
}

int main(int argc, char** argv){
  // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    char g;
    heap testheap;
    string input = "";
    int ascii[126] = {0};
    int numSymbols = 0;
    while (file.get(g)) {
        cout << g;
	input += g;
	int ASCIInum = (int)g;
	if(ASCIInum > 31 && ASCIInum <127){
	  ascii[ASCIInum] += 1;
	  numSymbols ++;
	}
    
    }
    for(int i = 32;i<126; i++){
      if(ascii[i]!= 0){
	testheap.insert(new huffmanNode(ascii[i], (char) i));
      }
    }
    
    map <char, int> mapp;
    

    
    for(int i =1; i<=testheap.size();i++){
      mapp.insert(pair<char, int>(testheap.getNode(i)->chara, testheap.getNode(i)->freq));
    }
    
    vector<pair<char, int>> vec;
    
    map<char, int>::iterator itr;
    
    for(itr = mapp.begin(); itr !=mapp.end(); itr++){
      vec.push_back(pair<char, int>(itr->first, itr->second));
    }
 
    sort(vec.begin(), vec.end(), cmp);
    vector<char> charvec;
    vector<int> freqvec;
    
    for(int i =0; i<vec.size(); i++){
      charvec.push_back(vec[i].first);
      freqvec.push_back(vec[i].second);
      
    }
    heap finalHeap;
    vector<huffmanNode*> nodeVec;
    for(int k = 0; k<charvec.size(); k++){
      huffmanNode* n = new huffmanNode(freqvec[k], charvec[k]);
      finalHeap.insert(n);
      nodeVec.push_back(n);
    }
    

    int distinctSymbol = finalHeap.size();
    while(finalHeap.size()>1){
      huffmanNode* node1 = finalHeap.deleteMin();
      huffmanNode* node2 = finalHeap.deleteMin();
      huffmanNode* upperNode = new huffmanNode(node1->freq+node2->freq, (char) 0);
      upperNode->left=node1;
      upperNode->right=node2;
      finalHeap.insert(upperNode);
    
    }

    huffmanTree tree = huffmanTree(finalHeap.getNode(1));
    tree.printAndMap(finalHeap.getNode(1), "");
    cout << "----------------------------------------" << endl;
    string compressedOutput ="";
    for(int i= 0; i<input.length(); i++){
      cout<< tree.mapping[input[i]]<< " ";
      compressedOutput += tree.mapping[input[i]];
    }
    cout<<endl;
    cout << "----------------------------------------" << endl;
    int bitCompressed = compressedOutput.length();
    
    // once we hit the end of the file we are marked as "failed", so clear that
    // then "seek" to the beginning of the file to start again
    file.clear(); // Clears the _state_ of the file, not its contents!
    file.seekg(0);
    cout<<"There are a total of "<< numSymbols << " symbols that are encoded." <<endl;
    cout<<"There are "<< distinctSymbol << " distinct symbols used." <<endl;
    cout<<"There were "<< numSymbols*8 << " bits in the original file." <<endl;
    cout<<"There were "<< bitCompressed<< " bits in the compressed file." <<endl;
    float compressionRatio = (float)numSymbols*8/(float)bitCompressed;

    float costTotal = 0.0;
    for(int i=0; i<nodeVec.size(); i++){
      costTotal += nodeVec[i]->prefix.length()*nodeVec[i]->freq;
    }
    float cost = costTotal/(float)numSymbols;
    
    cout<<"This gives a compression ratio of "<< compressionRatio <<endl;
    cout<<"The cost of the Huffman tree is " << cost << " bits per character" <<endl;

    // close the file
    file.close();

    return 0;
}
