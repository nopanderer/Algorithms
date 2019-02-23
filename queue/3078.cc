/**
 * 좋은 친구
 * 3078
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    string s;
    string xs;
    int n;
    deque<int> a;
    deque<int> ra;
    cin >> s >> n >> xs;
    int idx = 1;
    while(xs.size() > 2 && idx < xs.size()){  
      string tmp = "";
      while(xs[idx] != ',' && xs[idx] != ']'){
        tmp += xs[idx];
        idx++;
      }
      a.push_back(stoi(tmp));
      ra.push_front(stoi(tmp));
      idx++;
    }
    int cnt = 0;
    bool error = false;
    for(int i=0;i<s.size();i++){
      if(s[i] == 'R'){
        cnt++;
      }
      else{
        if(a.empty()){
          error = true;
          break;
        }
        if(cnt%2 == 0){
          a.pop_front();
          ra.pop_back();
        }
        else{
          a.pop_back();
          ra.pop_front();
        }
      }
    }
    if(error){
      cout << "error\n";
      continue;
    }
    if(a.empty()){
      cout << "[]\n";
      continue;
    }
    if(cnt%2 == 0){
      cout << '[';
      for(int i=0;i<a.size()-1;i++){
        cout << a[i] << ',';
      }
      if(!a.empty()){
        cout << a[a.size()-1] << ']' << '\n';
      }
    }
    else{
      cout << '[';
      for(int i=0;i<ra.size()-1;i++){
        cout << ra[i] << ',';
      }
      if(!ra.empty()){
        cout << ra[ra.size()-1] << ']' << '\n';
      }
    }
  }

  return 0;
}
