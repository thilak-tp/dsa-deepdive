#include<iostream>
#include<climits>
// A C++ program to find the missing number in the array
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

int findMissingNumber(int *arr, int n)
{
  int newN = arr[n-1];
  int nSum = (newN*(newN+1))/2;
  int arrSum = 0;
  for(int i=0; i<n; i++)  
    arrSum += arr[i];

  return nSum-arrSum;
}
int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);

  cout<<"The missing number in the sequence is "<<findMissingNumber(arr, n);
  return 0;
}
