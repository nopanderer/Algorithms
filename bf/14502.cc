/**
 * 연구소
 * 14502
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
int N,M;
int a[9][9];
bool c[9][9];
int ans;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void go(int x, int y, int cnt){
  if(cnt == 3){
    // bfs
    memset(c, 0, sizeof(c));
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(a[i][j] == 2){
          q.push({i,j});
        }
      }
    }

    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny < M){
          if(a[nx][ny] == 0 && c[nx][ny] == false){
            c[nx][ny] = true;
            q.push({nx,ny});
          }
        }
      }
    }
    
    int sum = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(a[i][j] == 0 && c[i][j] == false){
          sum++;
        }
      }
    }
    if(ans < sum){
      ans = sum;
    }

    return;
  }
  int j=y;
  for(int i=x;i<N;i++){
    for(;j<M;j++){
      if(a[i][j] == 0){
        a[i][j] = 1;
        go(i,j,cnt+1);
        a[i][j] = 0;
      }
    }
    j=0;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> a[i][j];
    }
  }

  go(0,0,0);

  cout << ans << '\n';

  return 0;
}
