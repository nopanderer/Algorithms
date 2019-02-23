/**
 * 음식물 피하기
 * 1743
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
int n,m,k;
int x,y;
int a[101][101];
bool c[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt;
void dfs(int x, int y){
  c[x][y] = true;
  cnt++;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < n && 0 <= ny && ny < m){
      if(a[nx][ny] == 1 && c[nx][ny] == false){
        dfs(nx, ny);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for(int i=0;i<k;i++){
    cin >> x >> y;
    a[x-1][y-1] = 1;
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(a[i][j] == 1 && c[i][j] == false){
        cnt = 0;
        dfs(i,j);
        ans = max(ans, cnt);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
