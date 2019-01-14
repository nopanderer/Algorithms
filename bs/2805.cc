/**
 * 나무 자르기
 * 2805
 */
#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int a[1000001];
bool check(int mid){
  long long sum = 0;
  for(int i=0;i<N;i++){
    if(a[i]-mid > 0){
      sum += (a[i]-mid);
    }
  }
  return sum >= M;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  long long left = 1;
  long long right = *max_element(a,a+N);
  long long ans = 0;
  while(left <= right){
    long long mid = (left+right)/2;
    if(check(mid)){
      if(ans < mid){
        ans = mid;
      }
      left = mid + 1;
    }
    else{
      right = mid - 1;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
