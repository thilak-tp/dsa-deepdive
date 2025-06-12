#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Brute Force
int maxConsSubarraySum(int *arr, int size) {
  int maxSum = INT_MIN;
  for(int i=0; i<size; i++) {
    for(int j=i; j<size; j++) {
      int sum = 0;
      for(int k=i; k<=j; k++)   sum += arr[k];
      maxSum = max(maxSum, sum);
    }

  }
  return maxSum;
}

int maxConsSubarraySumKadane(int *arr, int size) {
  int maxSum = INT_MIN;
  int sum = 0;
  for(int i=0; i<size; i++) {
    sum += arr[i];

    maxSum = max(maxSum, sum);
    if(sum < 0) sum =0;
  }
  return maxSum;
}
int main() {
  int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
  int size = 9;
  int sum = maxConsSubarraySum(arr,size);  
  cout<<"The max consecutive subarray sum is "<<sum<<endl;
  return 0;
}
