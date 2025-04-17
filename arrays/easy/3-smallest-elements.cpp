#include<iostream>
#include<climits>
// A C++ program to find 3 smallest elements in the given array
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
void find3SmallestElements(int *arr, int size)
{
  int min1, min2, min3;
  min1 = min2 = min3 = arr[0];
  for(int i=1; i<size; i++)
  {
    if(arr[i] < min1)
    {
      min3 = min2;
      min2 = min1;
      min1 = arr[i];
    }
    else if(arr[i] < min2)
    {
      min3 = min2;
      min2 = arr[i];
    }
    else if(arr[i] < min3)
    {
      min3 = arr[i];
    }
  }  

  cout<<"The Min 3 numbers in the array are "<<min1<<", "<<min2<<", "<<min3<<endl;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  find3SmallestElements(arr,n);
  return 0;
}
