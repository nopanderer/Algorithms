/**
 * 오아시스 재결함
 * 3015
 */
#include <iostream>
#include <stack>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N;
  int a[500001];
  stack<pair<int,int>> s;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  long long ans = 0;
  for(int i=0;i<N;i++){
    pair<int,int> p = {a[i], 1};
    while(!s.empty()){
      if(s.top().first <= a[i]){
        ans += (long long)s.top().second;
        if(s.top().first == a[i]){
          p.second += s.top().second;
        }
        s.pop();
      }
      else{
        break;
      }
    }
    if(!s.empty()) ans += 1LL;
    s.push(p);
  }
  cout<<ans<<'\n';

  return 0;
}
