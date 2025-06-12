#include <iostream>
#include <string>
#include <stack>
using namespace std;



bool hasValidParenthesis(string inputString) {
  stack <char> st;
  for(auto it: inputString) {
    if(it == '(' || it == '[' || it == '{')
      st.push(it);
    else {
      if(st.size() == 0) return false;
      char ch = st.top();
      st.pop();
      if(ch == '(' and it == ')' or ch == '{' and it == '}' or ch == '[' and it == ']' ) continue;
      else return false; 
  }  
  }
  return st.empty(); 
}

int main() 
{
  string inputString;
  cout<<"Enter the input parenthesis"<<endl;
  cin>>inputString;
  
  if(hasValidParenthesis(inputString)) {
    cout<<"It has valid parenthesis"<<endl;
  }
  else
    cout<<"It does not have valid parenthesis"<<endl;

  return 0;
}
