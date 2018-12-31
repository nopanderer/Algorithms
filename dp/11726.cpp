/**
 * 2Xn 타일링
 * 11726
 * NOTE: 중간에 10007로 나눠주지 않으면 오버플로우 발생
 */
#include <cstdio>

int dp[1001];
int main(){
  int n;
  scanf("%d",&n);
  dp[1] = 1;
  dp[2] = 2;

  for(int i=3;i<=n;i++){
    dp[i] = dp[i-2] + dp[i-1];
    dp[i] %= 10007;
  }
  printf("%d",dp[n]);
  
  return 0;
}
