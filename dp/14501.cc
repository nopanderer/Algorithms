/**
 * 퇴사
 * 14501
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
  int d[16];
  int t[16];
  int p[16];
  memset(d, 0, sizeof(d));
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> t[i] >> p[i];
  }
  for(int i=N;i>=1;i--){
    if(i + t[i] - 1 <= N){
      d[i] = p[i];
    }
    if(i + t[i] <= N){
      d[i] += d[i + t[i]];
    }
    for(int j=i+1;j<=N;j++){
      d[i] = max(d[i], d[j]);
    }
  }

  cout << d[1] << '\n';

  return 0;
}
