/**
 * 쉬운 계단 수
 * 10844
 */
#include <cstdio>

long long dp[101][10];
long long mod = 1000000000;
int main(){
  int n;
  long long s=0;
  scanf("%d",&n);
  for(int i=1;i<=9;i++)
    dp[1][i] = 1;
  for(int i=2;i<=n;i++){
    for(int j=0;j<=9;j++){
      if(j==0) dp[i][j] = dp[i-1][1];
      else if(j==9) dp[i][j] = dp[i-1][8];
      else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
      dp[i][j] %= mod;
    }
  }
  for(int i=0;i<=9;i++)
    s+=dp[n][i];
  printf("%lld",s % mod);

  return 0;
}
