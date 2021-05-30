#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node* left, *right;
};

node* newNode(int data){
  node* Node=new node();
  Node->data=data;
  Node->left=NULL;
  Node->right=NULL;
  return Node;
}

bool isComplete(node* root){
  if(!root) return true;
  queue<node *> q;
  q.push(root);
  bool flag = false;
  while(!q.empty()){
    node* temp = q.front();
    q.pop();

    if(temp->left){
      if(flag) return false;
      q.push(temp->left);
    }
    else flag = true;

    if(temp->right){
      if(flag) return false;
      q.push(temp->right);
    }
    else flag = true;
  }
  return true;
}

int main(){
  node* root1=newNode(1);
  root1->left=newNode(2);
  root1->right=newNode(3);
  root1->left->left=newNode(4);
  root1->left->right=newNode(5);
  root1->right->left=newNode(6);
  if(isComplete(root1))
    cout<<"Complete Binary tree"<<endl;
  else cout<<"Not complete binary tree"<<endl;

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
