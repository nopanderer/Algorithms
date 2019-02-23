/**
 * 프린터 큐
 * 1966
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t,n,m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    queue<pair<int,int>> q;
    int c[101];
    for(int i=0;i<n;i++){
      int x;
      cin >> x;
      q.push({x,i});
    }
    int cnt = 0;
    while(true){
      if(q.empty()){
        break;
      }
      bool found = false;
      int now = q.front().first;
      int nowIdx = q.front().second;
      q.pop();
      for(int i=0;i<q.size();i++){
        int next = q.front().first;
        int nextIdx = q.front().second;
        q.pop();
        if(next > now){
          found = true;
        }
        q.push({next, nextIdx});
      }
      if(!found){
        c[nowIdx] = ++cnt;
      }
      else{
        q.push({now, nowIdx});
      }
    }
    cout << c[m] << '\n';
  }
  return 0;
}
