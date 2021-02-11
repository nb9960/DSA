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

int findMax(int inorder[], int start, int end){
  int maxm = INT_MIN, maxInd;
  for(int i=start;i<=end;i++){
    if(maxm<inorder[i]){
      maxm = inorder[i];
      maxInd = i;
    }
  }
  return maxInd;
}

Node* buildTree(int inorder[], int start, int end){
  if(start>end) return NULL;
  int maxInd = findMax(inorder, start,end);
  Node* root = newNode(inorder[maxInd]);
  if(start == end)
    return root;
  root->left = buildTree(inorder, start,maxInd-1);
  root->right = buildTree(inorder, maxInd+1, end);
  return root;
}

void printInorder(Node* root){
  if(root == NULL) return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

int main(){
  int inorder[] = {5, 10, 40,30, 28};
  int len = sizeof(inorder)/sizeof(inorder[0]);
  Node* root = buildTree(inorder, 0, len-1);
  printInorder(root);
  return 0;
}