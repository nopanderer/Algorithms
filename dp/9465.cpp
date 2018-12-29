/**
 * 스티커
 * 9465
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int dp[2][MAX];
int a[2][MAX];

int main(){
  int T,N;
  scanf("%d",&T);
  while(T--){
    scanf("%d",&N);
    for(int i=0;i<2;i++)
      for(int j=0;j<N;j++)
        scanf("%d",&a[i][j]);

    for(int i=0;i<2;i++)
      for(int j=0;j<N;j++)
        dp[i][j] = -1;

    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0];
    dp[0][1] = a[1][0]+a[0][1];
    dp[1][1] = a[0][0]+a[1][1];
    for(int i=2;i<N;i++){
      dp[0][i] = max(max(dp[0][i-2],dp[1][i-2]), dp[1][i-1]) + a[0][i];
      dp[1][i] = max(max(dp[1][i-2],dp[0][i-2]), dp[0][i-1]) + a[1][i];
    }
    printf("%d\n",max(dp[0][N-1],dp[1][N-1]));
  }

  return 0;
}
