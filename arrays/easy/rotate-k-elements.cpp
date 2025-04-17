#include<iostream>
#include<climits>
// A C++ program to rotate an array by k places
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
void reverseArray(int *arr, int beg, int end)
{
  while(beg<end)
  {
    swap(arr[beg], arr[end]);
    beg++;
    end--;
  }
}
void rightRotateKPlaces(int *arr, int n, int k)
{

  reverseArray(arr, 0, n-k-1);
  reverseArray(arr, n-k, n-1);
  reverseArray(arr, 0, n-1);
}
void leftRotateKPlaces(int *arr, int n, int k)
{

  reverseArray(arr, 0, k-1);
  reverseArray(arr, k, n-1);
  reverseArray(arr, 0, n-1);
}
int main()
{
  
  int arr[20];
  int k;
  int n = populateArray(arr);
  displayArray(n,arr);
  cout<<"Enter the k value"<<endl;
  cin>>k;
  cout<<"The K value is "<<k<<endl;
  leftRotateKPlaces(arr,n,k);

  displayArray(n,arr);
  return 0;
}
