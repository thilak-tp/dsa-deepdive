#include<iostream>
#include<vector>
#include<unordered_map>
// A C++ program that returns the element that is repeated more than or equal
// to n/2 times of the total size of the array
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
// Using the Moore's Voting Algoritm
int nBy2TimesElementOptimized(int *arr, int n)
{
  int count = 0;  
  int element = 0;
  for(int i =0; i<n ; i++)
  {
    if(count == 0)
    {
      element = arr[i];
      count = 1;
    }
    else if(arr[i] == element)
    {
      count++;
    }
    else 
      count--;
  }
  
  int count1 = 0;
  for(int i=0; i<n; i++)
  {
    if(arr[i] == element)
      count1++;
  }
  if(count1 > n/2)
    return element;
  
  return -1;
}

int nBy2TimesElement(int *arr, int n)
{
  unordered_map <int, int> mpp;
  for(int i=0; i<n; i++)
    mpp[arr[i]]++;

  for(auto it:mpp)
  {
    if(it.second >= (n/2))
      return it.first;
  }

  return -1;
}

int main()
{
  int arr[20];

  int size = populateArray(arr); 
  displayArray(size,arr);

  if(nBy2TimesElementOptimized(arr, size) == -1)
    cout<<"There are no elements that is repeated n/2 times or more";
  else
    cout<<"The element that is repeated n/2 times is "<<nBy2TimesElement(arr,size)<<endl;
  return 0;
}

