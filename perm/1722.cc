/**
 * 순열의 순서
 * 1722
 */
#include <iostream>
using namespace std;
int N,P;
long long K;
int a[21];
bool c[21];
long long f[21];
void go1(){
  for(int i=0;i<N;i++){
    for(int j=1;j<=N;j++){
      if(c[j] == true) continue;
      if(K > f[N-1-i]){
        K -= f[N-1-i];
      }
      else{
        a[i] = j;
        c[j] = true;
        break;
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<a[i]<<' ';
  }
  cout<<'\n';
}
void go2(){
  long long ans = 0;
  for(int i=0;i<N;i++){
    for(int j=1;j<a[i];j++){
      if(c[j] == false){
        ans += f[N-i-1];
      }
    }
    c[a[i]] = true;
  }
  cout<<ans+1<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>P;
  f[0] = 1;
  f[1] = 1;
  for(int i=2;i<=N;i++){
    f[i] = f[i-1]*i;
  }
  if(P==1){
    cin>>K;
    go1();
  }
  else{
    for(int i=0;i<N;i++){
      cin>>a[i];
    }
    go2();
  }

  return 0;
}
