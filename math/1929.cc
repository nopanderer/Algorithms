/**
 * 소수 구하기
 * 1929
 */
#include <iostream>
using namespace std;

bool c[1000001];
int main(){
  int m,n;
  cin>>m>>n;
  c[0] = c[1] = true;
  for(int i=2;i*i<=n;i++){
    if(c[i] == false){
      for(int j=i*2;j<=n;j+=i){
        c[j] = true;
      }
    }
  }
  for(int i=m;i<=n;i++){
    if(c[i] == false) cout<<i<<'\n'; // endl is very slow!
  }

  return 0;
}
