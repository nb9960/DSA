// nb_9960
#include <bits/stdc++.h> 
using namespace std; 

class Node {
public:
    int data;
    Node* next;
};

int count(Node *head){
  int cnt=0;
  while(head!=NULL){
    cnt++;
    head=head->next;
  }
  return cnt;
}

int getIntersectionNode(int d, Node* head1, Node *head2){
  Node *current1 = head1;
  Node *current2 = head2;

  for(int i=0; i <d ; i++){
    if(current1 == NULL)
      return -1;
    current1 = current1->next;
  }

  while(current1 != NULL && current2 != NULL){
    if(current1 == current2)
      return current1->data;
    current1 = current1->next;
    current2 = current2->next;
  }
  return -1;
}

int main() 
{  
  /* 
      Create two linked lists 
    
      1st 3->6->9->15->30 
      2nd 10->15->30 
    
      15 is the intersection point 
  */

  Node* newNode;

  // Addition of new nodes
  Node* head1 = new Node();
  head1->data = 10;

  Node* head2 = new Node();
  head2->data = 3;

  newNode = new Node();
  newNode->data = 6;
  head2->next = newNode;

  newNode = new Node();
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = new Node();
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next = newNode;

  newNode = new Node();
  newNode->data = 30;
  head1->next->next = newNode;

  head1->next->next->next = NULL;

  int c1= count(head1);
  int c2 = count(head2);
  int d = abs(c1-c2);

  if (c1 > c2) {
      d = c1 - c2;
      cout<<"The node of intersection is: "<<getIntersectionNode(d, head1, head2)<<endl;
  }
  else {
      d = c2 - c1;
      cout<<"The node of intersection is: "<<getIntersectionNode(d, head2, head1)<<endl;
  }

  return 0; 
} 
