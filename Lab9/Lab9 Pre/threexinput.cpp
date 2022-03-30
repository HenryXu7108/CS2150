/*Test file for threexplusone
 */

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int threexplusone(int x);

int main() {
  int input;
  cout<<"Enter a number: ";
  cin>>input;
  
  int times;
  cout<<"Enter iterations of subroutine: ";
  cin>>times;

  int result = threexplusone(input);

  timer t;
  t.start();
   for(int i = 0; i<times; i++){
    threexplusone(input);
  }
  t.stop();
  
  double time = t.getTime();
  //cout<<time/(double)times << " seconds"<<endl;

  cout<< "Steps: " << result<<endl;

  return 0;
}
