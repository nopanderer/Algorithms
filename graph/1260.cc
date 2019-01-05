/**
 * DFS와 BFS
 * 1260
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool c[1001];
vector<vector<int> > a(1001);
queue<int> q;

void dfs(int v){
  c[v] = true;
  printf("%d ",v);
  for(int i=0;i<a[v].size();i++){
    int next = a[v][i];
    if(c[next] == false){
      dfs(next);
    }
  }
}
void bfs(int v){
  c[v] = true;
  q.push(v);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    printf("%d ",x);
    for(int i=0;i<a[x].size();i++){
      int next = a[x][i];
      if(c[next] == false){
        c[next] = true;
        q.push(next);
      }
    }
  }
}
int main(){
  int N,M,V;

  scanf("%d %d %d",&N,&M,&V);

  for(int i=0;i<M;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i=1;i<=N;i++){
    sort(a[i].begin(),a[i].end());
  }
  fill(c,c+1001,false);
  dfs(V);
  printf("\n");
  fill(c,c+1001,false);
  bfs(V);

  return 0;
}
