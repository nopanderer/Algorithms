/**
 * 합분해
 * 2225
 */
#include <iostream>

using namespace std;

long long mod = 1000000000;
long long d[201][201];
int main(){
  int N,K;
  cin>>N>>K;
  d[0][0] = 1LL;
  for(int n=0;n<=N;n++){
    for(int k=1;k<=K;k++){
      for(int l=0;l<=n;l++){
        d[n][k] += d[n-l][k-1];
        d[n][k] %= mod;
      }
    }
  }
  cout<<d[N][K]<<endl;

  return 0;
}
