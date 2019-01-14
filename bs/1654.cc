/**
 * 랜선 자르기
 * 1654
 */
#include <iostream>
#include <algorithm>
using namespace std;
int K,N;
int a[10001];
bool check(long long mid){
  long long sum=0;
  for(int i=0;i<K;i++){
    sum += a[i]/mid;
  }
  if(sum >= N) return true;
  else return false;
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>K>>N;
  for(int i=0;i<K;i++){
    cin>>a[i];
  }
  long left = 1;
  long long right = *max_element(a,a+K);
  while(left <= right){
    long long mid = left + (right-left)/2;
    if(check(mid)){
      left = mid+1;
    }
    else{
      right = mid-1;
    }
  }
  cout<<right<<'\n';

  return 0;
}
