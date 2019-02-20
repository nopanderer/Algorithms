/**
 * 감소하는 수
 * 1038
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
int n;
vector<long long> a;
void go(long long num, int d){
  // 9876543210 이 가장 큰 감소하는 수이고 이게 10자리이기 때문에 그 이상은 할 수가 없음
  if(d > 10){
    return;
  }

  a.push_back(num);

  // 입력으로 들어오는 수보다 작은 수를 뒤에 재귀적으로 붙여나감
  for(int i=0;i<10;i++){
    if(num%10 > i){
      go(num * 10 + i, d + 1);
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<10;i++){
    go(i,1);
  }
  sort(a.begin(), a.end());
  if(a.size() <= n){
    cout << "-1\n";
  }
  else{
    cout << a[n] << '\n';
  }
    
  return 0;
}
