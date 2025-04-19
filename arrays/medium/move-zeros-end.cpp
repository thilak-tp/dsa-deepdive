#include<iostream>
#include<vector>
// A C++ program to move all zeroes to the end of the array
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

// A function to send all zeroes to the end of the array
void sendZeroesBack(int *arr, int n)
{
  // Initiate the j value to -1
  int j= -1;

  // Traverse the whole array get the index of the first zero
  for(int i=0; i<n;i++)
  {
    if(arr[i] == 0)
    {
      j = i;
      break;
    }
  }
  // Check if the j is still -1, if so there ain't no zeroes in the array so exit
  if(j == -1)
    return;

  // Whenever we enounter a non zero after the zero that we found, we swap and increment the j index 
  for(int i=j+1; i<n; i++)
  {
    if(arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}


 
int main()
{
  int k;
  int arr[20];

  int size = populateArray(arr); 

  displayArray(size,arr);

  sendZeroesBack(arr, size);

  displayArray(size, arr);

  return 0;
}

