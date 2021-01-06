#include <bits/stdc++.h>
using namespace std; 

class Node{
public:
  int data;
  Node(int d){
    data=d;
  }
  Node *next;
};

Node* sortedIntersect (Node *a, Node *b){
  if(a==NULL || b==NULL)
    return NULL;
  
  if(a->data < b->data)
    return sortedIntersect(a->next, b);
  if(a->data > b->data)
    return sortedIntersect(a,b->next);
  
  Node *tmp;
  tmp->data = a->data;
  tmp->next = sortedIntersect(a->next, b->next);
  return tmp;
}

void push(Node **head, int new_data){
  Node *new_node;
  new_node->data =new_data;
  new_node->next = *head;
  *head = new_node;
}

void printList(Node* node){
  while(node != NULL){
    cout<<node->data<<" ";
    node = node->next;
  }
}

int main(){
  Node *a = NULL;
  Node *b =NULL;
  Node *intersect = NULL;
  /* Let us create the first sorted
    linked list to test the functions
    Created linked list will be 
    1->2->3->4->5->6 */
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  push(&a, 2);
  push(&a, 1);

  /* Let us create the second sorted linked list
    Created linked list will be 2->4->6->8 */
  push(&b, 8);
  push(&b, 6);
  push(&b, 4);
  push(&b, 2);

  /* Find the intersection two linked lists */
  intersect = sortedIntersect(a, b);

  printf("\n Linked list containing common items of a & b \n ");
  printList(intersect); 
  return 0;
}