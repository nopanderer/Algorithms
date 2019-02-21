/**
 * 이항 계수 2
 * 11051
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
const int mod = 10007;
int d[1001][1001];
int solve(int n, int k){
  if(n == k || k == 0){
    return 1;
  }
  if(k == 1){
    return n;
  }
  if(d[n][k] != -1){
    return d[n][k];
  }
  return d[n][k] = (solve(n-1,k) + solve(n-1,k-1)) % mod;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  memset(d, -1, sizeof(d));
  d[n][k] = solve(n,k);

  cout << d[n][k] << '\n';

  return 0;
}
