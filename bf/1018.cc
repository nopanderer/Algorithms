/**
 * 체스판 다시 칠하기
 * 1018
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
int a[51][51];
int cal(int x, int y){
  // 0,0 is W
  int wb = 0;
  int bw = 0;
  for(int i=x;i<x+8;i++){
    for(int j=y;j<y+8;j++){
      if((i+j)%2 == 0){
        // Black
        if(a[i][j] == 1){
          wb++;
        }
        // White
        else{
          bw++;
        }
      }
      else{
        if(a[i][j] == 1){
          bw++;
        }
        else{
          wb++;
        }
      }
    }
  }

  return (bw > wb) ? wb : bw;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++){
    string tmp;
    cin >> tmp;
    for(int j=0;j<m;j++){
      if(tmp[j] == 'B'){
        a[i][j] = 1;
      }
    }
  }
  int ans = 2147483647;
  for(int i=0;i<=n-8;i++){
    for(int j=0;j<=m-8;j++){
      ans = min(ans, cal(i,j));
    }
  }

  cout << ans << '\n';

  return 0;
}
// (50-8+1)*(50-8+1)*8*8 ~~ 100K
