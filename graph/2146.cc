/**
 * 다리 만들기
 * 2146
 */
#include <cstdio>
#include <queue>
using namespace std;

int a[101][101];
int g[101][101];
int d[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N;
void bfs(int x,int y,int group){
  queue<pair<int,int> >q;
  g[x][y] = group;
  q.push(make_pair(x,y));
  while(!q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    q.pop();
    for(int i=0;i<4;i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if(0 <= nx && nx < N && 0 <= ny && ny <= N){
        if(a[nx][ny] == 1 && g[nx][ny] == 0){
          g[nx][ny] = group;
          q.push(make_pair(nx,ny));
        }
      }
    }
  }
}
int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&a[i][j]);
    }
  }
  // find group
  int group = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a[i][j] == 1 && g[i][j] == 0){
        bfs(i,j,group++);
      }
    }
  }
  int ans = -1;
  for(int gr=1;gr<group;gr++){
    queue<pair<int,int> > q;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        d[i][j] = -1;
        if(g[i][j] == gr){
          d[i][j] = 0;
          q.push(make_pair(i,j));
        }
      }
    }
    while(!q.empty()){
      int cx = q.front().first;
      int cy = q.front().second;
      q.pop();
      for(int i=0;i<4;i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(0 <= nx && nx < N && 0 <= ny && ny <= N){
          if(d[nx][ny] == -1){
            d[nx][ny] = d[cx][cy] + 1;
            q.push(make_pair(nx,ny));
          }
        }
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(a[i][j] == 1 && g[i][j] != gr){
          if(ans == -1 || ans > d[i][j] - 1){
            ans = d[i][j] - 1;
          }
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
