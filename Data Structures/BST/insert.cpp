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
  insert(root,10);
  insert(root, 5);
  insert(root,20);
  insert(root,8);
  insert(root, 30);

  inorder(root);

  node* tmp = search (root, 20);
  return 0;
}
