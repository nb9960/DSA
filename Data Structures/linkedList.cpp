// Author:Nishtha
#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long

struct Node{
  ll data;
  struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void Display(struct Node *p){
  while(p!=NULL){
    cout<<p->data;
    p=p->next;
  }
}

void create(ll a[], ll n){
  ll i;
  struct Node *t,*last;
  first= new Node;
  first->next=NULL;
  last=first;

  fi(i,1,n){
    t=new Node;
    t->data=a[i];
    t->next=t;
    last->next=t;
    last=t;
  }
}

void sortedInsert(struct Node *p,ll x){
  struct Node *t,*q=NULL;
  t=new Node;
  t->data=x;
  t->next=NULL;

  if(first==NULL){
    first=t;
  }
  else{
    while (p && p->data<x)
    {
      q=p;
      p=p->next;
    }
    if(p==first){
      t->next=first;
      first=t;
    }else{
      t->next=q->next;
      q->next=t;
    }
    
  }
}

int main() 
{  
  ll n;
  cin>>n;
  ll a[n];
  fi(i,0,n)
  cin>>a[i];
  create(a,n);
  sortedInsert(first,15);
  Display(first);
  return 0; 
} 
