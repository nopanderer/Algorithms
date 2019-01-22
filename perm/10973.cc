/**
 * 이전 순열
 * 10973
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> a;
void swap(int* a,int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
bool prev_permutation(int n){
  int i=n-1,j=n-1;
  while(i > 0 && a[i-1] < a[i]){
    i--;
  }
  if(i==0) return false;
  while(j >= i && a[i-1] < a[j]){
    j--;
  }
  swap(&a[i-1],&a[j]);
  reverse(a.begin()+i,a.end());
  return true;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>n;
  for(int i=0;i<n;i++){
    int tmp;
    cin>>tmp;
    a.push_back(tmp);
  }
  if(prev_permutation(n)){
    for(int i=0;i<n;i++){
      cout<<a[i]<<' ';
    }
  }
  else{
    cout<<"-1";
  }
  cout<<'\n';

  return 0;
}
