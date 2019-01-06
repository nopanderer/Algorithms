/**
 * 단지번호붙이기
 * 2667
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int a[26][26];
bool c[26][26];
vector<int> ans;
int bfs(int x, int y){
  int cnt=0;
  queue<pair<int,int> > q;
  c[x][y] = true;
  q.push(make_pair(x,y));
  while(!q.empty()){
    pair<int,int> node = q.front();
    q.pop();
    cnt++;
    for(int i=0;i<4;i++){
      int nx = node.first + dx[i];
      int ny = node.second + dy[i];
      if(nx > 26 || nx < 0 || ny > 26 || ny < 0){
        continue;
      }
      if(a[nx][ny] && c[nx][ny] == false){
        c[nx][ny] = true;
        q.push(make_pair(nx,ny));
      }
    }
  }
  return cnt;
}
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    char tmp[26];
    scanf("%s",tmp);
    for(int j=0;j<N;j++){
      a[i][j] = tmp[j]-'0';
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a[i][j] && c[i][j] == false){
        ans.push_back(bfs(i,j));
      }
    }
  }
  sort(ans.begin(),ans.end());
  printf("%d\n",ans.size());
  for(int i=0;i<ans.size();i++){
    printf("%d\n",ans[i]);
  }

  return 0;
}
