#include<iostream>
#include<vector>
// A C++ program to find the longest subarray with the given positive sum
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

 
int main()
{
  
  int arr[20];

  int n = populateArray(arr); 

  displayArray(n,arr);
  
  
  return 0;
}

