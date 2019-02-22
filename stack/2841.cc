/**
 * 외계인의 기타 연주
 * 2841
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
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,p;
  cin >> n >> p;
  stack<int> st[7];
  int ans = 0;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    while(!st[x].empty() && st[x].top() > y){
      st[x].pop();
      ans++;
    }
    if(!st[x].empty() && st[x].top() == y){
      continue;
    }
    st[x].push(y);
    ans++;
  }
  cout << ans << '\n';
  return 0;
}
