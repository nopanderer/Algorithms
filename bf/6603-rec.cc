/**
 * 로또 - 재귀
 * 6603
 */
#include <iostream>
#include <vector>
using namespace std;
void go(int idx, int cnt, vector<int> &a, vector<int> &l){
  if(cnt == 6){
    for(int a : l){
      cout<<a<<' ';
    }
    cout<<'\n';
    return;
  }
  if(a.size() == idx) return;
  l.push_back(a[idx]);
  go(idx+1,cnt+1,a,l);
  l.pop_back();
  go(idx+1,cnt,a,l);
}
int main(){
  int T;
  while(true){
    vector<int> a;
    vector<int> l;
    cin>>T;
    if(T==0) break;
    for(int i=0;i<T;i++){
      int tmp;
      cin>>tmp;
      a.push_back(tmp);
    }
    go(0,0,a,l);
    cout<<'\n';
  }
  return 0;
}
