//  algorithm (pseudo code) 
/*  countingSort(array, size)
    max - find largest element in array
    initialize count array with all zeros
    for j - 0 to size
    find the total count of each unique element and 
    store the count at jth index in count array
    for i - 1 to max
    find the cumulative sum and store it in count array itself
    for j - size down to 1
    restore the elements to array
    decrease count of each element restored by 1 */
// Counting sort in C++ programming

#include <iostream>
using namespace std;

void countSort(int array[], int size) {
    // providing size of array statically 
    //one can use dynamic allocation also according to need
  int outputarray[10];
  int countarray[10];
  int max = array[0];

  // largest element 
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

// setting count array elements to "0"
  for (int i = 0; i <= max; ++i) {
    countarray[i] = 0;
  }

 // storing count of each element
  for (int i = 0; i < size; i++) {
    countarray[array[i]]++;
  }

  // Storing the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    countarray[i] += countarray[i - 1];
  }

  // Finding the index of each element of the original array in count array, and
  // placing the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    outputarray[countarray[array[i]] - 1] = array[i];
    countarray[array[i]]--;
  }

  // Copying the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = outputarray[i];
  }
}

//printing the array
void print(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

//main code
int main() {
    int n =8;
  int array[]= {8,9,4,2,5,6,7,6};
  countSort(array, n);
  print(array, n);
  return 0;
}
