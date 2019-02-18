/**
 * 게임판 덮기
 * boardcover
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
int c,h,w;
int a[21][21];
int dx[4][2] = {{0,1},
                {1,1},
                {0,1},
                {1,1}};
int dy[4][2] = {{1,0},
                {0,1},
                {1,1},
                {-1,0}};
int ans;
void solve(int cntWt){
  if(cntWt == 0){
    ans++;
  }
  int x = -1;
  int y = -1;
  for(int i=0;i<h;i++){
    bool found = false;
    for(int j=0;j<w;j++){
      if(a[i][j] == 0){
        x = i;
        y = j;
        found = true;
        break;
      }
    }
    if(found) break;
  }
  for(int i=0;i<4;i++){
    bool flag = true;
    for(int j=0;j<2;j++){
      int nx = x + dx[i][j];
      int ny = y + dy[i][j];
      if(0 > nx || nx >= h || 0 > ny || ny >= w){
        flag = false;
        break;
      }
      if(a[nx][ny] == 1){
        flag = false;
        break;
      }
    }
    if(flag == true){
      a[x][y] = 1;
      a[x+dx[i][0]][y+dy[i][0]] = 1;
      a[x+dx[i][1]][y+dy[i][1]] = 1;
      solve(cntWt-3);
      a[x][y] = 0;
      a[x+dx[i][0]][y+dy[i][0]] = 0;
      a[x+dx[i][1]][y+dy[i][1]] = 0;
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> c;
  while(c--){
    int cntWt = 0;
    ans = 0;
    cin >> h >> w;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        char c;
        cin >> c;
        if(c == '#'){
          a[i][j] = 1;
        }
        else if(c == '.'){
          a[i][j] = 0;
          cntWt++;
        }
      }
    }
    if(cntWt ==  0 || cntWt%3 != 0){
      cout << "0\n";
      continue;
    }
    solve(cntWt);
    cout << ans << '\n';
  }

  return 0;
}
