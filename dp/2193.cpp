/**
 * 이친수
 * 2193
 * NOTE: int로 하면 오버플로우
 */
#include <cstdio>

long long dp[91];
int main(){
  int n;
  scanf("%d",&n);
  dp[1] = 1;
  dp[2] = 1;
  for(int i=3;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  printf("%lld",dp[n]);
  return 0;
}
