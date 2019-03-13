/**
 * 토너먼트
 * 1057
 */
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  int a,b;
  cin >> N >> a >> b;
  int ans = 0;
  while(a != b){
    a -= a/2;
    b -= b/2;
    ans++;
  }

  cout << ans << '\n';


  return 0;
}
