/**
 * 나이트의 이동
 * 7562
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
int t,n;
int s1,s2;
int e1,e2;
int a[301][301];
int c[301][301];
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int dy[] = {-1,1,-2,2,-2,2,-1,1};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    memset(c, -1, sizeof(c));
    cin >> n;
    cin >> s1 >> s2;
    cin >> e1 >> e2;

    queue<pair<int,int>> q;
    c[s1][s2] = 0;
    q.push({s1,s2});
    while(!q.empty()){
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
          if(c[nx][ny] == -1){
            c[nx][ny] = c[x][y] + 1;
            q.push({nx,ny});
          }
        }
      }
    }
    cout << c[e1][e2] << '\n';
  }

  return 0;
}
