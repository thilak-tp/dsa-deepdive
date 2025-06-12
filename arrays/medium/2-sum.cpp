#include<iostream>
#include<vector>
#include<unordered_map>
// A C++ program to check wheter a pair of elements exists in an array whose sum amounts to a given number

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

//Using Hashmap
bool twoSum(int *arr, int n, int target)
{
  unordered_map <int, int> mpp;
  
  for(int i=0; i<n; i++)
  {
    int num = arr[i];
    int moreNeeded = target - num;
    if(mpp.find(moreNeeded) != mpp.end())
      return true;

    mpp[num] = i;
  }

  return false;

}

//Using Two pointer method
bool twoSumTP(int *arr, int n, int target)
{ 
  int beg = 0;
  int end = n-1;
  int sum = 0;
  while(beg < end)
  { 
    sum = arr[beg] + arr[end];
    if(sum > target)
    {
      end--;
    }
    else if(sum < target)
    { 
      beg++;
    }
    else
    {

    return true;}
  }
  return false;
}

int main()
{
  int target;
  int arr[20];

  int n = populateArray(arr); 
  displayArray(n,arr);
  cout<<"Enter the target value"<<endl;
  cin>>target;
  
  if(twoSumTP(arr,n,target))
    cout<<"The pair exists"<<endl;
  else  
    cout<<"The pair does not exist"<<endl;
  return 0;
}

