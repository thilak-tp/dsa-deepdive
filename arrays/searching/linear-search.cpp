#include<iostream>
#include<climits>
// A C++ progarm to perform linear search on the given array
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

// A function to perform linear search of a given element in the array
//O(N)
bool linearSearch(int *arr, int n, int element)
{
  for(int i=0; i<n; i++)
    if(arr[i] == element)
      return 0;
 
  return -1;
}
int main()
{
  
  int arr[20], element;

  int n = populateArray(arr);
  displayArray(n,arr);
  cout<<"Enter an element to search in the given array"<<endl;
  cin>>element;

  if(!linearSearch(arr,n,element))
    cout<<"The element was found"<<endl;
  else
    cout<<"The element was not found"<<endl;

  return 0;
}
