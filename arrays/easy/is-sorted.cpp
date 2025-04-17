#include<iostream>
#include<climits>
// A C++ program to check whether the given array is sorted or not
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

bool isSorted(int *arr, int n)
{
   for(int i=0; i<n-1; i++)
   {
      if(arr[i] > arr[i+1])
        return false;
   }

    return true;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  if(isSorted(arr, n))
    cout<<"The given array is sorted"<<endl; 
  else
    cout<<"The given array is unsorted"<<endl;

  return 0;
}
