#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;
};

void push(Node **head, int new_data){
  Node* new_node = new Node();
  new_node->data =new_data;
  new_node->next = *head;
  *head = new_node;
}

void printNthFromLast(Node *head, int n){
  Node *main_ptr = head;
  Node *ref_ptr = head;
  int cnt = 0;
  if(head != NULL){
    while(cnt < n){
      if(ref_ptr == NULL){
        cout<<"NA"<<endl;
        return;
      }
      ref_ptr = ref_ptr->next;
      cnt++;
    }
    if(ref_ptr == NULL){
      head = head->next;
      if(head != NULL)
        cout<<main_ptr->data<<endl;
    }else{
      while(ref_ptr != NULL){
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
      }
      cout<<main_ptr->data<<endl;
    }
  }
}

void printNthFromLastUsingLength(Node *head, int n){
  int len = 0;
  Node* temp = head;
  while(temp != NULL){
    temp = temp->next;
    len++;
  }
  if(len < n)
    return;
  temp = head;
  for(int i = 1; i<len - n + 1; i++)
    temp = temp->next;
  cout<<temp->data<<endl;
  return;
}

int main(){
  Node *a = NULL;
  push(&a, 6);
  push(&a, 5);
  push(&a, 4);
  push(&a, 3);
  printNthFromLastUsingLength(a, 3);
  // printNthFromLast(a, 3);
  return 0;
}