/**
 * 카드 구매하기
 * 11052
 */
#include <cstdio>

int p[1001];
int dp[1001];
int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
    scanf("%d",&p[i]);
  for(int i=1;i<=n;i++){
    dp[i] = p[i];
    for(int j=1;j<=i;j++){
      int tmp = p[j] + dp[i-j];
      if(tmp>dp[i]) dp[i] = tmp;
    }
  }

  printf("%d",dp[n]);
  
  return 0;
}
  
