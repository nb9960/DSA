#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left; 
  Node* right;
};

Node* newNode(int data){
  Node* node = new Node();
  node->data = data;
  node->left = NULL; node->right = NULL;
}

Node* constructTreeUtil(int pre[], char preLN[], int* ind, int n){
  int index = *ind;
  if(index == n) return NULL;
  Node* tmp = newNode(pre[index]);
  (*ind)++;
  if(pre[index] == 'N'){
    tmp->left = constructTreeUtil(pre, preLN, ind, n);
    tmp->right = constructTreeUtil(pre, preLN, ind, n);
  }
  return NULL;
}

Node* constructTree(int pre[], char preLN[], int n){
  int ind=0;
  return constructTreeUtil(pre, preLN, &ind, n);
}

void printInorder(Node* root){
  if(root == NULL) return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

int main(){
  int pre[] = {10, 30, 20,5, 15};
  char preLN[] = {'N', 'N', 'L', 'L', 'L'};
  int len = sizeof(pre)/sizeof(pre[0]);
  Node* root = constructTree(pre, preLN, len);
  printInorder(root);
  return 0;
}