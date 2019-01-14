/**
 * 공유기 설치
 * 2110
 */
#include <iostream>
#include <algorithm>
using namespace std;
int N,C;
int a[200001];
bool check(int d){
  int cnt=1;
  int prev=a[0];
  for(int i=1;i<N;i++){
    if(a[i]-prev >= d){
      prev = a[i];
      cnt++;
    }
  }
  return cnt >= C;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>C;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(a,a+N);
  long long left = 1;
  long long right = a[N-1];
  long long ans = 0;
  while(left <= right){
    long long mid = (left+right)/2;
    if(check(mid)){
      if(ans < mid){
        ans = mid;
      }
      left = mid+1;
    }
    else{
      right = mid-1;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
