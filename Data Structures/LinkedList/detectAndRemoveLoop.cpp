#include <bits/stdc++.h>
using namespace std;

/*
4 methods :
  1. hashing - simplest but space complexity zyada
  2. Floyd's Cycle detection (I)
      Detect loop and get pointer to loop node
      Count the no. of nodes in loop using this (lets say count = k)
      ek ptr head pe rakho aur ek head se kth node pe
      ab dono pts ko same pace se chalao, vo loop ke starting node p milenge
      last node ka ptr pkdo ek ko k dist chlake aur uska next null kr do
  3. After detecting the loop, if we start slow pointer from head 
     and move both slow and fast pointers at same speed until fast don’t meet, 
     they would meet at the beginning of the loop.
*/

struct Node {
  int key;
  struct Node* next;
};

Node* newNode(int key){
  Node* temp = new Node;
  temp->key = key;
  temp->next = NULL;
  return temp;
}

void detectAndRemoveLoop(Node* head){
  if(head == NULL || head->next == NULL)
    return;
  Node *slow = head, *fast = head;
  slow = slow->next;
  fast = fast->next->next;

  while(fast && fast->next){
    if(slow == fast)
      break;
    slow = slow->next;
    fast = fast->next->next;
  }

  if(slow == fast){
    slow = head;
    // agar head se hi loop ho to
    if(slow == fast){
      while(fast->next != slow) fast = fast->next;
    }else{
      while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
      }
    }
    fast->next = NULL;
  }
}

int main(){
  Node* head = newNode(50);
  head->next = head;
  head->next = newNode(20);
  head->next->next = newNode(15);
  head->next->next->next = newNode(4);
  head->next->next->next->next = newNode(10);

  head->next->next->next->next->next = head;
  return 0;
}