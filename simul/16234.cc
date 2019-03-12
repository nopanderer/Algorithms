/**
 * 인구 이동
 * 16234
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int N,L,R;
int a[51][51];
int g[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool flag;
int ans;
int sum;
int cnt;
vector<pair<int,int>> v;
void dfs(int x, int y, int group){
  v.push_back({x,y});
  cnt++;
  sum += a[x][y];
  g[x][y] = group;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < N && 0 <= ny && ny < N){
      int dif = abs(a[x][y] - a[nx][ny]);
      if(L <= dif && dif <= R && g[nx][ny] == 0){
        flag = true;
        dfs(nx,ny,group);
      }
    }
  }
}
int main(){
  cin >> N >> L >> R;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
    }
  }

  while(true){
    int group = 1;
    flag = false;
    memset(g, 0, sizeof(g));
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(g[i][j] == 0){
          sum = 0;
          cnt = 0;
          v.clear();
          dfs(i,j,group++);
          
          if(cnt > 1){
            for(auto &p : v){
              a[p.first][p.second] = sum/cnt;
            }
          }
        }
      }
    }

    if(!flag){
      break;
    }
    ans++;
  }

  cout << ans << '\n';


  return 0;
}
