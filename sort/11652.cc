/**
 * 카드
 * 11652
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<long long> a(N);
  for(int i=0;i<N;i++)
    cin>>a[i];
  sort(a.begin(),a.end());

  long long ans=a[0];
  int ans_cnt=1;
  int cnt=0;
  for(int i=1;i<N;i++){
    if(a[i-1]!=a[i]){
      cnt=0;
    }
    else{
      cnt++;
    }
    if(ans_cnt<cnt){
      ans_cnt = cnt;
      ans = a[i];
    }
  }
  cout<<ans<<endl;

  return 0;
}
