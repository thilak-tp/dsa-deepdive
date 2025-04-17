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
int findLargestElement(int *arr, int size)
{
  int largest = INT_MIN;
  for(int i=0; i<size; i++)
  {
    if(arr[i] > largest)
      largest = arr[i];
  }
  return largest;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  int largest = findLargestElement(arr,n);
  cout<<"The largest element in the given array is "<<largest<<endl;

  return 0;
}
