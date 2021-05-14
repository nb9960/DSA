#include <bits/stdc++.h>
using namespace std;

// by making deque operation costly kyuki enque m 2 baar loop chalana pdhh rha h

class Queue {
  stack<int> s1, s2;
  int curr_size;

public:
  Queue(){
    curr_size = 0;
  }

  void enqueue(int x){
    s1.push(x);
  }

  int dequeue(){
    if(s1.empty() && s2.empty()){
      cout<<"Queue is empty"<<endl;
      exit(0);
    }
    if(s2.empty()){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
    }
    int x=s2.top();
    s2.pop();
    return x;
  }
};

int main(){
  Queue q;
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  return 0;
}