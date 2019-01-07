/**
 * 토마토
 * 7576
 */
#include <cstdio>
#include <queue>
using namespace std;

int a[1001][1001];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int M,N;
int ans;
queue<pair<int,int> > q;
int main(){
  scanf("%d %d",&M,&N);
  bool flag = false;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%d",&a[i][j]);
      if(a[i][j] == 1){
        flag = true;
        q.push(make_pair(i,j));
      }
    }
  }
  if(!flag){
    printf("0\n");
    return 0;
  }
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

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(ans < a[i][j]){
        ans = a[i][j];
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(a[i][j] == 0){
        printf("-1\n");
        return 0;
      }
    }
  }
  printf("%d\n",ans-1);

  return 0;
}
