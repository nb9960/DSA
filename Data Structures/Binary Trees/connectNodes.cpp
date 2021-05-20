#include <bits/stdc++.h>
using namespace std;

class node{
  public:
    int data;
    node *left, *right, *next, *nextRight;
};

void populateNext(node *p){
  static node *next = NULL;
  if(p){
    // reverse inorder so that to store prev node
    populateNext(p->right);
    p->next = next;
    next = p;
    populateNext(p->left);
  }
}

node* getNextRight(node* p){
  node* temp = p->nextRight;
  while(temp!=NULL){
    if(temp->left) return temp->left;
    if(temp->right) return temp->right;
    temp = temp->nextRight;
  } 
  return NULL;
}

void connectRecur(node *p){
  if(!p) return;
  /* Before setting nextRight of left and right children, set nextRight
  of children of other nodes at same level (because we can access 
  children of other nodes using p's nextRight only) */
  if(p->nextRight != NULL) connectRecur(p->nextRight);
  if(p->left){
    if(p->right){
      p->left->nextRight = p->right;
      p->right->nextRight = getNextRight(p);
    }else{
      p->left->nextRight = getNextRight(p);
    }
    connectRecur(p->left);
  }
  else if(p->right){
    p->right->nextRight = getNextRight(p);
    connectRecur(p->right);
  }
  else connectRecur(getNextRight(p));
}

void connect(node* p){
  p->nextRight = NULL;
  connectRecur(p);
}

node* newnode(int data)
{
  node* Node = new node();
  Node->data = data;
  Node->left = NULL;
  Node->right = NULL;
  Node->next = NULL;
  Node->nextRight = NULL;
  return(Node);
}

int main(){
  node *root = newnode(10);
  root->left = newnode(8);
  root->right = newnode(12);
  root->left->left = newnode(3);

  populateNext(root);

  // Populates nextRight pointer in all nodes 
  connect(root); 
 
  // Let us see the populated values
  node *ptr = root->left->left;
  while(ptr)
  {
      // -1 is printed if there is no successor
      cout << "Next of " << ptr->data << " is "
            << (ptr->next? ptr->next->data: -1)
            << endl;
      ptr = ptr->next;
  }

  return 0;
}