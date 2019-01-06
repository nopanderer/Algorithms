/**
 * 연결 요소의 개수
 * 11724
 */
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> a[1001];
bool c[1001];
void bfs(int x){
  queue<int> q;
  c[x] = true;
  q.push(x);
  while(!q.empty()){
    int y = q.front();
    q.pop();
    for(int i=0;i<a[y].size();i++){
      int next = a[y][i];
      if(c[next] == false){
        c[next] = true;
        q.push(next);
      }
    }
  }
}
int main(){
  int N,M;
  int cnt=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int u,v;
    scanf("%d %d",&u,&v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for(int i=1;i<=N;i++){
    if(c[i] == false){
      bfs(i);
      cnt++;
    }
  }
  printf("%d\n",cnt);

  return 0;
}
