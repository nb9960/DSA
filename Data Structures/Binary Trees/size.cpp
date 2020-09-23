#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

int size(node* node){
  if(node==NULL)
    return 0;
  else return(size(node->left) + 1 + size(node->right));
}

int maxDepth(node* node){
  if(node==NULL)
    return 0;
  else {
    int l=maxDepth(node->left);
    int r=maxDepth(node->right);
    return (max(l,r)+1);
  }
}

int diameter(node* node){
  if(node==NULL){
    return 0;
  }
  int lh=maxDepth(node->left);
  int rh=maxDepth(node->right);
  int ld=diameter(node->left);
  int rd=diameter(node->right);
  return max(lh+rh+1,max(ld,rd));
}

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

int main(){
  node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->right=newNode(5);

  cout<<"Size = "<<size(root)<<endl;
  cout<<"Height = "<<maxDepth(root)<<endl;
  cout<<"Diameter = "<<diameter(root)<<endl;
  return 0;
}

/*
      1
    /   \
   2     3
  /  \
  4   5
  Time complexity: worst case: O(n^2)
  Space complexity: O(n) for worst case for skewed tree 
                    For balanced tree O(logn)
*/
