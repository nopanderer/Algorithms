/**
 * 오르막 수
 * 11057
 */
#include <cstdio>

long long dp[1001][10];
long long mod = 10007;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<=9;i++)
    dp[1][i] = 1;

  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=j;k++){
        dp[i][j] += dp[i-1][k];
      }
      dp[i][j] %= mod;
    }
  }
  long long sum = 0;
  for(int i=0;i<=9;i++)
    sum += dp[n][i];
  printf("%lld",sum%mod);

  return 0;
}
