/**
 * 순열 사이클
 * 10451
 */
#include <cstdio>
#include <vector>
using namespace std;

vector<int> a[1001];
bool c[1001];
int cnt;
void dfs(int x){
  c[x] = true;
  for(int i=0;i<a[x].size();i++){
    int next = a[x][i];
    if(c[next] == false){
      dfs(next);
    }
    else{
      cnt++;
    }
  }
}
int main(){
  int T,N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    // clear
    cnt = 0;
    for(int i=1;i<=N;i++){
      a[i].clear();
      c[i] = false;
    }
    // adj list
    for(int i=1;i<=N;i++){
      int node;
      scanf("%d",&node);
      a[i].push_back(node);
    }
    // dfs
    for(int i=1;i<=N;i++){
      if(c[i] == false){
        dfs(i);
      }
    }
    // print # cycles
    printf("%d\n",cnt);
  }
  return 0;
}
