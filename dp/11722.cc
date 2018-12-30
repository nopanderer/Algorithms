/**
 * 가장 긴 감소하는 부분 수열
 * 11722
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int a[1001];
int dp[1001];
int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&a[i]);
  }
  for(int i=1;i<=n;i++){
    dp[i] = 1;
    for(int j=1;j<i;j++){
      if(a[i]<a[j])
        dp[i] = max(dp[i],dp[j] + 1);
    }
  }
  int ans = dp[1];
  for(int i=2;i<=n;i++)
    ans = max(ans,dp[i]);
  
  printf("%d",ans);

  return 0;
}

