/**
 * 1,2,3 더하기
 * 9095
 */
#include <cstdio>

int dp[12];
int main(){
  int t;
  scanf("%d",&t);
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  while(t--){
    int n;
    scanf("%d",&n);
    for(int i=4;i<=n;i++)
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    printf("%d\n",dp[n]);
  }
  return 0;
}
