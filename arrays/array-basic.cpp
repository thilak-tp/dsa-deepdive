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

//O(N)
void displayArray(int n, int *arr)
{
  for(int i=0; i<n; i++)
    cout<<arr[i]<<"->";
  cout<<endl;
}

//A function to reverse an array
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
  return 0;
}
