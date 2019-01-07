/**
 * 트리의 지름
 * 1167
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int> > a[100001];
int d[100001];
bool c[100001];
void dfs(int x){
  for(int i=0;i<a[x].size();i++){
    int next = a[x][i].first;
    if(c[next] == false){
      c[next] = true;
      d[next] = d[x] + a[x][i].second;
      dfs(next);
    }
  }
}
int main(){
  int V;
  scanf("%d",&V);
  for(int i=0;i<V;i++){
    int u,v,w;
    scanf("%d",&u);
    while(true){
      scanf("%d",&v);
      if(v == -1) break;
      scanf("%d",&w);
      a[u].push_back(make_pair(v,w));
      a[v].push_back(make_pair(u,w));
    }
  }
  c[1] = true;
  dfs(1);
  int ans=0;
  int max_node; 
  for(int i=1;i<=V;i++){
    if(d[i] > ans){
      max_node = i;
      ans = d[i];
    }
  }

  // clear
  fill(d,d+100001,0);
  fill(c,c+100001,false);

  c[max_node] = true;
  dfs(max_node);
  for(int i=1;i<=V;i++){
    ans = max(ans,d[i]);
  }
  printf("%d\n",ans);

  return 0;
}
