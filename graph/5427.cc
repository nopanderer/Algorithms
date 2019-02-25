/**
 * 불
 * 5427
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
int t;
int w,h;
char a[1001][1001];
int fireC[1001][1001];
int moveC[1001][1001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    memset(a, 0, sizeof(a));
    memset(fireC, -1, sizeof(fireC));
    memset(moveC, -1, sizeof(moveC));
    queue<pair<int,int>> move;
    queue<pair<int,int>> fire;
    cin >> w >> h;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        cin >> a[i][j];
        if(a[i][j] == '@'){
          moveC[i][j] = 0;
          move.push({i,j});
        }
        else if(a[i][j] == '*'){
          fireC[i][j] = 0;
          fire.push({i,j});
        }
      }
    }

    while(!fire.empty()){
      int x = fire.front().first;
      int y = fire.front().second;
      fire.pop();
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < h && 0 <= ny && ny < w){
          if(a[nx][ny] == '.' && fireC[nx][ny] == -1){
            fireC[nx][ny] = fireC[x][y] + 1;
            fire.push({nx, ny});
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
        if(0 <= nx && nx < h && 0 <= ny && ny < w){
          if(a[nx][ny] == '.' && moveC[nx][ny] == -1 && (fireC[nx][ny] == -1 || fireC[nx][ny] > moveC[x][y] + 1)){
            moveC[nx][ny] = moveC[x][y] + 1;
            move.push({nx, ny});
          }
        }
      }
    }
    int ans = 987654321;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(i==0 || i==h-1 || j==0 || j==w-1){
          if(moveC[i][j] != -1){
            ans = min(ans, moveC[i][j]);
          }
        }
      }
    }
    if(ans == 987654321){
      cout << "IMPOSSIBLE\n";
    }
    else{
      cout << ans + 1<< '\n';
    }
  }

  return 0;
}
