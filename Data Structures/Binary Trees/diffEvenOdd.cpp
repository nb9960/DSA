#include <bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node *left, *right;
};

int diffIterative(node *root){
  if(!root) return 0;
  int oddSum =0, evenSum =0, level =0;
  queue<node *> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    level += 1;
    while(size--){
      node* temp = q.front();
      q.pop();
      if(level%2 == 0){
        evenSum += temp->data;
      }
      else oddSum += temp->data;
      if(temp->left) q.push(temp->left);
      if(temp->right) q.push(temp->right);
    }
  }
  return evenSum - oddSum;
}

int diffRecursive(node *root){
  if(!root) return 0;
  return root->data - diffRecursive(root->left) - diffRecursive(root->right);
}

void verticalSumUtil(node* root, int hdist, map<int, int> mp){
  if(root == NULL) return;
  verticalSumUtil(root->left, hdist-1, mp);
  mp[hdist] += root->data;
  verticalSumUtil(root->right, hdist+1, mp); 
}

void verticalSum(node* root){
  map<int, int> mp;
  map<int, int> :: iterator it;
  verticalSumUtil(root, 0, mp);
  for(it = mp.begin(); it!=mp.end();++it){
    cout<<it->first<<": "<<it->second<<endl;
  }
}

node* newnode(int data)
{
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  return(Node);
}

int main(){
  node *root = newnode(10);
  root->left = newnode(8);
  root->right = newnode(12);
  root->left->left = newnode(3);

  cout<<diffIterative(root)<<endl;
  cout<<diffRecursive(root)<<endl;
  verticalSum(root);

  return 0;
}