#include <iostream>
#include <stack>

using namespace std;
class MinStack {
  stack <pair <int,int>> st;

  public:
  void push(int value) {
    int min;
    if(st.empty()) {
      min = value;
    }
    else {
      min = min(st.top().second, value);
    }
    st.push({value, min});
  }

  void pop() {
    st.pop();
  }  

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
  
  
};



int main() {

  MinStack st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

}
