/**
 * 연산자 끼워넣기
 * 14888
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
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int a[12];
int ansMax = -2147483647;
int ansMin = 2147483647;
void go(int idx, int res, int plus, int minus, int mul, int div){
  if(idx == N){
    if(ansMax < res){
      ansMax = res;
    }
    if(ansMin > res){
      ansMin = res;
    }
    return;
  }

  if(plus != 0){
    go(idx + 1, res + a[idx], plus - 1, minus, mul, div);
  }
  if(minus != 0){
    go(idx + 1, res - a[idx], plus, minus - 1, mul, div);
  }
  if(mul != 0){
    go(idx + 1, res * a[idx], plus, minus, mul - 1, div);
  }
  if(div != 0){
    go(idx + 1, res / a[idx], plus, minus, mul, div - 1);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int plus,minus,mul,div;

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  cin >> plus >> minus >> mul >> div;

  go(1,a[0],plus,minus,mul,div);

  cout << ansMax << '\n' << ansMin << '\n';

  return 0;
}
