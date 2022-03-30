#include <iostream>
#include <climits>
using namespace std;



void sizeOfTest(){
  int A;
  unsigned int B;
  float C;
  double D;
  char E;
  bool F;
  int * G;
  char*H;
  double*I;
  cout << "Size of int: " << sizeof(A)<<endl;
  cout << "Size of unsigned int: " << sizeof(B)<<endl;
  cout << "Size of float: " << sizeof(C)<<endl;
  cout << "Size of double: " << sizeof(D)<<endl;
  cout << "Size of char: " << sizeof(E)<<endl;
  cout << "Size of bool: " << sizeof(F)<<endl;
  cout << "Size of int*: " << sizeof(G)<<endl;
  cout << "Size of char*: " << sizeof(H)<<endl;
  cout << "Size of double*: " << sizeof(I)<<endl;

}

void overflow(){
  unsigned int a;
  a = UINT_MAX;
  unsigned int result = a + 1;
  cout<< a <<" + 1 = "<< result<<endl;
}

void outputBinary(unsigned int y){
  int binary[32];
  for(int k =0; k<=31; k++){
    binary[k] = 0;
   }
  int i = 0;
  while(y>0){
    binary[i] = y%2;
    y = y/2;
    i++;
  }
  for (int j = 31; j >=0; j--){
    cout << binary[j];
  }
  cout<<endl;

}

int main(){
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  //int a =5;
  //int b = 3;
  //int c = a >> b;
  //cout <<c;

}
