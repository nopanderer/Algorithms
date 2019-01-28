/**
 * 듣보잡
 * 1764
 */
#include <iostream>
#include <set>
using namespace std;
int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n,m;
  string name;
  set<string> s;
  set<string> v;
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>name;
    s.insert(name);
  }
  for(int i=0;i<m;i++){
    cin>>name;
    if(s.find(name) != s.end()){
      v.insert(name);
    }
  }
  cout<<v.size()<<'\n';
  for(auto it = v.begin();it != v.end();it++){
    cout<<*it<<'\n';
  }
  return 0;
}
