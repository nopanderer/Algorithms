/**
 * 동전 0
 * 11047
 */
#include <iostream>
using namespace std;

int main(){
  int N,K;
  int a[11];
  int ans=0;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=N-1;i>=0;i--){
    if(K/a[i] != 0){
      ans += K/a[i];
      K %= a[i];
    }
  }
  cout<<ans<<'\n';

  return 0;
}
  
