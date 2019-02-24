/**
 * 영역 구하기
 * 2583
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
int n,m,k;
int a[101][101];
bool c[101][101];
vector<int> ans;
int area;
int cnt;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void dfs(int x, int y){
  c[x][y] = true;
  area++;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0 <= nx && nx < m && 0 <= ny && ny < n){
      if(a[nx][ny] == 0 && c[nx][ny] == false){
        dfs(nx, ny);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n >> k;
  for(int i=0;i<k;i++){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cx1 = m-1-y1;
    int cy1 = x1;
    int cx2 = m-1-y2+1;
    int cy2 = x2-1;

    for(int X=cx2;X<=cx1;X++){
      for(int Y=cy1;Y<=cy2;Y++){
        a[X][Y] = 1;
      }
    }
  }

  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(a[i][j] == 0 && c[i][j] == false){
        area = 0;
        dfs(i,j);
        cnt++;
        ans.push_back(area);
      }
    }
  }

  cout << cnt << '\n';
  sort(ans.begin(), ans.end());
  for(auto &p : ans){
    cout << p << ' ';
  }
  cout << '\n';

  return 0;
}
