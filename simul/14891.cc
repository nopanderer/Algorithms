/**
 * 톱니바퀴
 * 14891
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
string t[4];
int K;
int num, dir;
void rotate(int x, int d, bool left, bool right){
  if(left){
    int l = x-1;
    if(l >= 0 && t[x][6] != t[l][2]){
      rotate(l, -d, true, false);
    }
  }
  if(right){
    int r = x+1;
    if(r <= 3 && t[x][2] != t[r][6]){
      rotate(r, -d, false, true);
    }
  }
  if(d == -1){
    char tmp = t[x][0];
    for(int i=1;i<=7;i++){
      t[x][i-1] = t[x][i];
    }
    t[x][7] = tmp;
  }
  else if(d == 1){
    char tmp = t[x][7];
    for(int i=6;i>=0;i--){
      t[x][i+1] = t[x][i];
    }
    t[x][0] = tmp;
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<4;i++){
    cin >> t[i];
  }
  cin >> K;
  for(int i=0;i<K;i++){
    cin >> num >> dir;
    rotate(num-1, dir, true, true);
  }


  int ans = 0;
  if(t[0][0] == '1'){
    ans += 1;
  }
  if(t[1][0] == '1'){
    ans += 2;
  }
  if(t[2][0] == '1'){
    ans += 4;
  }
  if(t[3][0] == '1'){
    ans += 8;
  }

  cout << ans << '\n';

  return 0;
}
