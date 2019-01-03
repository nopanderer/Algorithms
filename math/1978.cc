/**
 * 소수 찾기
 * 1978
 */
#include <iostream>
using namespace std;

int a[101];
bool prime(int n){
  if(n<2)
    return false;
  for(int j=2;j*j<=n;j++){
    if(n%j == 0)
      return false;
  }
  return true;
}
int main(){
  int N;
  int cnt=0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
    if(prime(a[i])) cnt++;
  }
  cout<<cnt<<endl;

  return 0;
}

