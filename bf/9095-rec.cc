/**
 * 1,2,3 더하기 - 재귀호출
 * 9095
 */
#include <iostream>
using namespace std;
int T,n,ans;
int go(int count, int sum,int goal){
  if(sum > goal) return 0;
  if(sum == goal) return 1;
  int now = 0;
  for(int i=1;i<=3;i++){
    now += go(count+1,sum+i,goal);
  }
  return now;
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>T;
  while(T--){
    ans = 0;
    cin>>n;
    cout<<go(0,0,n)<<'\n';
  }
  return 0;
}
