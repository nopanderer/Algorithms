/**
 * 유레카 이론
 * 10448
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
int a[1001];
bool solve(int k, int cnt, int sum){
  if(sum > k)
    return false;
  if(cnt == 3){
    if(sum == k)
      return true;
    else
      return false;
  }
  bool flag = false;
  for(int i=1;a[i] < k;i++){
    flag |= solve(k, cnt+1, sum+a[i]);
  }

  return flag;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t,k;
  for(int i=1;i<=1000;i++){
    a[i] = i*(i+1)/2;
  }
  cin >> t;
  while(t--){
    cin >> k;
    if(solve(k,0,0) == true)
      cout << "1\n";
    else
      cout << "0\n";
  }

  return 0;
}
// 1000*1000*1000인 것 같지만 a[i] < k 과 if문 때문에 탐색공간이 줄어듦
