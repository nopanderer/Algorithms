/**
 * 스타트와 링크
 * 14889
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
int a[21][21];
int t[21];
int ans = 2147483647;
void go(int idx, int cntA, int cntB){
  if(idx == N){
    int sumA = 0;
    for(int i=0;i<N-1;i++){
      if(t[i] == 1){
        for(int j=i+1;j<N;j++){
          if(t[j] == 1){
            sumA += (a[i][j] + a[j][i]);
          }
        }
      }
    }
    int sumB = 0;
    for(int i=0;i<N-1;i++){
      if(t[i] == 2){
        for(int j=i+1;j<N;j++){
          if(t[j] == 2){
            sumB += (a[i][j] + a[j][i]);
          }
        }
      }
    }

    int dif = sumA - sumB;
    if(dif < 0){
      dif = sumB - sumA;
    }
    if(ans > dif){
      ans = dif;
    }
    return;
  }

  if(cntA < N/2){
    t[idx] = 1;
    go(idx + 1, cntA + 1, cntB);
  }
  if(cntB < N/2){
    t[idx] = 2;
    go(idx + 1, cntA, cntB + 1);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
    }
  }

  go(0,0,0);

  cout << ans << '\n';

  return 0;
}
