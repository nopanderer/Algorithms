/**
 * 바이러스
 * 2606
 */
#include <iostream>
using namespace std;
int parent[101];
int Find(int x){
  if(x == parent[x]){
    return x;
  }
  else{
    return parent[x] = Find(parent[x]);
  }
}
void Union(int x, int y){
  x = Find(x);
  y = Find(y);
  parent[y] = x;
}
int main(){
  int n,p,x,y;
  int ans=0;
  cin>>n>>p;
  for(int i=0;i<=n;i++){
    parent[i] = i;
  }
  while(p--){
    cin>>x>>y;
    Union(x,y);
  }
  for(int i=2;i<=n;i++){
    if(Find(1) == Find(i))
      ans++;
  }
  cout<<ans<<'\n';

  return 0;
}

