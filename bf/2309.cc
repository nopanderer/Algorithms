/**
 * 일곱 난쟁이
 * 2309
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
int a[9];
vector<int> ans;
void solve(int idx, int sum){
  if(idx == 9){
    if(ans.size() == 7 && sum == 100){
      for(auto &p : ans){
        cout << p << '\n';
      }
      exit(0);
    }
    else{
      return;
    }
  }
  solve(idx+1, sum);
  ans.push_back(a[idx]);
  solve(idx+1, sum + a[idx]);
  ans.pop_back();
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for(int i=0;i<9;i++){
    cin >> a[i];
  }
  sort(a,a+9);
  solve(0,0);

  return 0;
}
// 9C7 = 36, 완탐으로 가능
