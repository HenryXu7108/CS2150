// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  expressionStack = stack<TreeNode*>();
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  if(expressionStack.size() != 0){
  cleanTree(expressionStack.top());
  expressionStack.pop();
  }
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if (tree != NULL){
    if(tree->left != NULL || tree->right != NULL){
      if (tree->left != NULL){
	cleanTree(tree->left);
	tree->left = NULL;
      }
      if (tree->right != NULL){
	cleanTree(tree->right);
	tree->right = NULL;
      }
    }
    
  }
  delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
  if (val == "+" || val == "-" || val == "*" || val == "/"){
    TreeNode * sign = new TreeNode(val);
    TreeNode * num1 = expressionStack.top();
    expressionStack.pop();
    TreeNode * num2 = expressionStack.top();
    expressionStack.pop();
    sign->left = num2;
    sign->right = num1;
    expressionStack.push(sign);
	
  
  }
  else{
    TreeNode * num = new TreeNode(val);
    expressionStack.push(num);	         
  }

  
 
  
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if (tree != NULL){
    cout<< " " << tree->value;
    printPrefix(tree->left);
    printPrefix(tree->right);

  }
  
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
  if (tree != NULL){
    if(tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/"){
      cout<<" (";
    }
    printInfix(tree->left);
    cout<< " " << tree->value;
    printInfix(tree->right);
    if(tree->value == "+" || tree->value == "-" || tree->value == "*" || tree->value == "/"){
      cout<<") ";
    } 
  }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if (tree != NULL){
      printPostfix(tree->left);
      printPostfix(tree->right);
      cout<< " " << tree->value;
  }
  
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
  int result;
  if(tree->left == NULL && tree->right == NULL){
    return stoi(tree->value);
  }else{
  if(tree->value == "+"){
    int num1 = calculate(tree->left);
    int num2 = calculate(tree->right);
    result = num1 +num2;
  }else if(tree->value == "-"){
    int num1 = calculate(tree->left);
    int num2 = calculate(tree->right);
    result = num1 -num2;
  }else if(tree->value == "*"){
    int num1 = calculate(tree->left);
    int num2 = calculate(tree->right);
    result = num1 *num2;
  }else if(tree->value == "/"){
    int num1 = calculate(tree->left);
    int num2 = calculate(tree->right);
    result = num1 /num2;
  }


 }
    return result;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
  int result = calculate(expressionStack.top());
    return result;
}
