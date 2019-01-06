/**
 * 텀 프로젝트
 * 9466
 */
#include <cstdio>

int g[100001];
int v[100001];
int a[100001];
int cnt;

void dfs(int x,int group,int visit){
  v[x] = visit;
  g[x] = group;
  if(v[a[x]] != 0 && g[a[x]] == g[x])
    cnt += v[x] - v[a[x]] + 1;
  else if(v[a[x]] == 0)
    dfs(a[x],group,visit+1);
}
int main(){
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d",&n);
    // clear
    cnt = 0;
    int group = 1;
    int visit = 1;
    for(int i=1;i<=n;i++){
      g[i] = 0;
      v[i] = 0;
    }
    // build graph
    for(int i=1;i<=n;i++){
      int s;
      scanf("%d",&s);
      a[i] = s;
    }
    for(int i=1;i<=n;i++){
      if(i == a[i]){
        g[i] = group++;
        v[i] = visit++;
        cnt++;
      }
    }
    for(int i=1;i<=n;i++){
      if(v[i] == 0)
        dfs(i,group++,visit);
    }
    printf("%d\n",n-cnt);
  }

  return 0;
}
