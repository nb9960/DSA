#include <bits/stdc++.h>
using namespace std;

/* n no of eggs & k floors. find least no. of egg droppings that is guaranteed 
to find the highest floor from which the egg wont break on dropping */

// VVIP solution time comp O(n*k)
int superEggDrop(int n, int k) {
  /*
  dp[M][n]means that, given n eggs and M moves,
  what is the maximum number of floor that we can check.

  The dp equation is:
  dp[m][n] = dp[m - 1][n - 1] + dp[m - 1][n] + 1,
  which means we take 1 move to a floor,
  if egg breaks, then we can check dp[m - 1][n - 1] floors.
  if egg doesn't breaks, then we can check dp[m - 1][n] floors.

  dp[m][n] is the number of combinations and it increase exponentially to k
  */
  int dp[k+1][n+1];
  memset(dp, 0, sizeof(dp));
  int m = 0;
  while (dp[m][n] < k) {
    m++;
    for (int i = 1; i <= n; ++i)
      dp[m][i] = dp[m - 1][i - 1] + dp[m - 1][i] + 1;
  }
  return m;
  }


// using DP --- time comp O(n*k^2); space O(n*k);
int eggDrop(int n, int k){
  // 2D table where eggFloor[i][j] --> minimum no. of trials needed for i eggs j floors
  int eggFloor[n+1][k+1], res;

  // if there are no floors, no trials needed
  // if there is 1 floor 1 trial needed
  for(int i=1;i<=n;i++){
    eggFloor[i][1] = 1; // floor 1 hai toh 1 trial
    eggFloor[i][0] = 0; // floor 0 hai toh 0 trial
  }

  // k trials for 1 egg & k floors
  for(int j=1;j<=k;j++)
    eggFloor[1][j] = j; // j trials for 1 egg & j floor

  // i--> no. of eggs; j--> no. of floors
  for(int i=2;i<=n;i++){
    for(int j=2;j<=k;j++){
      eggFloor[i][j] = INT_MAX;
      // j floor tk ka ans lene ke liye j tk ke harr floor pe jaake dekho
      for(int x=1;x<=j;x++){
        // kisi bhi x floor ke liye 2 cases honge ya toh egg tuta ya bacha toh dono cases ka max lo
        // (n-1, x-1) --> egg tuta mtlb req floor lies below this floor toh x-1;
        // (n, k-x)--> nahi tuta to ab bs k-x wale floors ko dekho
        // +1 kyuki uss girane wale floor wala turn bhi count kro
        res = 1 + max(eggFloor[i-1][x-1], eggFloor[i][j-x]);
        if(res < eggFloor[i][j])
          eggFloor[i][j] = res;
      }
    }
  }
  return eggFloor[n][k];
}




// fn to get min no. of trials needed in worst case with n eggs & k floors
int eggDropRec(int n, int k){
  // if there are no floors, no trials needed
  // if there is 1 floor 1 trial needed
  if(k==1 || k==0) return k;

  // k trials for 1 egg & k floors
  if(n==1) return k;
  int minm = INT_MAX, x, res;
  
  //pehle se akhiri harr floor m girake dekho aur sabka minimum le lo
  // x-->kis floor se gira rahe / current floor
  for(x=1;x<=k;x++){
    // kisi bhi x floor ke liye 2 cases honge ya toh egg tuta ya bacha toh dono cases ka max lo
    // (n-1, x-1) --> egg tuta mtlb req floor lies below this floor to x-1;
    // (n, k-x)--> nahi tuta to ab bs k-x wale floors ko dekho
    res = max(eggDropRec(n-1, x-1), eggDropRec(n, k-x));
    minm = min(res, minm);
  }
  return minm+1; // +1 kyuki uss girane wale floor wala turn bhi count kro
}



int main(){
  int n = 2, k = 6;
  cout<<""<<eggDropRec(n, k)<<" using Dp: "<<eggDrop(n,k)<<" using O(n*k): "<<superEggDrop(n, k)<<endl;
  return 0;
}