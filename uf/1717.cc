/**
 * 집합의 표현
 * 1717
 */
#include <iostream>
using namespace std;
int parent[1000001];
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
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  for(int i=0;i<=n;i++){
    parent[i] = i;
  }
  for(int i=0;i<m;i++){
    int M,x,y;
    cin>>M>>x>>y;
    if(M==0){
      Union(x,y);
    }
    else{
      if(Find(x) == Find(y)){
        cout<<"yes\n";
      }
      else{
        cout<<"no\n";
      }
    }
  }
  return 0;
}
