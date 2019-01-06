/**
 * 반복수열
 * 2331
 */
#include <cstdio>
#include <vector>
using namespace std;

int c[1000000];
int pow(int x,int y){
  int ans = 1;
  for(int i=0;i<y;i++){
    ans *= x;
  }
  return ans;
}
int next(int x,int p){
  int ans = 0;
  while(x != 0){
    ans += pow(x%10,p);
    x /= 10;
  }
  return ans;
}
void dfs(int x,int p,int cnt){
  if(c[x] == 0){
    c[x] = cnt;
    dfs(next(x,p),p,cnt+1);
  }
  else printf("%d\n",c[x]-1);
}
int main(){
  int A,P;
  scanf("%d %d",&A,&P);
  dfs(A,P,1);

  return 0;
}
