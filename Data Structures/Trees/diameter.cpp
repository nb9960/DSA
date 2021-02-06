#include <bits/stdc++.h>
using namespace std;

class node {
  public:
	int data;
	node *left, *right;
};

node* newNode(int data);

int height(node* root){
  if(root == NULL){
    return 0;
  }
  int lHeight = height(root->left);
  int rHeight = height(root->right);
  return max(lHeight, rHeight) +1;
}

void printGivenLevel(node* root, int level){
  if(root == NULL){
    return;
  }
  if(level == 1){
    cout<<root->data<<" ";
  }
  else if(level>1){
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}

void printLevelOrder(node* root){
  int h = height(root);
  for(int i=0;i<=h;i++){
    printGivenLevel(root, i);
  }
}

int diameterOpt(node* root, int* height)
{
    // lh --> Height of left subtree
    // rh --> Height of right subtree
    int lh = 0, rh = 0;
 
    // ldiameter  --> diameter of left subtree
    // rdiameter  --> Diameter of right subtree 
    int ldiameter = 0, rdiameter = 0;
 
    if (root == NULL) {
        *height = 0;
        return 0; // diameter is also 0 
    }
 
    // Get the heights of left and right subtrees in lh and
    // rh And store the returned values in ldiameter and
    // ldiameter
    ldiameter = diameterOpt(root->left, &lh);
    rdiameter = diameterOpt(root->right, &rh);
 
    // Height of current node is max of heights of left and
    // right subtrees plus 1
    *height = max(lh, rh) + 1;
 
    return max(lh + rh + 1, max(ldiameter, rdiameter));
}

bool sameTree(node* tree1, node* tree2){
  if(tree1==NULL && tree2 == NULL ){
    return true;
  }else if(tree1!=NULL && tree2!=NULL){
    return (tree1->data == tree2->data && sameTree(tree1->left, tree2->left) && sameTree(tree1->right, tree2->right));
  }else{
    return false;
  }
}

void printInorder(node* node){
  if(node == NULL)
    return;
  printInorder(node->left);
  cout<<node->data<<" ";
  printInorder(node->right);
}

void printPreorder(node* node){
  if(node == NULL)
    return;
  cout<<node->data<<" ";
  printPreorder(node->left);
  printPreorder(node->right);
}

void printPostorder(struct node* node){
  if(node == NULL)
    return;
  printPostorder(node->left);
  printPostorder(node->right);
  cout<<node->data<<" ";
}

node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// Driver Code
int main()
{

	/* Constructed binary tree is
			1
			/ \
		2	 3
		/ \
	4	 5
	*/
	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
  int height =0;

	// Function Call
	cout << "Diameter of the given binary tree is " <<
		diameterOpt(root, &height);

	return 0;
}

// This code is contributed by shivanisinghss2110
