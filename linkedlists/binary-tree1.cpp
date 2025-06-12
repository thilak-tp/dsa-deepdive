#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  
  int data;
  Node* right;
  Node* left;
  Node(int value) {
    data = value;
    left = right = NULL;
  }
};

// For Inorder Traversal of the Tree (left -> root -> right)
void inOrder(Node* root) {
  if(!root)
    return;

  inOrder(root->left);
  cout<<root->data<<"->";
  inOrder(root->right);
}

// For Preorder Traversal of the Tree (root -> left -> right)
void preOrder(Node* root) {
  if(!root)
    return;
  cout<<root->data<<"->";
  preOrder(root->left);
  preOrder(root->right);
}

// For Postoder Traversal of the Tree (left ->right -> root)
void postOrder(Node* root) {
  if(!root)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<"->";
}

void levelOrder(Node* root, vector<vector<int>> &answer){
  if(!root) return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()) {
    int size = q.size();
    vector <int>level;
    for(int i=0; i<size; i++){
      Node* node = q.front();
      q.pop();
      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right);
      level.push_back(node->data);
    }
    answer.push_back(level);
  }
}

// To level order traverse the BT
vector<vector<int>>  levelOrderTraversal( Node* root){
 vector<vector<int>> result;
 levelOrder(root,result);
 return result;
}
int main() {

  Node* root = new Node(4);
  root->right = new Node(5);
  root->left = new Node(2);
  root->left->left = new Node(3);
  root->left->left->right = new Node(9);
  root->left->left->right->left = new Node(1);
  root->right->left = new Node(7);
  root->right->right = new Node(6);
  root->right->right->left = new Node(8);
  inOrder(root);
  cout<<endl;
  preOrder(root);
  cout<<endl;
  postOrder(root);
  vector <vector<int>> ans = levelOrderTraversal(root);
  for(auto row: ans) {
    for(auto element: row) {
      cout<<element<<" ";
    }
    cout<<endl;
  }
  return 0;  
}
