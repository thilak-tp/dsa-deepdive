#include<iostream>
#include<vector>
// To find the Kth largest element in the given array of elements

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

void bubbleSortArray(int *arr, int size)
{
  //Using bubblesort to sort the array
  for(int i=0; i<size; i++)
  {
  
    for(int j=0; j<size-i-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        swap(arr[j], arr[j+1]);
      }

    }
  }

}

//To find the Kth largest element without using vector and inbuild sort functions
//Here i can sort the elements in the array and get the kth largest element from it
// Here the time complexity is NXN due to bubble sort being used
int kthLargestElement(int *arr,int size, int k)
{
  //A function to sort and return the array
  bubbleSortArray(arr, size);
   
  return arr[size-k];
}


int main()
{
  int k;
  int arr[20];

  int size = populateArray(arr); 
  displayArray(size,arr);
  cout<<"Enter the K value"<<endl;
  cin>>k;

  cout<<"The "<<k<<"th largest number is "<<kthLargestElement(arr,size,k)<<endl;
  return 0;
}

