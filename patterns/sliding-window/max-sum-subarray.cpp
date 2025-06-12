#include<iostream>
#include<climits>
#include<unordered_map>
// A C++ program to find the max sum subarray
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

int maxSubarraySumHash(int *arr, int n, int k)
{
  unordered_map <int, int> windowSums;
  int windowSum = 0;
  for(int i=0; i<n; i++)
  {
    windowSum += arr[i];
    windowSums[0] = windowSum;
  }

  int maxSum = INT_MIN;
  int maxStart = -1;

  for(int i = k; i<n; i++)
  {
    windowSum += arr[i] - arr[i-k];
    windowSums[i - k + 1] = windowSum;
  }
  
  for(auto it: windowSums)
  {
    if(it.second > maxSum)  
    {
      maxSum = it.second;
      maxStart = it.first;
    }
  }
  return maxSum;
}

int maxSubarraySum(int *arr, int n, int k)
{
  int maxSum = INT_MIN;
  int winStart = 0;
  int windowSum = 0;
  
  for(int winEnd = 0; winEnd<n; winEnd++)
  {
    windowSum += arr[winEnd];
    if(winEnd >= k-1)
    {
      maxSum = max(maxSum,windowSum);
      windowSum -= arr[winStart];
      winStart++;
    }
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
