#include <bits/stdc++.h>
using namespace std;

class Node{
  public: 
  int data;
  Node* next; //issi ko hi right ptr ki trh use kro
  Node* prev; //isko left ki trh
};

void push(Node** head, int data){
  Node* new_node = new Node();
  new_node->data =data;
  new_node->prev =NULL;
  new_node->next = (*head);
  if((*head) != NULL){
    (*head)->prev = new_node;
  }
  (*head) = new_node;
}

int countNode(Node* head){
  int num = 0;
  Node* temp = head;
  while(temp){
    temp = temp->next;
    num++;
  }
  return num;
}

Node* sortedListToBSTRecur(Node** head, int n){
  if(n<=0) return NULL;
  Node *left = sortedListToBSTRecur(head, n/2);
  Node* root = *head;
  root->prev = left;
  *head = (*head)->next;
  root->next = sortedListToBSTRecur(head, n-n/2-1);
  return root;
}

Node *sortedListToBST(Node* head){
  int n = countNode(head);
  return sortedListToBSTRecur(&head, n);
}

void preOrder(Node* root){
  if(root == NULL) return;
  cout<<root->data<<" ";
  preOrder(root->prev);
  preOrder(root->next);
}

int main(){
  Node* head = NULL;
  push(&head, 7);
  push(&head, 6);
  push(&head, 5);
  push(&head, 4);
  push(&head, 3);
  push(&head, 2);
  push(&head, 1);

  Node* root = sortedListToBST(head);
  cout<<"Preorder Traversal of constructed BST \n";
  preOrder(root);
  return 0;
}