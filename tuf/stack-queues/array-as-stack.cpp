#include <iostream>
#include <climits>
class Stack{
  int *arr;
  int top;
  int size;
  
  public:
  
  Stack() {
    top = -1;
    size = 100;
    arr = new int[size];
  }

  void push(int data) {
    if(top >= size -1) {
      std::cout<<"The Stack is full, can't push!"<<std::endl;
      return;
    }
    top++;
    arr[top] = data;
  }

  int pop() {
    if(top == -1) {
      std::cout<<"The Stack is empty, can't pop!"<<std::endl;
      return INT_MAX;
    }
    int num = arr[top];
    top--;
    return num;
  }

  int Top() {
    return arr[top];
  }

  int Size() {
    return top + 1;  
  }

  void display() {
    for(int i=0; i<=top; i++)
      std::cout<<arr[i]<<"->";
  }
};  


int main() {
  
  Stack s;

  s.push(5);
  s.push(4);
  s.push(8);
  s.display();
  
  std::cout<<"The size of the stack is "<<s.Size()<<std::endl;
  std::cout<<"The Top element of the stack is "<<s.Top()<<std::endl;
  std::cout<<"The number getting popped is "<<s.pop()<<std::endl;
  s.display();
  
  std::cout<<"The number getting popped is "<<s.pop()<<std::endl;
  std::cout<<"The number getting popped is "<<s.pop()<<std::endl;
  std::cout<<"The number getting popped is "<<s.pop()<<std::endl;
  
  return 0;
}
