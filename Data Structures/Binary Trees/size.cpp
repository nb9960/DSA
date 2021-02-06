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

int getWidth(node* root,int level){
  if(root==NULL)
    return 0;
  if(level==1)
    return 1;
  return (getWidth(root->left,level-1)+getWidth(root->right,level-1));
}

int getMaxWidth(node* root){
  int maxWidth=0,i,width,h=maxDepth(root);
  for(i=1;i<=h;i++){
    width=getWidth(root,i);
    maxWidth=max(maxWidth,width);
  }
  return maxWidth;
}

int sum(node* node){
  if(node == NULL) return 0;
  return sum(node->left)+node->data+sum(node->right);
}

// 
// int isSumTree(node* node){
//   int ls, rs;
//   if(node == NULL || (node->left == NULL && node->right == NULL)){
//     return 1;
//   }
//   ls = sum(node->left); rs = sum(node->right);
//   if((node->data == ls +rs) && isSumTree(node->left) && isSumTree(node->right))
//     return 1;
//   return 0;
// }

bool isLeaf(node* root){
  return (root->left == NULL && root->right == NULL);
}

bool isSumTree(node* node){
  int ls = 0, rs = 0;
  if(node == nullptr || isLeaf(node))
    return true;
  if(node->left)
    ls = isLeaf(node->left) ? node->left->data : 2*node->left->data;
  if(node->right)
    rs = isLeaf(node->right) ? node->right->data : 2*node->right->data;
  return (node->data == ls+rs && isSumTree(node->left) && isSumTree(node->right)); 
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
  root->right->left=newNode(6);
  root->right->right=newNode(7);

  cout<<"Size = "<<size(root)<<endl;
  cout<<"Height = "<<maxDepth(root)<<endl;
  cout<<"Diameter = "<<diameter(root)<<endl;
  cout<<"Max Width = "<<getMaxWidth(root)<<endl;
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
