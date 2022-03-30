// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
//Code getting from lecture slides
//Modified by Wenhao Xu
//heap.cpp
#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    Heap.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    Heap = vec;
    Heap.push_back(Heap[0]);
    Heap[0] = 0;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}
bool heap::find(char x){
  for (int i = 1; i < heap_size; i++) {
 
    if(Heap[i]->chara == x){
      Heap[i]->freq += 1;
      return true;
    }
  }
  return false;
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    Heap.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
      // get the value just inserted
    huffmanNode* x = Heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x->freq < Heap[hole/2]->freq); hole /= 2) {
        Heap[hole] = Heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    Heap[hole] = x;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = Heap[1];
    // move the last inserted position into the root
    Heap[1] = Heap[heap_size--];
    // make sure the vector knows that there is one less element
    Heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}
huffmanNode* heap::getNode(int i){
  return Heap[i];
}
huffmanNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return Heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    Heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    for (int i = 1; i <=heap_size; i++) {
      cout << Heap[i]->chara <<Heap[i]->freq<<endl;
      
        // next line from http://tinyurl.com/mf9tbgm
        //bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        //if (isPow2) {
      //cout << endl << "\t";
	    //}
    }
    //cout << endl;
}


void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode* x = Heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (Heap[child+1]->freq < Heap[child]->freq)) {
            child++;
        }
        // if the child is greater than the node...
        if (x->freq > Heap[child]->freq) {
            Heap[hole] = Heap[child]; // move child up
            hole = child;             // move hole down
	   
	}else{
	  break;
	}
    }
     Heap[hole] = x;
}
