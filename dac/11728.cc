/**
 * 배열 합치기
 * 11728
 */
#include <iostream>
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  for(int i=0;i<M;i++){
    cin>>b[i];
  }
  int ia = 0;
  int ib = 0;
  int ic = 0;
  while(ia < N && ib < M){
    if(a[ia] < b[ib]){
      c[ic++] = a[ia++];
    }
    else{
      c[ic++] = b[ib++];
    }
  }
  while(ia < N) c[ic++] = a[ia++];
  while(ib < M) c[ic++] = b[ib++];
  for(int i=0;i<N+M;i++){
    cout<<c[i]<<" ";
  }
  cout<<'\n';


  return 0;
}
