/**
 * 회의실배정
 * 1931
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> p1, pair<int,int> p2){
  if(p1.second == p2.second){
    return p1.first < p2.first;
  }
  else{
    return p1.second < p2.second;
  }
}
int main(){
  int N;
  vector<pair<int,int> > a;
  cin>>N;
  for(int i=0;i<N;i++){
    int s,e;
    cin>>s>>e;
    a.push_back(make_pair(s,e));
  }
  sort(a.begin(),a.end(),cmp);

  int ans=1;
  int end=a[0].second;
  for(int i=1;i<a.size();i++){
    if(a[i].first >= end){
      ans++;
      end = a[i].second;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
