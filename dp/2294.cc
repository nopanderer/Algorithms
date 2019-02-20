/**
 * 동전 2
 * 2294
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
using namespace std;
int n,k;
int a[101];
int d[10001];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  
  for(int i=1;i<=k;i++){
    d[i] = 99999;
    for(int j=0;j<n;j++){
      if(i == a[j]){
        d[i] = 1;
        break;
      }
      else if(i-a[j] > 0){
        if(d[i-a[j]] > 0){
          d[i] = min(d[i], 1 + d[i-a[j]]);
        }
      }
    }
    if(d[i] == 99999){
      d[i] = 0;
    }
  }
  if(d[k])
    cout << d[k] << '\n';
  else
    cout << "-1\n";

  return 0;
}
