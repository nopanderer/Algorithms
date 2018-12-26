/**
 * 1로 만들기
 * 1463
 */
#include <cstdio>
#include <algorithm>
const int MAX = 1000001;

int dp[1000001];
int f(int n){
  if(n == 1) return 0; // base case
  if(dp[n] != -1) return dp[n]; // memoization

  int result = f(n-1) + 1;
  if(n%3 == 0) result = std::min(result, f(n/3) + 1);
  if(n%2 == 0) result = std::min(result, f(n/2) + 1);
  dp[n] = result;
  return result;
}
int main(){
  int N;
  scanf("%d",&N);
  std::fill(dp, dp+MAX, -1);
  printf("%d",f(N));
  
  return 0;
}
