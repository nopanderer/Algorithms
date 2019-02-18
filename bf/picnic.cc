/**
 * 소풍
 * picnic
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
int c,n,m;
int a,b;
bool f[11][11];
bool check[11];
int solve(int cnt, int idx){
  int ret = 0;
  if(cnt == n/2){
    return 1;
  }
  for(int i=idx;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(check[i] == false && check[j] == false && f[i][j] == true){
        check[i] = check[j] = true;
        ret += solve(cnt+1, i+1);
        check[i] = check[j] = false;
      }
    }
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> c;
  while(c--){
    for(int i=0;i<11;i++){
      check[i] = false;
      for(int j=0;j<11;j++){
        f[i][j] = false;
      }
    }
    cin >> n >> m;
    for(int i=0;i<m;i++){
      cin >> a >> b;
      f[a][b] = f[b][a] = true;
    }

    cout << solve(0,0) << '\n';
  }

  return 0;
}
