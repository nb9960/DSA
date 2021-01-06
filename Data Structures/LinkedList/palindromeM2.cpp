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
  Node *slow_ptr = head, *fast_ptr = head;
  Node *second_half, *prev_of_slow_ptr;
  // prev of slow ptr to get the last index  of 1st half
  Node *midnode = NULL; // To handle odd size list
  bool res=true;

  if(head != NULL && head->ptr !=NULL){
    // to get the middle node
    while(fast_ptr != NULL && fast_ptr->ptr !=NULL){
      fast_ptr=fast_ptr->ptr->ptr;
      prev_of_slow_ptr = slow_ptr;
      slow_ptr = slow_ptr -> ptr;
    }

    /* fast_ptr would become NULL when there are even elements in list. 
    And not NULL for odd elements. We need to skip the middle node 
    for odd case and store it somewhere so that we can restore the 
    original list*/
    if (fast_ptr != NULL) { 
        midnode = slow_ptr; 
        slow_ptr = slow_ptr->ptr; 
    } 

    // reversing the 2nd half and comparing with 1st
    second_half = slow_ptr;
    prev_of_slow_ptr->ptr = NULL; // NULL terminate first half
    reverse(&second_half);
    res = compareLists(head, second_half);
    reverse(&second_half);
    if(midnode != NULL){
      prev_of_slow_ptr->ptr = midnode;
      midnode -> ptr = second_half;
    }else{
      prev_of_slow_ptr->ptr = second_half;
    }
  }
  return res;
}

bool compareLists(Node *head1, Node *head2){
  Node *tmp1 = head1;
  Node *tmp2= head2;
  while(tmp1 != NULL && tmp2 != NULL){
    if(tmp1->data == tmp2->data){
      tmp1 = tmp1->ptr;
      tmp2 = tmp2->ptr;
    }else
      return 0;
  }
  /* Both are empty reurn 1*/
  if (tmp1 == NULL && tmp2 == NULL) 
      return 1; 

  /* Will reach here when one is NULL 
  and other is not */
  return 0; 
}

void reverse(Node** head_ref){
  Node *prev = NULL;
  Node *current = *head_ref;
  Node *next;
  while(current != NULL){
    next = current->ptr;
    current->ptr = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
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