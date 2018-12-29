/**
 * 쉬운 계단 수
 * 10844
 */
#include <cstdio>

long long dp[101][10];
int main(){
  int n;
  long long s=0;
  scanf("%d",&n);
  for(int i=1;i<=9;i++)
    dp[1][i] = 1;
  for(int i=2;i<=n;i++){
    for(int j=1;j<=8;j++){
      dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
      dp[i][j] %= 1000000000;
    }
    dp[i][0] = dp[i-1][1];
    dp[i][9] = dp[i-1][8];
  }
  for(int i=1;i<=9;i++)
    s+=dp[n][i];
  printf("%lld",s%1000000000);

  return 0;
}
