/**
 * 로프
 * 2217
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
int N;
vector<int> a;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for(int i=N-1;i>=0;i--){
    ans = max(ans, a[i]*(N-i));
  }

  cout << ans << '\n';

  return 0;
}
