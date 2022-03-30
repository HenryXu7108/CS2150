#include<iostream>
using namespace std;
#include<string>
#include<cmath>

int bitcount(int n, int count){
  if(n==0){return count;}
  if(n%2==1) return bitcount(n/2,count+1);
  else{return bitcount(n/2,count);}
}


string base_convert(string num, int sbase, int ebase){
  int dec=0;
  int j = 0;
  for(int i =num.length()-1; i>=0;i--){
    if(num[i]=='1'||num[i]=='2'||num[i]=='3'||num[i]=='4'||num[i]=='5'||num[i]=='6'||num[i]=='7'||num[i]=='8'||num[i]=='9'||num[i]=='0'){
    dec = dec + (num[i] - 48)*pow(sbase,j);
    j++;}
    else{dec = dec + (num[i] - 55)*pow(sbase,j);
    j++;}
      
  }
  string convert="";
  while(dec>0){
    convert = convert +to_string(dec%ebase);
    dec = dec/ebase;
  }
  string result = "";
  for(int k = convert.length()-1; k>=0;k--){
    result= result+convert[k];

  }
  return result;   
}



int main(int argc, char **argv){
  int A = atoi(argv[1]);
  string B = string(argv[2]);
  int C = atoi(argv[3]);
  int D = atoi(argv[4]);
  cout<< A<< " has "<< bitcount(A,0) << " bit(s)"<<endl;
  cout<< B  << " (base " << C<<") " <<"= "<<base_convert(B,C,D)<<" (base "<<D<<")"<<endl;

 return 0;
}
