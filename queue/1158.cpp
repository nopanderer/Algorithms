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
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++){
    q.push(i);
  }
  printf("<");
  while(q.size() != 1){
    for(int i=0;i<m-1;i++){
      int f = q.front();
      q.pop();
      q.push(f);
    }
    printf("%d, ",q.front());
    q.pop();
  }
  printf("%d>\n",q.front());

  return 0;
}

