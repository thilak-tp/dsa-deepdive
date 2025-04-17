#include<iostream>
#include<climits>
// A C++ program to find the second largest element in the array
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

int findSecondLargestElement(int *arr, int n)
{
  int max1, max2;
  max1 = max2 = arr[0];
  for(int i=1; i<n; i++)
  {
    if(arr[i] > max1)
    {
      max2 = max1;
      max1 = arr[i];
    }
    else if(arr[i] > max2)
    {
      max2 = arr[i];
    }
  }
  return max2;
  
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr);
  displayArray(n,arr);
  
  int secondLargest = findSecondLargestElement(arr, n);
  cout<<"The second largest element in the array is "<<secondLargest<<endl;
  return 0;
}
