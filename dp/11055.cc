/**
 * 가장 큰 증가하는 부분 수열
 * 11055
 */
#include <cstdio>
#define max(a,b) (((a)>(b))?(a):(b))

int dp[1001];
int a[1001];
int main(){
  int n;
  scanf("%d",&n);

  for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);

  for(int i=1;i<=n;i++){
    dp[i] = a[i];
    for(int j=1;j<i;j++)
      if(a[j]<a[i])
        dp[i] = max(dp[i], dp[j] + a[i]);
  }

  int ans = dp[1];
  for(int i=2;i<=n;i++)
    ans = max(dp[i],ans);

  printf("%d",ans);
  return 0;
}
