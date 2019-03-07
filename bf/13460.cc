/**
 * 구슬 탈출 2
 * 13460
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
struct Ball{
  int d;
  int rx,ry,bx,by;
};
int N,M;
int board[11][11];
bool visit[10][10][10][10];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int srx,sry,sbx,sby,hx,hy;
string s;
int ans = -1;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> s;
    for(int j=0;j<M;j++){
      if(s[j] == '#'){
        board[i][j] = 1;
      }
      else if(s[j] == 'R'){
        srx = i;
        sry = j;
      }
      else if(s[j] == 'B'){
        sbx = i;
        sby = j;
      }
      else if(s[j] == 'O'){
        board[i][j] = 2;
        hx = i;
        hy = j;
      }
    }
  }

  queue<Ball> q;
  q.push({0,srx,sry,sbx,sby});
  visit[srx][sry][sbx][sby] = true;

  while(!q.empty()){
    Ball x = q.front();
    q.pop();

    if(x.d > 10){
      break;
    }
    if(x.rx == hx && x.ry == hy){
      ans = x.d;
      break;
    }

    for(int i=0;i<4;i++){
      int rx = x.rx;
      int ry = x.ry;
      int bx = x.bx;
      int by = x.by;
      
      // move red
      while(true){
        rx += dx[i];
        ry += dy[i];
        if(rx < 0 || rx > N || ry < 0 || ry > M){
          break;
        }
        if(board[rx][ry] == 1){
          rx -= dx[i];
          ry -= dy[i];
          break;
        }
        else if(board[rx][ry] == 2){
          break;
        }
      }
      // move blue
      while(true){
        bx += dx[i];
        by += dy[i];
        if(bx < 0 || bx > N || by < 0 || by > M){
          break;
        }
        if(board[bx][by] == 1){
          bx -= dx[i];
          by -= dy[i];
          break;
        }
        else if(board[bx][by] == 2){
          break;
        }
      }

      if(bx == hx && by == hy){
        continue;
      }
      if(rx == bx && ry == by){
        switch(i){
          case 0:
            x.rx < x.bx ? bx++ : rx++;
            break;
          case 1:
            x.rx < x.bx ? rx-- : bx--;
            break;
          case 2:
            x.ry < x.by ? by++ : ry++;
            break;
          case 3:
            x.ry < x.by ? ry-- : by--;
            break;
        }
      }
      if(visit[rx][ry][bx][by] == false){
        q.push({x.d + 1, rx,ry,bx,by});
        visit[rx][ry][bx][by] = true;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
