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

Node* constructTreeUtil(int pre[], int post[], int* preInd, int l,int h, int size){
  if(*preInd >= size || l>h) return NULL;
  Node* root = newNode(pre[*preInd]);
  ++(*preInd);
  if(l==h) return root;

  // next element pre ka root ka left hoga ab left m dekho kitne elements hai post array ki help se
  int i;
  for(i=l;i<=h;i++){
    if(pre[*preInd] == post[i])
      break;
  }
  if(i<=h){
    root->left = constructTreeUtil(pre, post, preInd, l, i, size);
    root->right = constructTreeUtil(pre, post,preInd, i+1, h, size);
  }
}

Node* constructTree(int pre[], int post[], int n){
  int preInd=0;
  return constructTreeUtil(pre, post, &preInd,0, n-1,n);
}

void printInorder(Node* root){
  if(root == NULL) return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

int main(){
  int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7}; 
  int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1}; 
  int len = sizeof(pre)/sizeof(pre[0]);
  Node* root = constructTree(pre, post, len);
  printInorder(root);
  return 0;
}