#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
};

Node* kAltReverse(Node* node, int k){
  int count = 0;
  Node *prev = NULL, *current = node, *next;
  
  //  reverse first k nodes
  while(current != NULL && count < k){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
    count++;
  }
  
  // head kth node p h so change head.next to k+1th
  if(node != NULL)
    node->next = current;
  
  // move current to skip next k nodes
  count = 0;
  while(count < k-1 && current != NULL){
    current = current->next;
    count++;
  }
  if(current != NULL)
    current->next = kAltReverse(current->next, k);
  return prev;
} 

void push(Node **head_ref, int new_data){
  Node* new_node = new Node();
  new_node->data = new_data;
  new_node->next = *head_ref;
  *head_ref = new_node;
}

void printList(Node *node){
  int cnt = 0;
  while(node != NULL){
    cout<<node->data<<" ";
    node = node->next;
    cnt++;
  }
}

int main(){
  Node* head = NULL;
  for(int i=20;i>0;i--)
    push(&head, i);
  cout<<"Given Linked List \n";
  printList(head);
  head = kAltReverse(head, 3);
  cout<<"\nModeified Linked List \n";
  printList(head);
  return 0;
}