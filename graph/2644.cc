/**
 * 촌수계산
 * 2644
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
int n,m;
int x,y;
vector<int> a[101];
int c[101];
void bfs(int x){
  queue<int> q;
  c[x] = 0;
  q.push(x);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(int i=0;i<a[now].size();i++){
      int next = a[now][i];
      if(c[next] == -1){
        c[next] = c[now] + 1;
        q.push(next);
      }
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  cin >> x >> y;
  cin >> m;
  for(int i=0;i<m;i++){
    int t1, t2;
    cin >> t1 >> t2;
    a[t1].push_back(t2);
    a[t2].push_back(t1);
  }
  memset(c, -1, sizeof(c));

  bfs(x);

  cout << c[y] << '\n';

  return 0;
}
