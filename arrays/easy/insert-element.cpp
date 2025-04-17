#include<iostream>
// Insert the given element by the user at he given location in the array
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


// A function to insert an element into an array at the given index and return the removed element
int insertElement(int *arr, int size, int element, int indexToInsertAt)
{
  int elementRemoved = arr[indexToInsertAt];
   
  for(int i=size-1; i<indexToInsertAt+1; i--)
  {
    arr[i] = arr[i-1];
  }

  arr[indexToInsertAt] = element;
  
  return elementRemoved;
}

int main()
{
  int size, arr[10];
  size = populateArray(arr);
 
  int element, indexToInsertAt, elementRemoved;
  cout<<"Enter an element to insert"<<endl;
  cin>>element;
 
  cout<<"Enter an index where this element is to be inserted"<<endl;
  cin>>indexToInsertAt;

  elementRemoved = insertElement(arr,size,element, indexToInsertAt);

  displayArray(size, arr);
  cout<<"The removed element due to insert is "<<elementRemoved<<endl;  
  return 0;
}
