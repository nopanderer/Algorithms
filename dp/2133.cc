/**
 * 타일 채우기
 * 2133
 */
#include <cstdio>

long long d[31];
int main(){
  int n;
  scanf("%d",&n);

  d[0] = 1;
  for(int i=2;i<=n;i+=2){
    d[i] = d[i-2] * 3;
    for(int j=4;i-j>=0;j+=2){
      d[i] += d[i-j] * 2;
    }
  }

  printf("%lld",d[n]);

  return 0;
}
