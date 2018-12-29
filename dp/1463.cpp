/**
 * 1로 만들기
 * 1463
 */
#include <cstdio>
#include <algorithm>
const int MAX = 1000001;

using namespace std;

int dp[MAX];
int main(){
  int n;
  scanf("%d",&n);
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  for(int i=4;i<=n;i++){
    int tmp = dp[i-1];
    if(i%3 == 0){
      tmp = min(dp[i/3], tmp);
    }
    else if(i%2 == 0){
      tmp = min(dp[i/2], tmp);
    }
    dp[i] = tmp + 1;
  }
  printf("%d",dp[n]);
  
  return 0;
}
