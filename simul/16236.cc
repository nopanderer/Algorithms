/**
 * 아기 상어
 * 16236
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct Fish{
  int x;
  int y;
  int eat;
  int size;
  int time;
};
bool cmp(const Fish &f1, const Fish &f2){
  if(f1.time == f2.time){
    if(f1.x == f2.x){
      return f1.y < f2.y;
    }
    else{
      return f1.x < f2.x;
    }
  }
  else{
    return f1.time < f2.time;
  }
}
int N;
int a[21][21];
int v[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  queue<Fish> q;
  vector<Fish> f;
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
      if(a[i][j] == 9){
        a[i][j] = 0;
        q.push({i,j,0,2,0});
      }
    }
  }

  int ans = 0;
  while(true){
    memset(v, 0, sizeof(v));
    while(!q.empty()){
      int x = q.front().x;
      int y = q.front().y;
      int size = q.front().size;
      int eat = q.front().eat;
      int time = q.front().time;
      q.pop();
      for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N){
          continue;
        }
        if(v[nx][ny] != 0){
          continue;
        }
        if(a[nx][ny] == 0 || a[nx][ny] == size){
          v[nx][ny] = 1;
          q.push({nx,ny,eat,size,time+1});
        }
        else if(a[nx][ny] != 0 && a[nx][ny] < size){
          v[nx][ny] = 1;
          f.push_back({nx,ny,eat+1,size,time+1});
        }
      }
    }

    if(f.empty()){
      break;
    }
    sort(f.begin(), f.end(), cmp);

    if(f[0].size == f[0].eat){
      f[0].size++;
      f[0].eat = 0;
    }
    a[f[0].x][f[0].y] = 0;
    ans += f[0].time;
    q.push({f[0].x, f[0].y, f[0].eat, f[0].size, 0});
    f.clear();
  }
  cout << ans << '\n';
  return 0;
}
