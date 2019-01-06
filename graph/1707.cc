/**
 * 이분 그래프
 * 1707
 */
#include <cstdio>
#include <vector>
using namespace std;

vector<int> a[20001];
int c[20001];
void dfs(int x,int clr){
  c[x] = clr;
  for(int i=0;i<a[x].size();i++){
    int next = a[x][i];
    if(c[next] == 0){
      dfs(next,clr*(-1));
    }
  }
}
int main(){
  int T,V,E;
  scanf("%d",&T);
  while(T--){
    for(int i=0;i<20001;i++){
      a[i].clear();
    }
    fill(c,c+20001,0);
    scanf("%d %d",&V,&E);
    for(int i=0;i<E;i++){
      int u,v;
      scanf("%d %d",&u,&v);
      a[u].push_back(v);
      a[v].push_back(u);
    }
    for(int i=1;i<=V;i++){
      if(c[i] == 0){
        dfs(i,1);
      }
    }

    bool flag = true;
    for(int i=1;i<=V && flag;i++){
      for(int j=0;j<a[i].size();j++){
        int node = a[i][j];
        if(c[i] == c[node]){
          flag = false;
          break;
        }
      }
    }
    printf("%s\n",flag ? "YES" : "NO");
  }
  return 0;
}
