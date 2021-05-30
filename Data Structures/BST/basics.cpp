#include <bits/stdc++.h>
using namespace std;

class node{
  public:
  int key_value;
  node* left, *right;
};

node* newNode(int key)
{
    node* Node = new node();
    Node->key_value = key;
    Node->left = Node->right = nullptr;
 
    return Node;
}

bool isLeaf(node* root){
  return (root->left == NULL && root->right == NULL);
}

bool isSumTree(node* root){
  int ls = 0, rs= 0;
  if(!root || isLeaf(root)) return true;
  if(isSumTree(root->left) && isSumTree(root->right)){
    if(!root->left) ls =0;
    else if(isLeaf(root->left)) ls = root->left->key_value;
    else ls = 2*(root->left->key_value);
    if(!root->right) rs = 0;
    else if(isLeaf(root->right)) rs = root->right->key_value;
    else rs = 2*(root->right->key_value);
    return (root->key_value == ls+rs);
  }
  return false;
}

node* search(node* root,int key){
  node* t= root;
  while (t != NULL)
  {
    if(key == t->key_value)
     return t;
    else if(key < t->key_value)
      t = t->left;
    else t = t->right;
  }
  return NULL;
}

void insert(node* &root,int key){
  if(root == NULL){
    root = newNode(key);
    return;
  }
  // pehle search karke dekho kaha add karna hai
  if (key < root->key_value) {
    insert(root->left, key);
  }
  // if the given key is more than the root node, recur for the right subtree
  else {
   insert(root->right, key);
  }
}

void inorder(node* root){
  if(root == NULL){
    return;
  }
  inorder(root->left);
  cout<<root->key_value<<" ";
  inorder(root->right);
}

int main(){
  node* root = NULL;
  insert(root,26);
  insert(root, 10);
  insert(root,3);
  insert(root,4);
  insert(root, 6);
  insert(root, 3);

  inorder(root);
  if(isSumTree(root))  cout<<"Is sum Tree"<<endl;
  else cout<<"not a sum tree"<<endl;
  node* tmp = search (root, 20);
  return 0;
}
