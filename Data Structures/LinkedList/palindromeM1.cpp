#include <bits/stdc++.h>
using namespace std; 

class Node{
public:
  int data;
  Node(int d){
    data=d;
  }
  Node *ptr;
};

bool isPalin(Node* head){
  stack<int>s;

  Node* tmp=head;
  while(tmp!=NULL){
    s.push(head->data);
    tmp=tmp->ptr;
  }

  while(head!=NULL){
    int i=s.top();
    if(head->data != i){
      return false;
    }
    head=head->ptr;
  }
  return true;
}

int main(){
  Node one = Node(1);
  Node two = Node(2);
  Node three = Node(3);
  Node four = Node(2);
  Node five = Node(1);

  five.ptr = NULL;
  one.ptr = &two;
  two.ptr = &three;
  three.ptr = &four;
  four.ptr = &five;

  isPalin(&one) ? cout<<"Is Palindrome"<<endl : cout<<"Not a Palindrome"<<endl; 
  return 0;
}