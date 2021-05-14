#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> sets;
  vector<int> s1 = {1,1,2,2,5};
  vector<int> s2 = {1,1,4,3,5,9};
  vector<int> s3 = {1,1,2,3,5,6};
  sets.push_back(s1);
  sets.push_back(s2);
  sets.push_back(s3);
  vector<int> r;

  int smallSetInd = 0, minSize = sets[0].size();
  // sort all sets and find smallest set
  for(int i=1;i<sets.size();i++){
    sort(sets[i].begin(), sets[i].end());
    if(minSize > sets[i].size()){
      minSize = sets[i].size();
      smallSetInd = i;
    }
  }

  map<int, int> elementsMap;

  //  add all elements of smallest set to map agar pehle se hi h to update freq
  for(int i=0;i<sets[smallSetInd].size();i++){
    if(elementsMap.find(sets[smallSetInd][i]) == elementsMap.end())
      elementsMap[sets[smallSetInd][i]] = 1;
    else elementsMap[sets[smallSetInd][i]]++;
  }

  map<int, int>:: iterator it;
  for(it = elementsMap.begin(); it!= elementsMap.end(); ++it){
    int elem = it->first, freq = it->second;

    bool found = true;
    for(int j=0;j<sets.size();j++){
      if(j != smallSetInd){
        if(binary_search(sets[j].begin(), sets[j].end(), elem)){
          int lInd = lower_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();
          int uInd = upper_bound(sets[j].begin(), sets[j].end(), elem) - sets[j].begin();
          if((uInd- lInd) > freq)
            freq = uInd - lInd;
        }else{
          found = false;
          break;
        }
      }
    }
    if (found)
      for(int k = 0; k < freq; k++) 
        r.push_back(elem); 
  }

  for(auto num : r){
    cout<<num<<" ";
  }
  return 0;
}