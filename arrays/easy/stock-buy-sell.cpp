#include<iostream>
#include<climits>
// A C++ program to check the best profitable buy and sell order
using namespace std;

// A function to populate an array
//O(N)
int populateArray(int *arr)
{

  int n;
  cout<<"Enter the number of elements "<<endl;
  cin>>n;
  cout<<"Enter "<<n<<" number of elements"<<endl; 
  
  for(int i=0; i<n; i++)
    cin>>arr[i];

    
  return n;
}
// To display the elements in the given array
//O(N)
void displayArray(int n, int *arr)
{
  for(int i=0; i<n; i++)
    cout<<arr[i]<<"->";
  cout<<endl;
}

int findStockBuyPrice(int *arr, int n)
{
  int maxPro = 0;
  int minPrice = INT_MAX;
  
  for(int i=0; i<n; i++)
  {
    minPrice = min(minPrice, arr[i]);
    maxPro = max(maxPro, arr[i] - minPrice);
  }

  return maxPro;
}
int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  
  int maxProfit = findStockBuyPrice(arr,n);
  cout<<"The max profit for the array is "<<maxProfit<<endl;
  return 0;
}
