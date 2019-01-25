/**
 * 부분집합의 합 - 비트마스크
 * 1182
 */
#include <iostream>
using namespace std;
int main(){
  int N,S;
  int a[21];
  int ans=0;
  cin>>N>>S;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=1;i<(1<<N);i++){
    int sum=0;
    for(int j=0;j<N;j++){
      if(i&(1<<j)){
        sum+=a[j];
      }
    }
    if(sum == S){
      ans++;
    }
  }
  cout<<ans<<'\n';
  return 0;
}
