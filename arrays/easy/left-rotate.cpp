#include<iostream>
#include<climits>
// A C++ program to left rotate the array by one element
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

void leftRotateArray(int *arr, int n)
{
  int firstElement = arr[0];
  for(int i=0; i<n-1; i++)
  {
    arr[i] = arr[i+1];
  }
  arr[n-1] = firstElement;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);

  leftRotateArray(arr,n);

  cout<<"After rotating the array by a place the array now is"<<endl;
  displayArray(n,arr);
  return 0;
}
