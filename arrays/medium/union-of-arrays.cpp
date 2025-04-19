#include<iostream>
#include<vector>
// A C++ program to find the union of two arrays
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

// A program to find the union of the two given arrays
vector <int> unionOfTwoArrays(int *arr1, int *arr2, int m, int n)
{

  vector <int> union_;
  
  int i=0;
  int j=0;
  while(i<m && j<n)
  {
    if(arr1[i] <= arr2[j])
    {
      if(union_.size() == 0 ||  union_.back() != arr1[i])
        union_.push_back(arr1[i]);
      i++;
    }
    else
    {
      if(union_.size() == 0 || union_.back() != arr2[j])
        union_.push_back(arr2[j]);
      j++;
    }
  }
      
  while(i<m)
  {
    if(union_.back() != arr1[i])
      union_.push_back(arr1[i]);
    i++;
  }   
  while(j<m)
  {
    if(union_.back() != arr2[j])
      union_.push_back(arr2[j]);
    j++;
  }
  
  return union_;
}


 
int main()
{
  
  int arr1[20],arr2[20];

  int m = populateArray(arr1); 
  int n = populateArray(arr2); 

  displayArray(m,arr1);
  displayArray(n,arr2);

  vector <int> union_ = unionOfTwoArrays(arr1, arr2, m, n);

  cout<<"The union is "<<endl;
  for(auto it: union_)
    cout<<it<<"->";
  return 0;
}

