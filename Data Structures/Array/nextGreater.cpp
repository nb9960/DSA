#include <bits/stdc++.h>
using namespace std;

/*
Algorithm applied
I) Traverse the given number from rightmost digit, keep traversing till you find a digit 
  which is smaller than the previously traversed digit.
  For example, if the input number is “534976”, we stop at 4 because 4 is smaller than next digit 9. 
  If we do not find such a digit, then output is “Not Possible”.

II) Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. 
  For “534976″, the right side of 4 contains “976”. The smallest digit greater than 4 is 6.

III) Swap the above found two digits, we get 536974 in above example.

IV) Now sort all digits from position next to ‘d’ to the end of number. 
  The number that we get after sorting is the output. 
  For above example, we sort digits in bold 536974. 
  We get “536479” which is the next greater number for input 534976.
*/

int main(){
  string s = "534976";
  int n=s.size();
  int smaller=-1;
  for(int i=n-1;i>0;i--){
    if(s[i]>s[i-1]){
      smaller = i-1;
      break;
    }
  }
  if(smaller == -1) {
    cout<<"Not possible"<<endl;
  }else{
    char mnim = s[smaller+1];
    int min_ind = smaller+1;
    for(int j = smaller+2;j<s.size();j++){
      if(s[j]<mnim) {
        mnim = s[j]; min_ind = j;
      }
    }
    swap(s[min_ind], s[smaller]);
    sort(s.begin()+smaller+1, s.end());
    cout<<s<<endl;
  }
  return 0;
}