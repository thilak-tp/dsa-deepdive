#include<iostream>
#include<vector>
//A C++ program to sort an array of 0s, 1s and 2s
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

void sortZeroesOnesTwos(int *arr, int n)
{
  int beg, end, mid;
  beg = 0;
  mid = 0;
  end = n-1;
  
  while(end>=beg)
  {
    if(arr[mid] == 0)
    {
      swap(arr[mid],arr[beg]);
      mid++;
      beg++;
    } 
    else if(arr[mid] == 1)
    {
      mid++;
    }
    else
    {
      swap(arr[mid], arr[end]);
      end--;
    }
  }
}

int main()
{
  int arr[20];

  int size = populateArray(arr); 
  displayArray(size,arr);

  sortZeroesOnesTwos(arr,size);
  cout<<"After sorting the elements are "<<endl;
  displayArray(size,arr);
  return 0;
}

