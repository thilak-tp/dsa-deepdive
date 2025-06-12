#include<vector>
#include <iostream>
#include <algorithm>

// Given a matrix, rotate it 90 degrees, clockwise
using namespace std;
  
// Optimal Solution

void rotateMatrix(vector <vector <int>> &matrix) {
  
  int m = matrix.size();
  int n = matrix[0].size();

  // Interchange rows and columns of the given matrix
  for( int i=0; i<m; i++)
    for( int j=0; j<i; j++) {
      swap(matrix[i][j], matrix[j][i]);
    }

  // Reverse each row of the matrix
  for(int i=0; i<m; i++)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main(){

  vector <vector <int>> matrix = {{-1,-1,1},{-1,0,1},{-1,1,0}};
  int m= matrix.size();
  int n = matrix[0].size();

  cout<<"Input Matrix"<<endl;
  for(int i=0; i<m; i++) {
    for(int j=0;j<n; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
  
  rotateMatrix(matrix);
  
  cout<<"Output Matrix"<<endl;
  for(int i=0; i<m; i++) {
    for(int j=0;j<n; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
