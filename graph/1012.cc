/**
 * 유기농 배추
 * 1012
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
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[51][51];
bool check[51][51];
int t,r,c,k;
int x,y;
void dfs(int x, int y){
  check[x][y] = true;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(a[nx][ny] == 1 && check[nx][ny] == false){
      dfs(nx, ny);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    memset(a,0,sizeof(a));
    memset(check,0,sizeof(check));
    cin >> r >> c >> k;
    for(int i=0;i<k;i++){
      cin >> x >> y;
      a[y][x] = 1;
    }
    int cnt = 0;
    for(int i=0;i<c;i++){
      for(int j=0;j<r;j++){
        if(a[i][j] == 1 && check[i][j] == false){
          dfs(i,j);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}
