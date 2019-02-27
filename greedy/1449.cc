/**
 * 수리공 항승
 * 1449
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
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N,L;
  bool c[2001];
  memset(c, 0, sizeof(c));
  vector<int> a;
  cin >> N >> L;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for(int i=0;i<N;i++){
    if(c[a[i]] == false){
      ans++;
      for(int j=0;j<L;j++){
        c[a[i]+j] = true;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
