/**
 * 버블 소트
 * 1517
 */
#include <iostream>
using namespace std;
int a[500001];
int b[500001];
int N;
long long cnt;
void merge(int s,int e){
  int mid = (s+e)/2;
  int i = s;
  int j = mid+1;
  int k = 0;
  while(i<=mid && j<=e){
    if(a[i] <= a[j]){
      b[k++] = a[i++];
    }
    // swap
    else{
      cnt += (mid-i+1);
      b[k++] = a[j++];
    }
  }
  while(i<=mid){
    b[k++] = a[i++];
  }
  while(j<=e){
    b[k++] = a[j++];
  }
  for(i=s;i<=e;i++){
    a[i] = b[i-s];
  }
}
void sort(int s,int e){
  if(s==e){
    return;
  }
  int mid = (s+e)/2;
  sort(s,mid);
  sort(mid+1,e);
  merge(s,e);
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  sort(0,N-1);
  cout<<cnt<<'\n';

  return 0;
}
