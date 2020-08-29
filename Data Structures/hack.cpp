// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pl; 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<pii> vpii; 

struct Node{
  int data;
  struct Node *next;
}*first=NULL;

void Insert(struct Node *p, int x){
  struct Node *t;
  t=new Node;
  t->data=x;
  t->next=NULL;
  if(p==NULL){
    p=t;
  }else{
    while(p!=NULL){
      p=p->next;
    }
    p->next=t;
  }
  cout<<p->data<<"\n";
}

// Drive Code 
int main() 
{  
  // #ifndef ONLINE_JUDGE 
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout); 
  // #endif
  // Fast Input/Output 
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  // Test Cases 
  // ll t = 1; 
  // cin >> t;

  // while (t--) { 
  // } 

  int n;
  cin>>n;
  int a[n];
  fi(i,0,n){
  cin>>a[i];
  Insert(first,a[i]);
  }


  return 0; 
} 
