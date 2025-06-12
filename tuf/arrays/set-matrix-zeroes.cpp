#include<vector>
#include <iostream>
#include <climits>
// If we get a zero, set all the row and column of that matrix to 0
// Including negative numbers as well
using namespace std;

// For the given row and all the columns, set the elements to INT_MIN
void setRow(vector <vector <int>> &matrix, int i, int n) {
  for(int j=0; j<n; j++) {
    if(matrix[i][j] != 0) {
       matrix[i][j] = INT_MIN;}
  }
}

// For the column and all the rows, set the elements to INT_MIN
void setCol(vector <vector <int>> &matrix, int m, int j) {
  for(int i=0; i<m; i++) {
    if(matrix[i][j] != 0) {
      matrix[i][j] = INT_MIN;
    } 
  }
}
// Brute Force Solution
void setMatrixZeroBF(vector <vector <int>> &matrix, int m, int n)
{
  // Set all the elements in the rows and columns of 0 with INT_MIN
  for(int i=0; i<m; i++) {
    for(int j=0;j<n; j++) {
      if(matrix[i][j] == 0 ) {
        setRow(matrix,i,n);
        setCol(matrix,m,j);
      }
    }
  }

  // Set all INT_MIN to 0
  for(int i=0; i<m; i++) {
    for(int j=0;j<n; j++) {
      if(matrix[i][j] == INT_MIN ) {
        matrix[i][j] = 0;
      }
    }
  }

}

//  Better Approach
void setMatrixZeroBA(vector <vector <int>> &matrix, int m, int n) {
  int row[m] = {0};
  int col[n] = {0};
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++) {
      if(matrix[i][j] == 0) {
        row[i] = 1;
        col[j] = 1;
      }
    }

  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++) {
      if(row[i] || col[j])
      {
        matrix[i][j] = 0;
      }
    }
}

//Optimal Solution
void setMatrixZeroOS(vector <vector <int>> &matrix, int m, int n) {
  int col0 = 1;
  // Set the first row and column values to 0 where the zero is found
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++) {
      if(matrix[i][j] == 0) {
        matrix[i][0] = 0;
        if( j!=0)
         matrix[0][j] = 0;
        else
         col0 = 0 ;
      }
    }

  // Set the rest of the element zero where the zero is found
  for(int i=1; i<m; i++)
    for(int j=1; j<m; j++) {
      if(matrix[i][j] != 0) {
        if(matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      }
    }
  // Set the first row and column to 0
  if(matrix[0][0] == 0) {
    for(int j=0; j<m; j++) {
      matrix[0][j] = 0;
    }
  }

  if(col0 == 0) {
    for(int i=0; i<n; i++) {
      matrix[i][0] = 0;
    }
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
  
  //setMatrixZeroBF(matrix,m,n);
  //setMatrixZeroBA(matrix,m,n);
  setMatrixZeroOS(matrix,m,n);
  
  cout<<"Output Matrix"<<endl;
  for(int i=0; i<m; i++) {
    for(int j=0;j<n; j++) {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
