#include<iostream>
// This is the default C++ template that i'll be using
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

 

// A function to delete the given index element in an array and then
// add zeroes at the end
int deleteElement(int *arr, int size, int delElementIndex)
{
  int deletedNumber = arr[delElementIndex];
  if(delElementIndex >= size)
  {
    cout<<"The index provided doesn't exist in the array!Exiting"<<endl;
    exit(0);

  }
  for(int i=delElementIndex; i<size; i++)
  {
    arr[i] = arr[i+1];
  }
  
  arr[size-1] = 0;
  
  return deletedNumber;
  
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
  int size, arr[10], deletedElement, delElementIndex;
  size = populateArray(arr);
  
  cout<<"Enter which index element is to be deleted"<<endl;
  cin>>delElementIndex;

  deletedElement = deleteElement(arr,size,delElementIndex);

  displayArray(size,arr);

  cout<<"The deleted element is "<<deletedElement<<endl;
  
  return 0;
}
