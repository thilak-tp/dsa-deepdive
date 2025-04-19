#include<iostream>
// This C++ program does implements bubble sort algorithm on a static array
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

// Check for consecutive elements and send the largest to the end
// O(NxN) 
void bubbleSort(int *arr, int n)
{
  for(int i=0 ;i <n; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(arr[j], arr[j+1]);
      }
    }
  }


}
int main()
{
  int arr[30];
  int n = populateArray(arr);
  displayArray(n, arr);
    
  bubbleSort(arr, n);

  displayArray(n, arr);
  return 0;
}
