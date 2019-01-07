/**
 * 트리의 부모
 * 11725
 */
#include <cstdio>
#include <vector>
using namespace std;

vector<int> a[100001];
int p[100001];
void dfs(int x){
  for(int i=0;i<a[x].size();i++){
    int next = a[x][i];
    if(p[next] == 0){
      p[next] = x;
      dfs(next);
    }
  }
}
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  p[1] = 1;
  dfs(1);

  for(int i=2;i<=N;i++){
    printf("%d\n",p[i]);
  }
  return 0;
}
