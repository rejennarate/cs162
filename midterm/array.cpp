//array.cpp 

#include "array.h"

//put the implementations of your assigned functions here

int sumOfEvens(int list[], int size){
  //compute and return the sum of even integers in list
  int sum;

  for(int i = 0; i < size; i++){
    if(list[i] % 2 == 0) {
      sum = sum+list[i];
    }
  }

  cout << "The sum of all even numbers is: " << sum << endl;
  return sum;
}

void remove(int list[], int& size, int numOfInt){
  // remove the first “numOfInt” integers in the list and update the size of the list E.g.
  // remove(list, size, 5); will remove the first 5 integers in the list
  for(int j = 0; j < numOfInt; j++){
    list[j] = 0;
    // have to shift every index starting with numOfInt over numOfInt indices
    for (int k = numOfInt; k < size; k++) {
      list[k-numOfInt] = list[k];
    }
    // need to decrement the list after the numOfInt values have been moved

  }
}