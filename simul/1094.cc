/**
 * 막대기
 * 1094
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

  int x;
  cin >> x;
  int ans = 0;
  for(int i=1;i<=x;i = i<<1){
    if(i & x){
      ans++;
    }
  }
  cout << ans << '\n';

  return 0;
}
