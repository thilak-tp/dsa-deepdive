#include <iostream>
#include <climits>

using namespace std;
class Queue {
  int start;
  int end;
  int* arr;
  int maxSize;
  int curSize;

public:
  Queue() {
    start = end = -1;
    maxSize = 100;
    arr = new int[maxSize];
    curSize = 0;
  }

  Queue(int size) {
    maxSize = size;
    arr = new int[maxSize];
    start = end = -1;
    curSize = 0;
  }

  void push(int data) {
    if (curSize == maxSize) {
      cout << "The Queue is full" << endl;
      return;
    }

    if (end == -1) {
      start = end = 0;
    } else {
      end = (end + 1) % maxSize;
    }

    arr[end] = data;
    cout << data << " has been pushed" << endl;
    curSize++;
  }

  void pop() {
    if (start == -1) {
      cout << "The Queue is empty" << endl;
      return;
    }

    int popped = arr[start];
    cout << "The popped element is " << popped << endl;

    if (curSize == 1) {
      start = end = -1;
    } else {
      start = (start + 1) % maxSize;
    }
    curSize--;
  }

  int top() {
    if (start == -1) {
      cout << "The Queue is empty" << endl;
      return -1;
    }
    return arr[start];
  }

  int size() {
    return curSize;
  }
};


int main() {
  
  Queue q;

  q.push(5);
  q.push(4);
  q.push(8);
  cout<<"The top of the queue is "<<q.top()<<endl;
  cout<<"The size of the queue is "<<q.size()<<endl;
  q.pop();
  q.pop();  
  q.pop();

  
  return 0;
}
