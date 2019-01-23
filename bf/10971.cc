/**
 * 외판원 순회 2
 * 10971
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
  int N;
  int w[11][11];
  vector<int> a;
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>w[i][j];
    }
  }
  for(int i=0;i<N;i++){
    a.push_back(i);
  }
  int ans=987654321;
  do{
    int cost=0;
    bool flag=false;
    for(int i=0;i<N-1;i++){
      if(w[a[i]][a[i+1]] == 0){
        flag = true;
        break;
      }
      cost += w[a[i]][a[i+1]];
    }
    if(!flag && w[a[N-1]][a[0]]){
      cost += w[a[N-1]][a[0]];
      if(cost < ans){
        ans = cost;
      }
    }
  }while(next_permutation(a.begin(),a.end()));

  cout<<ans<<'\n';

  return 0;
}
