#include<iostream>
//To remove the duplicates from an array and retrun the array
using namespace std;

// To remove consecutive duplicates from an array
int * removeDoubleDuplicates(int *size, int *arr)
{
  
  int pairCount = 0;
  for(int i=0; i<*size ; i++)
  {

    if(arr[i] == arr[i+1])
    {
      pairCount++;
      for(int j=i; j<*size-1; j++)
      {
        arr[j] = arr[j+2];
      }
    }
  }
  
  *size = *size - 2*pairCount;
  arr = (int*) realloc(arr, *size);
  cout<<"The new size is "<<*size<<endl;
  
  return arr;
}

int removeDuplicatesTwoPointer(int size, int *arr)
{
  if(size <= 0)
    return -1;
  int j=0;
  for(int i=1;i<size-1;i++)
  {

    if(arr[i] != arr[j])
    {
    
      arr[++j] = arr[i];
    }
  }
  
  arr = (int*) realloc(arr, j+1);
  cout<<"The new size is "<<j+1<<endl;
  return j+1;
}
// To display the elements in the given array
//O(N)
void displayArray(int n, int *arr)
{
  for(int i=0; i<n; i++)
    cout<<arr[i]<<"->";
  cout<<endl;
}


int main()
{
  int size;
  cout<<"Enter the size of the array."<<endl;
  cin>>size;

  //int *arr = new int(size);
  int *arr = (int*) malloc(size*sizeof(int));
  cout<<"Enter "<<size<<"numbers."<<endl; 
  for(int i=0; i<size; i++)
    cin>>arr[i];
  displayArray(size, arr);  
  
  //arr = removeDoubleDuplicates(&size, arr);
  int newSize = removeDuplicatesTwoPointer(size, arr);
  displayArray(newSize, arr);
  return 0;
}
