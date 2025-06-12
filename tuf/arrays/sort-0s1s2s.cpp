#include<vector>
#include <iostream>
#include <climits>
// Given an array of 0s 1s and 2s, sort them
using namespace std;

// Brute Force Approach
void sort0s1s2sBF(vector <int> &arr) {
  // Individually count the number of 0s 1s and 2s
  int cnt0 = 0, cnt1 = 0, cnt2 = 0;
  for(auto it: arr) {
    if(it == 0) cnt0++;
    else if(it == 1) cnt1++;
    else if(it == 2) cnt2++;
  }
  
  int size = arr.size();
  for(int i=0; i<cnt0; i++) arr[i] = 0;
  for(int i=cnt0; i< cnt0 + cnt1; i++) arr[i] = 1;
  for(int i= cnt1+cnt0; i<size; i++) arr[i] = 2;

}
// Optimal Solution
void sort0s1s2sOS(vector <int> &arr) {
   
  int size = arr.size();
  int mid = 0, low = 0, high = size -1;
  
  while(mid <= high) {
    if(arr[mid] == 0) {
      swap(arr[mid], arr[low]);
      low++;
      mid++;
    }
    else if(arr[mid] == 1) {
      mid++;
    }
    else {
      swap(arr[mid], arr[high]);
      high--;
    }
  } 
}
int main(){

  vector <int> arr = {1,0,2,2,0,0,1,1};
  int n = arr.size();

  cout<<"Input Matrix"<<endl;
  for(int j=0;j<n; j++) {
     cout<<arr[j]<<" ";
  }
  
  sort0s1s2sOS(arr);

  cout<<"Output Matrix"<<endl;
  for(int i=0; i<n; i++) {
      cout<<arr[i]<<" ";
  }

  return 0;
}
