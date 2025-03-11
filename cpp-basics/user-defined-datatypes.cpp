#include<iostream>
#include<string>
// A program that shows all the simple user defined data types in C++
using namespace std;

//1. A Class is a collection of data and its associated functions that are used to manipulate that data
class student{
  public:
  string name;
  int rollNo;
  int age;
};

//2. A structure is a collection of heterogenous data 
struct teacher{
  string name;
  int empID;
  string subject;
};

//3. A Union is a collection of heterogenous datatypes but all the members share the same memory location
// It is used in embedded systems since the use of the same memory makes it memory efficient on an already
// memoory depr
union buffer{
  int intergerBuffer;
  char characterBuffer;
  float floatingBuffer;
};

// 4. Enum are used to assign values to integral constants
enum RET_VAL {
  SUCCESS,
  FAILURE
};

int main()
{
  int returnVal = SUCCESS;
  cout<<"The value of the enum is "<<returnVal<<endl;

  student s1;
  teacher t1;
  buffer b1;
  
  s1.name = "Thilak";
  s1.rollNo = 37;
  s1.age = 25;
  cout<<"The name of the student is "<<s1.name<<endl<<"Roll No: "<<s1.rollNo<<endl<<"Age: "<<s1.age<<endl;
  t1.name = "Sundar Pichai";
  t1.empID = 10000;
  t1.subject = "Computer Science";
  cout<<"The name of the teacher is "<<t1.name<<endl<<"Employee ID: "<<t1.empID<<"Subject: "<<t1.subject<<endl;

  b1.intergerBuffer = 65;
  cout<<"The interger buffer is "<<b1.intergerBuffer<<endl<<"The character buffer is "<<b1.characterBuffer<<endl<<"The floating buffer is "<<b1.floatingBuffer<<endl;
  
  return 0;
}
