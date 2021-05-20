#include <bits/stdc++.h>
using namespace std;

/* break it in 3 parts:
- print left boundary in top-down
- print all leaf nodes from l to r 
    - print all leaf nodes of left subtree from l to r
    - print all leaf nodes of right subtree from l to r
- print right boundary in bottom up
*/

class node{
  public:
    int data;
    node *left, *right;
};

void printBoundaryLeft(node *root){
  if(!root) return;
  if(root->left){
    cout<<root->data<<" ";
    printBoundaryLeft(root->left);
  }
  else if(root->right){
    cout<<root->data<<" ";
    printBoundaryLeft(root->right);
  }
  //  do nothing if its a leaf node
}

void printLeaves(node *root){
  if(!root) return;
  printLeaves(root->left);
  if(!(root->left) && !(root->right))
    cout<<root->data<<" ";
  printLeaves(root->right);
}

void printBoundaryRight(node *root){
  if(!root) return;
  if(root->right){
    printBoundaryRight(root->right);
    cout<<root->data<<" ";
  }
  else if(root->left){
    printBoundaryRight(root->left);
    cout<<root->data<<" ";
  }
  //  do nothing if its a leaf node
}

void printBoundary(node *root){
  if(!root) return;
  cout<<root->data<<" ";
  printBoundaryLeft(root->left);
  printLeaves(root->left);
  printLeaves(root->right);
  printBoundaryRight(root->right);
}

node* newNode(int data)
{
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return(Node);
}

int main(){
  node* root = newNode(20);
  root->left = newNode(8);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  root->right = newNode(22);
  root->right->right = newNode(25);

  printBoundary(root);

  return 0;
}