/**
 * 경사로
 * 14890
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
int N,L;
int ans;
void check(int a[101][101], int row){
  bool v[101] = {false, };
  for(int i=0;i<N-1;i++){
    if(a[row][i] != a[row][i+1]){
      int dif = abs(a[row][i] - a[row][i+1]);
      if(dif != 1){
        return;
      }
      if(a[row][i] < a[row][i+1]){
        for(int j=0;j<L;j++){
          if(i-j < 0 || v[i-j]){
            return;
          }
          if(a[row][i] == a[row][i-j]){
            v[i-j] = true;
          }
          else{
            return;
          }
        }
      }
      else{
        for(int j=0;j<L;j++){
          if(i+1+j >= N || v[i+1+j]){
            return;
          }
          if(a[row][i+1] == a[row][i+1+j]){
            v[i+j+1] = true;
          }
          else{
            return;
          }
        }
      }
    }
  }
  ans++;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a[101][101];
  int b[101][101];

  cin >> N >> L;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
      b[j][i] = a[i][j];
    }
  }

  for(int i=0;i<N;i++){
    check(a,i);
    check(b,i);
  }

  cout << ans << '\n';

  return 0;
}
