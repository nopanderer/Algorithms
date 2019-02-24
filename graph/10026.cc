/**
 * 적록색약
 * 10026
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
int a[101][101];
bool c[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cnt1;
int cnt2;
void dfs(int x, int y, int mode){
  c[x][y] = true;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < n && 0 <= ny && ny < n){
      // normal
      if(mode == 0){
        if(a[x][y] == a[nx][ny] && c[nx][ny] == false){
          dfs(nx, ny, 0);
        }
      }
      else{
        if(c[nx][ny] == false){
          if(a[x][y] == a[nx][ny] || (a[x][y] + a[nx][ny])%2 == 0){
            dfs(nx, ny, 1);
          }
        }
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
      char tmp;
      cin >> tmp;
      if(tmp == 'R'){
        a[i][j] = 2;
      }
      else if(tmp == 'G'){
        a[i][j] = 4;
      }
      else{
        a[i][j] = 7;
      }
    }
  }

  // normal
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(c[i][j] == false){
        dfs(i,j,0);
        cnt1++;
      }
    }
  }
  memset(c, 0, sizeof(c));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(c[i][j] == false){
        dfs(i,j,1);
        cnt2++;
      }
    }
  }

  cout << cnt1 << ' ' << cnt2 << '\n';

  return 0;
}
