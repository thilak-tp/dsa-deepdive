#include <iostream>
#include <unordered_set>
using namespace std;


class LinkedList {

  struct Node {
    int data;
    Node *next;
    Node(int value) {
      data = value;
      next = NULL;
    }
  };

  Node *head;
  
  public:
  LinkedList() {
    head = NULL;

  }

  ~LinkedList() {
    clear();
  }

  // Member functions to add nodes at the front of the node
  void frontInsert( int value) {
    Node * newNode = new Node(value);
    newNode->next = head;
    head = newNode;
  }

  // Member function to add nodes at the back of the node
  void backInsert ( int value ) {
    Node *newNode = new Node(value);
    if(!head) {
      head = newNode; return;
    }
    
    Node* curNode = head;
    while(curNode->next) {
        curNode = curNode->next;
    }
    curNode->next = newNode;
    
  }
    
  // Member function to display the nodes data in the lisked list
  void displayLinkedList() {
    if(!head) {
       cout<<"The list is empty"<<endl; return;
    }
    Node * curNode = head;
    while(curNode) {
      cout<<curNode->data<<"->";
      curNode = curNode->next;
    }
    cout<<endl;
  }
  
  // Member function to cleanup the dynamically allocated memory
  void clear() {
     Node* cur = head;
     while(cur) {
      Node *temp = cur;
      cur = cur->next;
      delete temp;
    }
    head = NULL;
  }
  
  // Member function to detete a given node

  void deleteNode( int value) {
    

    if(!head) { cout<<"Cannot delete from an empty list"<<endl; return ;}
    if (head->data == value) {
      Node* temp = head;
      head = head->next;
      delete temp;
      cout << "The Node was deleted" << endl;
      return;
    }
    Node* prev = head;
    Node* cur = head->next;
    
    while(cur) {
      if(cur->data == value) {
        Node *delNode = cur;
        prev->next = cur->next;
        delete delNode;
        cout<<"The Node was deleted"<<endl;
        return;
      }
      prev = prev->next;
      cur = cur->next;
    }
    cout<<"The node was not found!"<<endl;

  }

  // A function to reverse the linked list 
  void reverseLL() {
    if(!head) { cout <<"The list is empty!"<<endl; return;}
  
    Node *cur = head;
    Node *prev = NULL;

    while(cur) {
      Node *front = cur->next;
      cur->next = prev;
      prev = cur;
      cur = front;  
    }
    head = prev;
  }

  // A function to find the middle node of a LL
  void findMiddleNode() {
    if(!head) 
      return;
    if(!head->next) {
      head = NULL;
    } 
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    cout<<"The middle node is "<<slow->data<<endl;
  }


  // A function to delete the middle node of a LL
  void delMiddleNode() {
    if(!head) 
      return;
    if(!head->next) {
      head = NULL;
    } 
    Node *slow = head;
    Node *prev = NULL;
    Node *fast = head;

    while(fast && fast->next) {

      prev = slow;
      fast = fast->next->next;
      slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
  }
  
  void delNthNodeFromEnd(int n) {
    if(!head) { cout<<"The list is empty!"<<endl; return;}
    Node* fast = head;
    Node* slow = head;

    for(int i=0; i<n; i++) {
      fast = fast ->next;
    }

    if(!fast) {
      cout<<n<<"th node from the end is "<< head->next;
    }

    while(fast->next) {
      slow = slow->next;
      fast = fast->next;
    }

    Node* delNode = slow->next;
    cout<<n<<"th node from the end "<<delNode->data<<"deleted."<<endl;
    slow->next = slow->next->next;
    delete delNode;
    
  }

  bool detectLoop() {
    if(!head) {cout<<"The list is empty!"<<endl; return false;}
    Node* fast = head;
    Node* slow = head;
    
    while(fast && fast->next) {
      
      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast) {
        return true;
      }
    }
    return false;
  }


  void loopFirstElement(){
    if(!head) {cout<<"The list is empty!"<<endl; return;}
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next) {

      fast = fast->next->next;
      slow = slow->next;
      if(slow == fast) {
        slow = head;
        while(slow != fast) {
          fast = fast->next;
          slow = slow->next;
        } 
        cout<<"The first node of the loop is "<<slow->data<<endl;
        return;
      }
    }
    cout<<"There was no loop found!"<<endl;
  }

  // A function to reverse the linked list
  Node* reverseLL(Node* hd) {
    if(!head) { cout <<"The list is empty!"<<endl; return NULL;}

    Node *cur = hd;
    Node *prev = NULL;

    while(cur) {
      Node *front = cur->next;
      cur->next = prev;
      prev = cur;
      cur = front;
    }
    hd = prev;
    return hd;
  }
  bool checkPalindrome() {
    
    Node* fast = head;
    Node* slow = head;

    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    Node *newHead = reverseLL(slow->next);
    Node* firstHead = head;
    Node* secondHead = newHead;
    while(secondHead) {

      if(secondHead->data != firstHead->data) {
        reverseLL(newHead);
        return false;
      }

      firstHead = firstHead->next;
      secondHead = secondHead->next;
      
    }
    reverseLL(newHead);
    return true;
  }

  Node *findIntersectionMap(Node* head1, Node* head2){
    unordered_set<Node*> mpp;
    while(head1){
      mpp.insert(head1);
      head1 = head1->next;
    } 
    while(head2){
      if(mpp.find(head2) != mpp.end()) return head2;
      head2 = head2->next;
    }
    return NULL;
  }

  Node* findIntersectionOS(Node* head1, Node* head2) {
    Node* d1 = head1;
    Node* d2 = head2;

    while(d1 != d2) {
      d1 = d1 == NULL? head2 : d1->next;
      d2 = d2 == NULL? head1 : d2->next;
      
    }

    return d1;
  }
  //  Merge two liskedlists
  Node* mergeTwoLLs(Node* l1, Node* l2) {
    Node* newNode = new Node(-1);
    Node* temp = newNode;
  
    while(l1 && l2) {

      if(l1->data >= l2->data) {
        temp->next = l2;
        l2 = l2->next;
      }
      else {
        temp->next = l1;
        l1 = l1->next;
      }

      temp = temp->next;
    }
    if(l1) {
      temp->next = l1;
    }  
    else {
      temp->next = l2;
    }

    return newNode->next;
  }

  // A function to find the middle node of a LL
  Node* findMiddleNodeNew(Node* head) {
    if(!head)
      return nullptr;
    if(!head->next) {
      return head;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
  Node* retHead()
  {
    return head;
  }
  Node* sortLL(Node* head){
    if(!head || !head->next) return head;
    Node* midNode = findMiddleNodeNew(head);

    Node* right = midNode->next;
    midNode ->next = nullptr;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);
  
    return mergeTwoLLs(left,right);
  }
};
int main() {

  LinkedList list;
  list.frontInsert(10);
  list.backInsert(20);
  list.backInsert(30);
  list.backInsert(20);
  list.backInsert(10);
  list.reverseLL();
  list.displayLinkedList();
  //list.findMiddleNode();
  //list.delMiddleNode();
  //list.displayLinkedList();
  //list.delNthNodeFromEnd(4);
  //list.displayLinkedList();
  if(list.detectLoop())
    cout<<"The list has a loop"<<endl;
  else 
    cout<<"The list doesn't have a loop"<<endl;
   if(list.checkPalindrome())
    cout<<"The list is palindrome"<<endl;
  else 
    cout<<"The list is not palindrome"<<endl;
  list.sortLL(list.retHead());
  
  list.displayLinkedList();

return 0;
}
