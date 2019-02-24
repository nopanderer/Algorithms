/**
 * 안전 영역
 * 2468
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
int n;
int h;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[101][101];
bool c[101][101];
int cnt;
int ans = 1;
void dfs(int x, int y, int h){
  c[x][y] = true;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < n && 0 <= ny && ny < n){
      if(a[nx][ny] > h && c[nx][ny] == false){
        dfs(nx, ny, h);
      }
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
      h = max(h, a[i][j]);
    }
  }
  // consider every possible heights
  for(int i=1;i<=h;i++){
    memset(c, 0, sizeof(c));
    cnt = 0;
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        if(a[j][k] > i && c[j][k] == false){
          dfs(j,k,i);
          cnt++;
        }
      }
    }
    ans = max(ans, cnt);
  }

  cout << ans << '\n';

  return 0;
}
