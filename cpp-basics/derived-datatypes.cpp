#include<iostream>
//This program includes the basic dervied datatypes in C++
using namespace std;

// 1. Functions are a type of derived datatype which is a block of code that can be called again and again
int add(int number1, int number2)
{
  return number1+number2;
}

int main()
{

  // Calling the addition function here
  cout<<"The sum of 1 and 2 is "<<add(1,2)<<endl;
  // 2. Array is a type of a derived datatype which is a collection of homogenious elements
  int arr[] = {1,2,3,4,5,6};
  cout<<"The elements in the array are: "<<endl;
  for(auto it : arr)
  {
    cout<<it<<"->";
  }
  
  // 3. Pointers are a type of a dervied datatype that stores the address of another variable
  int variable = 10;
  int * ptr = &variable;

  // Here ptr points to the address of variable and not to the value of the variable
  cout<<"The value of the variable is "<<variable<<endl<<"The value of the pointer is "<<ptr<<endl<<"The value dereferenced by the memory location pointed by the pointer is "<<*ptr;
  
  //4. References are an alternate name given to a variable
  int & ref = variable;
  cout<<"The variable is "<<variable<<endl<<"The value using the reference variable is "<<ref<<endl;
  return 0;

}
