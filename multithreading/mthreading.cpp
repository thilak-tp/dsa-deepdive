#include<iostream>
#include<thread>
// This code will contain me exploring multithreading in C++
using namespace std;

void task1()
{
  cout<<"Thread one is executing"<<endl;  
}

void task2()
{
  cout<<"Thread two is executing"<<endl;
}

int main()
{
  thread t1(task1);
  thread t2(task2);

  t1.detach();
  t2.join();
  if(t1.joinable())
    cout<<"The thread is joinable"<<endl;
  else 
    cout<<"The thread is not joinable"<<endl;
  return 0;
}
