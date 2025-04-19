#include<iostream>
// This C++ program does implements selection sort algorithm on a static array
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

// At each iteration, a minimum is taken and then put we it in the right place
// O(NxN) 
void selectionSort(int *arr, int n)
{

  //Outer loop to run from first element to the second last element
  for(int i=0 ;i <n-1; i++)
  {
    // a variable to keep track of the minimum index where the unsorted array begins
    int minIdx = i;
    //Inner loop to run from the unsorted part to the last element
    for(int j= i + 1; j<n; j++)
    {
      // of the next element is smaller than the current minimum indexed element, then 
      // that index element is the new smaller element
      if(arr[j]<arr[minIdx])
      {
        minIdx = j;
      }
      
    }
    // after finding the smallest element, put it at the first postion of the unsorted array
    swap(arr[minIdx], arr[i]);
  }

}
int main()
{
  int arr[30];
  int n = populateArray(arr);
  displayArray(n, arr);
    
  selectionSort(arr, n);

  displayArray(n, arr);
  return 0;
}
