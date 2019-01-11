/**
 * NMK
 * 1201
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int N,M,K;
  vector<int> a;
  vector<int> s;
  cin>>N>>M>>K;
  if(M+K-1 <= N && N <= M*K){
    for(int i=1;i<=N;i++){
      a.push_back(i);
    }
    s.push_back(0);
    s.push_back(K);
    N -= K;
    M -= 1;
    int r = M==0 ? 0 : N%M;
    for(int i=0;i<M;i++){
      s.push_back(s.back() + N/M + (r>0 ? 1 : 0));
      if(r>0) r--;
    }
    for(int i=0;i<s.size()-1;i++){
      reverse(a.begin()+s[i],a.begin()+s[i+1]);
    }
    for(int i=0;i<a.size();i++){
      cout<<a[i]<<" ";
    }
  }
  else{
    cout<<"-1";
  }
  cout<<'\n';


  return 0;
}
