#include<iostream>
// This program explains the basics of arrays
using namespace std;

// swap without a third variable
void swap(int *num1, int *num2)
{
  *num1 = *num1 + *num2;
  *num2 = *num1 - *num2;
  *num1 = *num1 - *num2;  
}
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

// A function to count the number of zeroes in the array
//O(N)
int countZeroes(int *arr, int n)
{
  int zeroCount = 0;
  for(int i=0; i<n;i++)
    if(arr[i] == 0)
      zeroCount++;
  
  return zeroCount;
  
}

// To display the elements in the given array
//O(N)
void displayArray(int n, int *arr)
{
  for(int i=0; i<n; i++)
    cout<<arr[i]<<"->";
  cout<<endl;
}

//A function to reverse the elements in an array
void reverseArray(int *arr, int n)
{
  int beg = 0;
  int end = n -1;
  while(beg < end)
  {
    ::swap(&arr[beg],&arr[end]);
    beg++;
    end--;
  }
}
int main()
{
  int arr[10];
  int n = populateArray(arr);
  displayArray(n,arr);  
  reverseArray(arr, n);
  displayArray(n,arr);
  int zeroCount = countZeroes(arr, n);
  cout<<"There are "<<zeroCount<<" zeroes in the array"<<endl;
  return 0;
}
