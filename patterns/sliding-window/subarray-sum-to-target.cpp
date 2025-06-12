#include<iostream>
#include<climits>
#include<unordered_map>
// A C++ program to find the subarray that adds upto the given target sum
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

pair maxSubarraySum(int *arr, int n, int k)
{
  int winStart = 0;
  int windowSum = 0;
  
  for(int winEnd = 0; winEnd<n; winEnd++)
  {
    windowSum += arr[winEnd];

  }  

  return maxSum;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  
  int k;
  cout<<"Enter the max subarray size"<<endl;
  cin>>k;

  int maxSum = maxSubarraySumHash(arr,n,k);
  cout<<"The max subarray sum with the given size is "<<maxSum;

  return 0;
}
