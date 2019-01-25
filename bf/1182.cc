/**
 * 부분집합의 합
 * 1182
 */
#include <iostream>
#include <vector>
using namespace std;
int N,S;
int a[21];
int ans;
void solve(int idx, vector<int> &s){
  if(idx == N){
    int sum = 0;
    for(int num : s){
      sum += num;
    }
    if(sum == S) ans++;
    return;
  }
  s.push_back(a[idx]);
  solve(idx+1,s);
  s.pop_back();
  solve(idx+1,s);
}
int main(){
  cin>>N>>S;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  vector<int> s;
  solve(0,s);
  if(S==0) ans--;
  cout<<ans<<'\n';
  return 0;
}
