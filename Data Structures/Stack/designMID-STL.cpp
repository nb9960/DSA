/*
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
*/

#include <bits/stdc++.h>
using namespace std;
list<int>::iterator mid;  //to keep track of middle element

void push(list<int>& dll, int x){
  if(dll.size() == 0){
    dll.push_front(x);
    mid = dll.begin();
  }else{
    dll.push_front(x);
    int size = dll.size();
    if(size%2 == 0){
      mid = prev(mid, 1);
    }
  }
}

int top(list<int> dll){
  if(dll.size() == 0)
    return -1;
  return dll.front();
}

int pop(list<int>& dll){
  if(dll.size() == 0)
    return -1;
  int x = dll.front();
  dll.pop_front();
  int size = dll.size();

  if(size <= 1)
    mid = dll.begin();
  else if(size%2 == 0)
    mid = next(mid, 1);
  return x;
}

int findMiddle(list<int> dll){
  if(dll.size() == 0)
    return -1;
  return *mid;
}

int main(){
  list<int> dll;
  push(dll, 11);
  push(dll, 22);
  push(dll, 33);
  push(dll, 44);
  push(dll, 55);
  push(dll, 66);
  push(dll, 77);

  cout << "Top element    = " << top(dll) << endl;
  cout << "Middle Element = " << findMiddle(dll) << endl;
  cout << "Popped element = " << pop(dll) << endl;
  cout << "Top element    = " << pop(dll) << endl;
  cout << "Middle Element = " << findMiddle(dll) << endl;
  return 0;
}