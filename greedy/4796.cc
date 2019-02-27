/**
 * 캠핑
 * 4796
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
  int l,p,v;
  int cnt = 1;
  while(true){
    cin >> l >> p >> v;
    int ans = 0;
    if(l == 0 && p == 0 && v == 0){
      break;
    }
    while(v-p >= 0){
      ans += l;
      v -= p;
    }
    if(l > v){
      ans += v;
    }
    else{
      ans += l;
    }

    cout << "Case " << cnt << ": " << ans << '\n';
    cnt++;
  }


  return 0;
}
