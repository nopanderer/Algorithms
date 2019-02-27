/**
 * 교환
 * 1039
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
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string n;
  int k;
  queue<string> q;
  cin >> n >> k;
  q.push(n);
  for(int i=0;i<k;i++){
    set<string> found;
    int size = q.size();
    for(int ii=0; ii<size;ii++){
      string now = q.front();
      q.pop();
      if(found.count(now) != 0){
        continue;
      }
      found.insert(now);
      for(int j=0;j<now.size()-1;j++){
        for(int l=j+1;l<now.size();l++){
          if(now[l] != '0' || j > 0){
            swap(now[j], now[l]);
            q.push(now);
            swap(now[j], now[l]);
          }
        }
      }
    }
  }
  string ans = "0";
  while(!q.empty()){
    ans = max(ans, q.front());
    q.pop();
  }
  if(ans[0] == '0'){
    cout << "-1\n";
  }
  else{
    cout << ans << '\n';
  }

  return 0;
}
