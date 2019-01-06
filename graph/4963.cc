/**
 * 섬의 개수
 * 4963
 */
#include <cstdio>
#include <queue>
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int a[51][51];
bool c[51][51];
int w,h,cnt;
void bfs(int x,int y){
  queue<pair<int,int> > q;
  c[x][y] = true;
  q.push(make_pair(x,y));
  while(!q.empty()){
    pair<int,int> node = q.front();
    q.pop();
    for(int i=0;i<8;i++){
      int nx = node.first + dx[i];
      int ny = node.second + dy[i];
      if(nx < 0 || nx > h || ny < 0 || ny > w){
        continue;
      }
      if(a[nx][ny] && c[nx][ny] == false){
        c[nx][ny] = true;
        q.push(make_pair(nx,ny));
      }
    }
  }
}
int main(){
  while(true){
    scanf("%d %d",&w,&h);
    if(w==0 && h==0) break;
    // clear
    cnt = 0;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        a[i][j] = 0;
        c[i][j] = false;
      }
    }
    // build graph
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        scanf("%d",&a[i][j]);
      }
    }
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        if(a[i][j] && c[i][j] == false){
          bfs(i,j);
          cnt++;
        }
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
