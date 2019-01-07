/**
 * 미로 탐색
 * 2178
 */
#include <cstdio>
#include <queue>
using namespace std;

int a[101][101];
int c[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int N,M;
void bfs(int x, int y){
  queue<pair<int,int> > q;
  c[x][y] = 1;
  q.push(make_pair(x,y));
  while(!q.empty()){
    pair<int,int> node = q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx = node.first + dx[i];
      int ny = node.second + dy[i];
      if(nx < 0 || nx > N || ny < 0 || ny > M){
        continue;
      }
      if(a[nx][ny] && c[nx][ny] == 0){
        c[nx][ny] = c[node.first][node.second] + 1;
        q.push(make_pair(nx,ny));
      }
    }
  }
}
int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    char s[101];
    scanf("%s",s);
    for(int j=0;j<M;j++){
      a[i][j] = s[j]-'0';
    }
  }
  bfs(0,0);
  printf("%d\n",c[N-1][M-1]);

  return 0;
}
