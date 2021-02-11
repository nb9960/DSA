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
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printInorder(Node* root){
  if(root == NULL)
    return;
  printInorder(root->left);
  cout<<root->data<<" ";
  printInorder(root->right);
}

void storeInorder(Node* root, int a[], int *i){
  if(root == NULL)
    return;
  storeInorder(root->left, a, i);
  a[*i] = root->data;
  (*i)++;
  storeInorder(root->right, a, i);
}

int *merge(int a1[], int a2[], int n1, int n2){
  int *mergedArr = new int[n1+n2];
  int i = 0, j = 0, k = 0;
  while(i<n1 && j<n2){
    if(a1[i]<a2[j]){
      mergedArr[k] = a1[i];
      i++;
    }else{
      mergedArr[k] = a2[j];
      j++;
    }
    k++;
  }
  while(i<n1){
    mergedArr[k] = a1[i];
    i++; k++; 
  }
  while(j<n2){
    mergedArr[k] = a2[j];
    j++;  k++;
  }
  return mergedArr;
}

Node* sortedArrayToBST(int arr[], int start, int end){
  if(start > end)
    return NULL;
  int mid = (start+end)/2;
  Node* root = newNode(arr[mid]);
  root->left = sortedArrayToBST(arr, start, mid-1);
  root->right = sortedArrayToBST(arr, mid+1, end);
  return root;
}

Node* mergeTrees(Node* root1, Node* root2, int n1, int n2){
  int *arr1 = new int[n1];
  int i = 0;
  storeInorder(root1, arr1, &i);

  int *arr2 = new int[n2];
  int j = 0;
  storeInorder(root2, arr2, &j);
  int *mergedArr = merge(arr1, arr2, n1, n2);
  return sortedArrayToBST(mergedArr, 0, n1+n2-1);
}

int main(){
  Node *root1 = newNode(100); 
  root1->left     = newNode(50); 
  root1->right = newNode(300); 
  root1->left->left = newNode(20); 
  root1->left->right = newNode(70); 

  Node *root2 = newNode(80); 
  root2->left     = newNode(40); 
  root2->right = newNode(120); 

  Node* mergedTree = mergeTrees(root1, root2, 5, 3);
  printInorder(mergedTree);
  return 0;
}