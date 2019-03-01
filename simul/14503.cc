/**
 * 로봇 청소기
 * 14503
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
int a[51][51];
bool clean[51][51];
int r,c,d;
int ans;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
bool check(int x, int y){
  if(0 <= x && x < N && 0 <= y && y < M){
    return true;
  }
  else{
    return false;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  cin >> r >> c >> d;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> a[i][j];
    }
  }

  while(true){
    // clean the cur position
    if(clean[r][c] == false){
      clean[r][c] = true;
      ans++;
    }
    bool flag = false;
    for(int i=0;i<4;i++){
      d--;
      if(d < 0) d = 3;
      int nr = r + dr[d];
      int nc = c + dc[d];
      if(check(nr, nc)){
        if(a[nr][nc] != 1 && clean[nr][nc] == false){
          r = nr;
          c = nc;
          flag = true;
          break;
        }
      }
    }
    if(flag == false){
      int tmp = d - 2;
      if(tmp < 0) tmp = d + 2;
      int nr = r + dr[tmp];
      int nc = c + dc[tmp];
      if(check(nr, nc) && a[nr][nc] != 1){
        r = nr;
        c = nc;
      }
      else{
        break;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
