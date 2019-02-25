/**
 * 탈출
 * 3055
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
int r,c;
char a[51][51];
int moveC[51][51];
int waterC[51][51];
int d1,d2;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(moveC, -1, sizeof(moveC));
  memset(waterC, -1, sizeof(waterC));
  queue<pair<int,int>> move;
  queue<pair<int,int>> water;
  cin >> r >> c;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      cin >> a[i][j];
      if(a[i][j] == 'S'){
        moveC[i][j] = 0;
        move.push({i,j});
      }
      else if(a[i][j] == 'D'){
        d1 = i;
        d2 = j;
      }
      else if(a[i][j] == '*'){
        waterC[i][j] = 0;
        water.push({i,j});
      }
    }
  }

  while(!water.empty()){
    int x = water.front().first;
    int y = water.front().second;
    water.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0 <= nx && nx < r && 0 <= ny && ny < c){
        if(a[nx][ny] == '.' && waterC[nx][ny] == -1){
          waterC[nx][ny] = waterC[x][y] + 1;
          water.push({nx,ny});
        }
      }
    }
  }

  while(!move.empty()){
    int x = move.front().first;
    int y = move.front().second;
    move.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0 <= nx && nx < r && 0 <= ny && ny < c){
        if((a[nx][ny] == 'D' || a[nx][ny] == '.') && moveC[nx][ny] == -1 && (waterC[nx][ny] == -1 || waterC[nx][ny] > moveC[x][y] + 1)){
          moveC[nx][ny] = moveC[x][y] + 1;
          move.push({nx,ny});
        }
      }
    }
  }

  if(moveC[d1][d2] == -1){
    cout << "KAKTUS\n";
  }
  else{
    cout << moveC[d1][d2] << '\n';
  }
  
  return 0;
}
