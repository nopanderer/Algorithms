/**
 * 대회 or 인턴
 * 2875
 */
#include <iostream>
using namespace std;
int team(int n, int m){
  int ans=0;
  if(n < 0 || m < 0){
    return 0;
  }
  while(n-2 >= 0 && m-1 >= 0){
    n -= 2;
    m -= 1;
    ans++;
  }
  return ans;
}
int main(){
  int N,M,K;
  cin>>N>>M>>K;
  int ans=0;
  for(int i=0;i<=K;i++){
    int tmp = team(N-i,M-K+i);
    if(ans < tmp){
      ans = tmp;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
