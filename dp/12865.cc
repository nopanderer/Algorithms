/**
 * 평범한 배낭
 * 12865
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;
int n,k;
int d[101][100001];
int w[101];
int v[101];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i=1;i<=n;i++){
    cin >> w[i] >> v[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=k;j++){
      // current product can be put into the bag
      if(w[i] <= j){
        d[i][j] = max(d[i-1][j], v[i] + d[i-1][j-w[i]]);
      }
      // cannot be put into the bag, then previous max value
      else{
        d[i][j] = d[i-1][j];
      }
    }
  }

  cout << d[n][k] <<'\n';

  return 0;
}
