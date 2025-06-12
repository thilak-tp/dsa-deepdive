#include<vector>
#include <iostream>
#include <climits>
// Given an array, find the maximum profit that can be got by buying a stock and selling it
using namespace std;



// Optimal Solution
int stockBuySell(vector <int> &arr) {
  
  int minPrice = INT_MAX;
  int maxPro = 0;
  
  for(int i=0; i<arr.size(); i++) {
    minPrice = min(minPrice, arr[i]);
    maxPro = max(maxPro, arr[i] - minPrice);
  }
  
  return maxPro;
}

int main(){

  vector <int> arr = {3,4,1,5,9};
  int n = arr.size();

  cout<<"Input Matrix"<<endl;
  for(int j=0;j<n; j++) {
     cout<<arr[j]<<" ";
  }
  
  int maxProfit = stockBuySell(arr);

  cout<<"The max profit would be "<<maxProfit<<endl;  
  return 0;
}
