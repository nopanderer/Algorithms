/**
 * 분해합
 * 2231
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
int cal(int x){
  int sum = 0;
  while(x != 0){
    sum += x%10;
    x/=10;
  }
  return sum;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for(int i=1;i<=1000000;i++){
    if(i + cal(i) == n){
      cout << i << '\n';
      return 0;
    }
  }
  cout << "0\n";

  return 0;
}
