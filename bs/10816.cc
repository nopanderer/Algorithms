/**
 * 숫자 카드 2
 * 10816
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
vector<int> a;
int ans;
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(int i=0;i<N;i++){
    int num;
    cin>>num;
    a.push_back(num);
  }
  sort(a.begin(),a.end());
  cin>>M;
  for(int i=0;i<M;i++){
    int num;
    cin>>num;
    auto u = upper_bound(a.begin(),a.end(),num);
    auto l = lower_bound(a.begin(),a.end(),num);
    cout<<u-l<<" ";
  }
  cout<<"\n";

  return 0;
}
