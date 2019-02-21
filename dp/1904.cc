/**
 * 01타일
 * 1904
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
int d[1000001];
int n;
const int mod = 15746;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for(int i=3;i<=n;i++){
    d[i] = (d[i-1] + d[i-2]) % mod;
  }

  cout << d[n] << '\n';


  return 0;
}
