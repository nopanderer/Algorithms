/**
 * 벽 부수고 이동하기
 * 2206
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
struct Point{
  int x;
  int y;
  int brk;
  Point(int x, int y, int brk){
    this->x = x;
    this->y = y;
    this->brk = brk;
  }
};
int n,m;
char a[1001][1001];
int c[1001][1001][2];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin >> a[i][j];
    }
  }
  
  queue<Point> q;
  c[0][0][0] = 1;
  q.push(Point(0,0,0));
  while(!q.empty()){
    Point now = q.front();
    int x = now.x;
    int y = now.y;
    int brk = now.brk;
    q.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(0 <= nx && nx < n && 0 <= ny && ny < m){
        // next block is empty
        if(a[nx][ny] == '0'){
          if(c[nx][ny][brk] == 0){
            c[nx][ny][brk] = c[x][y][brk] + 1;
            q.push(Point(nx,ny,brk));
          }
        }
        // next block is wall
        else{
          // never broken before
          if(brk == 0){
            c[nx][ny][1] = c[x][y][brk] + 1;
            q.push(Point(nx,ny,1));
          }
        }
      }
    }
  }
  
  int a = c[n-1][m-1][0];
  int b = c[n-1][m-1][1];

  if(a == 0 && b == 0){
    cout << "-1\n";
  }
  else if(a == 0 && b != 0){
    cout << b << '\n';
  }
  else if(a != 0 && b == 0){
    cout << a << '\n';
  }
  else{
    cout << min(a,b) << '\n';
  }

  return 0;
}
