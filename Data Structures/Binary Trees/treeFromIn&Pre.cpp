#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
  char data;
  Node* left;
  Node* right;
};

Node* newNode(char newData){
  Node* node = new Node();
  node->data = newData;
  node->left = NULL;
  node->right = NULL;
  return node;
}

/*
preorder se element pick karo aur usse ek naya node bnao aur preOrder ka ptr badha do
jo element pkda hai uska index inorder wale m dekho map se
ab uss index ke pehle elements se left subtree banao 
aur uske baad walo se right 
*/

Node* buildTree(char in[], char pre[], int inStart, int inEnd, unordered_map<char, int> &mp){
  static int preInd = 0;
  if(inStart > inEnd)
    return NULL;
  char curr = pre[preInd++];
  Node* tNode = newNode(curr);
  if(inStart == inEnd)
    return tNode;
  int inInd = mp[curr];
  tNode->left = buildTree(in, pre, inStart, inInd-1, mp);
  tNode->right = buildTree(in, pre, inInd+1, inEnd, mp);
  return tNode;
}

Node* buildTreeWrap(char in[], char pre[], int len){
  unordered_map <char, int> mp;
  for(int i=0;i<len;i++)
    mp[in[i]] = i;
  return buildTree(in, pre, 0, len-1, mp);
}

void printInorder(Node* root){
  if(root == NULL) return;  
  printInorder(root->left);  
  cout<<root->data<<" ";
  printInorder(root->right);
}

int main(){
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  Node* root = buildTreeWrap(in, pre, len);
  printInorder(root);
  return 0;
}