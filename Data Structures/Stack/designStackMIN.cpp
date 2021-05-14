// Design a stack that supports getMin() in O(1) time and O(1) extra space
#include <bits/stdc++.h>
using namespace std;

struct MyStack{
  stack<int> s;
  int minEl;

  void getMin(){
    if(s.empty())
      cout<<"Stack is Empty\n";
    else cout<<"Min element is: "<<minEl<<endl;
  }

  void peek(){
    if(s.empty()){
      cout<<"Stack is empty";
      return;
    }
    int t = s.top();
    cout<<"Top element is: ";
    (t<minEl) ? cout<<minEl : cout<<t;
  }

  void pop(){
    if(s.empty()){
      cout<<"Stack is empty\n";
      return;
    }
    cout<<"Top most element removed: ";
    int t = s.top();
    s.pop();
    if(t<minEl){
      cout<<minEl<<"\n";
      minEl = 2*minEl - t;
    }else{
      cout<<t<<"\n";
    }
  }

  void push(int x){
    if(s.empty()){
      minEl = x;
      s.push(x);
      cout<<"Number inserted: "<<x<<"\n";
      return;
    }
    if(x<minEl){
      s.push(2*x - minEl);
      minEl = x;
    }else{
      s.push(x);
    }
    cout<<"Number inserted: "<<x<<"\n";
  }
};

int main(){
  MyStack s;
  s.push(3);
  s.push(5);
  s.getMin();
  s.push(2);
  s.push(1);
  s.getMin();
  s.pop();
  s.getMin();
  s.pop();
  s.peek();
  return 0;
}

/*
How previous minimum element, prevMinEle is, 2*minEle - y
in pop() is y the popped element?

 // We pushed y as 2x - prevMinEle. Here 
 // prevMinEle is minEle before y was inserted
 y = 2*x - prevMinEle  

 // Value of minEle was made equal to x
 minEle = x .
    
 new minEle = 2 * minEle - y 
            = 2*x - (2*x - prevMinEle)
            = prevMinEle // This is what we wanted
*/