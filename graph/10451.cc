/**
 * 순열 사이클
 * 10451
 */
#include <cstdio>
#include <vector>
using namespace std;

int a[1001];
bool c[1001];
int cnt;
void dfs(int x){
  c[x] = true;
  if(c[a[x]] == false)
    dfs(a[x]);
  else
    return;
}
int main(){
  int T,N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    // clear
    cnt = 0;
    for(int i=1;i<=N;i++){
      a[i] = 0;
      c[i] = false;
    }
    // adj list
    for(int i=1;i<=N;i++){
      scanf("%d",&a[i]);
    }
    // dfs
    for(int i=1;i<=N;i++){
      if(c[i] == false){
        dfs(i);
        cnt++;
      }
    }
    // print # cycles
    printf("%d\n",cnt);
  }
  return 0;
}
