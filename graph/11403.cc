/**
 * 경로 찾기
 * 11403
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
int a[101][101];
int ans[101][101];
bool c[101];
int n;
void dfs(int start, int x){
  ans[start][x] = 1;
  c[x] = 1;
  for(int i=0;i<n;i++){
    if(a[x][i] == 1 && c[i] == 0){
      dfs(start, i);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }

  for(int i=0;i<n;i++){
    memset(c, 0, sizeof(c));
    for(int j=0;j<n;j++){
      if(a[i][j] == 1 && c[j] == 0){
        dfs(i,j);
      }
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
