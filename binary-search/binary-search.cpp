#include<iostream>
#include<climits>
// A C++ progarm to find the largest of the elements in the array.
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

bool binarySearch(int *arr, int n, int element)
{
  int beg = 0;
  int end = n-1;
  int mid = 0; 
  while(beg <= end)
  {
    mid = (beg + end)/2;
    
    if(mid == element)
      return true;
    else if(mid > element)
      end = mid - 1;
    else 
      beg = mid + 1;
  }

  return false;
}
int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  int element;
  cout<<"Enter an element to search"<<endl;
  cin>>element;

  if(binarySearch(arr,n,element))
     cout<<"The element was found"<<endl;
  else
    cout<<"The element was not found"<<endl;

  return 0;
}
