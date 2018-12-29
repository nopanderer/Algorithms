/**
 * 포도주 시식
 * 2156
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int dp[10001][2];
int a[10001];
int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
  dp[1][1] = a[1];

  for(int i=2;i<=n;i++){
    dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
    dp[i][1] = max(dp[i-1][0], dp[i-2][0] + a[i-1]) + a[i];
  }

  printf("%d",max(dp[n][0], dp[n][1]));

  return 0;
}
