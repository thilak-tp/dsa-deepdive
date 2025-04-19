#include<iostream>
#include<vector>
#include<map>
// A C++ program to find the number that is only once but the rest of the numbers are twice
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

// A function to find the never repeated number among many double repeated elements
// Using hashmap
int findSingleRepeatedNumber(int *arr, int n)
{
  map <int, int> freq;
  
  for(int i=0; i<n;i++)
  {
    freq[arr[i]]++;
  }
  
  for(auto it: freq)
  {
    if(it.second == 1)
      return it.first; 
  }
  return -1;
}

// The same as the above but using the properties of XOR
// same gives zero
// xor with 0 gives the number itself
int findSingleRepeatedNumberXor(int *arr, int n)
{
  int xorr = 0;
  for(int i=0; i<n; i++)
    xorr = xorr ^ arr[i];
  return xorr;
}

int main()
{
  
  int arr[20];

  int n = populateArray(arr); 

  displayArray(n,arr);

  //if(findSingleRepeatedNumber(arr, n) == -1)
  //  cout<<"No single numbers were found"<<endl;
  //else
  //  cout<<"The single number that was found is "<<findSingleRepeatedNumber(arr,n)<<endl;
  cout<<"The single number that was found is "<<findSingleRepeatedNumberXor(arr, n)<<endl;
  return 0;
}

