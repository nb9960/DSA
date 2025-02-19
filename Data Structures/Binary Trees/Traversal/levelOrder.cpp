#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

void printGivenLevel(node* root, int level){
  if(root==NULL)
    return;
  if(level==1)
    cout<<root->data<<" ";
  else{
    printGivenLevel(root->left,level-1);
    printGivenLevel(root->right,level-1);
  }
}



int height(node* node){
  if(node==NULL)
    return 0;
  else{
    int lheight=height(node->left);
    int rheight=height(node->right);
    if(lheight>rheight)
      return (lheight+1);
    else return (rheight+1);
  }
}

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

/*
For reverse level order just reverse the loop from 1-h to h-1
For spiral level order add a variable lr if true the first left recurrence then right else first right then left
*/

void printLevelOrder(node *root){
  int h=height(root);
  int i;
  for(i=1;i<=h;i++){
    printGivenLevel(root,i);
  }
}

int main(){
  node* root=newNode(1);
  root->left=newNode(2);
  root->right=newNode(3);
  root->left->left=newNode(4);
  root->left->right=newNode(5);

  printLevelOrder(root);
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
