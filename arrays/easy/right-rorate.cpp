#include<iostream>
#include<climits>
// A C++ program to right rotate the array by one element
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

void rightRotateArray(int *arr, int n)
{
  int lastElement = arr[n-1];
  for(int i=n-1; i>0; i--)
  {
    arr[i] = arr[i-1];
  }
  arr[0] = lastElement;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);

  rightRotateArray(arr,n);

  cout<<"After rotating the array by a place the array now is"<<endl;
  displayArray(n,arr);
  return 0;
}
