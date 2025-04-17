#include<iostream>
#include<climits>
// A C++ progarm to find the 3 largest element in the array.
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
void find3LargestElements(int *arr, int size)
{
  int max1, max2, max3;
  max1 = max2 = max3 = arr[0];
  for(int i=1; i<size; i++)
  {
    if(arr[i] > max1)
    {
      max3 = max2;
      max2 = max1;
      max1 = arr[i];
    }
    else if(arr[i] > max2)
    {
      max3 = max2;
      max2 = arr[i];
    }
    else if(arr[i] > max3)
    {
      max3 = arr[i];
    }
  }  

  cout<<"The Max 3 numbers in the array are "<<max1<<", "<<max2<<", "<<max3<<endl;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  find3LargestElements(arr,n);
  return 0;
}
