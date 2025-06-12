#include<iostream>

using namespace std;

class BinaryTree{

  struct Node {
    int data;
    Node* right;
    Node* left;
    Node(int value) {
      data = value;
      left = right = NULL;
    }
  };
  Node* root;
  // Contructors and destructors
  BinaryTree() {root = NULL}
  ~BinaryTree() {}
  void inOrder() {
    if()
  }
};

int main(){
  BinaryTree tree;
  
  
  return 0;
}
