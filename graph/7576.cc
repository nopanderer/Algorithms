/**
 * 토마토
 * 7576
 */
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int a[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int M,N;
int ans;
void bfs(int x, int y){
  queue<pair<int,int> > q;
  q.push(make_pair(x,y));
  while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M){
        continue;
      }
      if(a[nx][ny] == 0 || a[nx][ny] > a[cx][cy] + 1){
        a[nx][ny] = a[cx][cy] + 1;
        q.push(make_pair(nx,ny));
      }
    }
  }
}
int main(){
  scanf("%d %d",&M,&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&a[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(a[i][j] == 1){
        bfs(i,j);
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(a[i][j] == 0){
        printf("-1\n");
        return 0;
      }
      else{
        ans = max(a[i][j], ans);
      }
    }
  }
  printf("%d\n",ans-1);

  return 0;
}
