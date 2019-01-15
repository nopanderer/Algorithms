/**
 * 중랑제한
 * 1939
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M,A,B,C,S,E;
long long l=1,r,mid,ans;
vector<pair<int,int>> a[10001];
bool c[10001];
bool bfs(int w){
  queue<int> q;
  fill(c,c+10001,false);
  c[S] = true;
  q.push(S);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    for(int i=0;i<a[x].size();i++){
      int next = a[x][i].first;
      int weight = a[x][i].second;
      if(c[next] == false && weight >= w){
        c[next] = true;
        q.push(next);
      }
    }
  }
  return c[E];
}
int main(){
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>A>>B>>C;
    a[A].push_back(make_pair(B,C));
    a[B].push_back(make_pair(A,C));
    if(r < C){
      r = C;
    }
  }
  cin>>S>>E;

  while(l <= r){
    mid = l + (r-l)/2;
    if(bfs(mid)){
      ans = mid;
      l = mid+1;
    }
    else{
      r = mid-1;
    }
  }
  cout<<ans<<'\n';

  return 0;
}
