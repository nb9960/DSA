// nb_9960
#include <bits/stdc++.h> 
using namespace std; 

class node{
  public:
  int data;
  node *left, *right;
};

void printSpiral(node* root){
  if(root == NULL) return;
  stack<node*> s1,s2;
  s1.push(root);
  while(!s1.empty() && !s2.empty()){
    while(!s1.empty()){
      node* tmp = s1.top();
      s1.pop();
      cout<<tmp->data<<" ";
      if(tmp->right != NULL){
        s2.push(tmp->right);
      }
      if(tmp->left != NULL){
        s2.push(tmp->left);
      }
    }
    while(!s2.empty()){
      node* tmp = s2.top();
      s2.pop();
      cout<<tmp->data<<" ";
      if(tmp->left != NULL){
        s1.push(tmp->left);
      }
      if(tmp->right != NULL){
        s1.push(tmp->right);
      }
    }
  }
}

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

int main() 
{  
  node* root = newNode(1); 
  root->left = newNode(2); 
  root->right = newNode(3); 
  root->left->left = newNode(7); 
  root->left->right = newNode(6); 
  root->right->left = newNode(5); 
  root->right->right = newNode(4); 
  cout << "Spiral Order traversal of binary tree is \n"; 
  printSpiral(root); 
  return 0; 
} 
