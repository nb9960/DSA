/*
Pehle left subtree pe chalo;
head NULL hai to leftmost ko head bana do
warna kuch mt karo head ke saath
current ke left ko (matlab list me prev) ko 
abhi tk jo tail hai vo rakh do aur tail ke right(matlab list m next) ko abhi wala
aur tail update krke current pe lao
aise hi right wale ke liye chalao
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
};

void bintree2listUtil(Node* root, Node** head, Node** tail){
  if(root == NULL) return;
  bintree2listUtil(root->left, head, tail);
  if(*head == NULL) *head = root;
  root->left = *tail;
  if(*tail != NULL){
    (*tail)->right = root;
  }
  *tail = root;
  bintree2listUtil(root->right, head, tail);
}

Node* bintree2list(Node* root){
  if(root == NULL) return root;
  Node* head =NULL;
  Node* tail = NULL;
  bintree2listUtil(root, &head, &tail);
  return head;
}

Node* newNode(int data){
  Node* new_node = new Node();
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void printList(Node* head){
  while(head){
    cout<<head->data<<" ";
    head = head->right;
  }
}

int main(){
  Node* root = newNode(10);
  root->left = newNode(12);
  root->right = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);

  Node* head = bintree2list(root);

  printList(head);
  return 0;
}