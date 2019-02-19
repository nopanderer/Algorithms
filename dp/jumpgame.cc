/**
 * 외발 뛰기
 * jumpgame
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
int a[101][101];
int d[101][101];
int t,n;
int solve(int x, int y){
  if(x >= n || y >= n){
    return 0;
  }
  if(x == n-1 && y == n-1){
    return 1;
  }
  if(d[x][y] != -1){
    return d[x][y];
  }
  return d[x][y] = solve(x+a[x][y], y) | solve(x, y+a[x][y]);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while(t--){
    cin >> n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin >> a[i][j];
        d[i][j] = -1;
      }
    }
    if(solve(0,0) == 1){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }
  }


  return 0;
}
