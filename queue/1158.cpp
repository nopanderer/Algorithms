/**
 * 조세퍼스 문제
 * 1158
 */
#include <cstdio>
#include <queue>

using namespace std;

int main(){
  int n,m;
  queue<int> q;
  queue<int> r;
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)
    q.push(i);
  for(int i=0;i<n;i++){
    for(int j=0;j<m-1;j++){
      int tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    r.push(q.front());
    q.pop();
  }
  
  printf("<%d",r.front());
  r.pop();
  for(int i=0;i<n-1;i++){
    printf(", %d",r.front());
    r.pop();
  }
  printf(">");


  return 0;
}
