#include<iostream>
#include<climits>
// A C++ program to check for them max consecutive ones in a given array
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

// A function to count the max consecutive ones in the given array
int maxConsecutiveOnes(int *arr, int n)
{
  int maxi = 0;
  int count = 0;
  for(int i=0; i<n; i++)
  {
    if(arr[i] == 1)
      count++;
    else
      count = 0;
    maxi = max(maxi, count);
  }  


  return maxi;
}
int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);

  cout<<"The max consecutive ones in the array is "<<maxConsecutiveOnes(arr, n)<<endl;
  return 0;
}
