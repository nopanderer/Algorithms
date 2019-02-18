/**
 * 사탕 게임
 * 3085
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
char a[51][51];
int checkRow(int r){
  int ret = 0;
  int len = 1;
  for(int i=0;i<n-1;i++){
    if(a[r][i] == a[r][i+1]){
      len++;
    }
    else{
      if(len > ret){
        ret = len;
      }
      len = 1;
    }
  }
  if(len > ret){
    ret = len;
  }

  return ret;
}
int checkCol(int c){
  int ret = 0;
  int len = 1;
  for(int i=0;i<n-1;i++){
    if(a[i][c] == a[i+1][c]){
      len++;
    }
    else{
      if(len > ret){
        ret = len;
      }
      len = 1;
    }
  }
  if(len > ret){
    ret = len;
  }

  return ret;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i=0;i<n;i++){
    string tmp;
    cin >> tmp;
    for(int j=0;j<n;j++){
      a[i][j] = tmp[j];
    }
  }
  int ans = 0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j+1 < n){
        swap(a[i][j], a[i][j+1]);
        ans = max(checkRow(i), ans);
        ans = max(checkCol(j), ans);
        ans = max(checkCol(j+1), ans);
        swap(a[i][j], a[i][j+1]);
      }

      if(i+1 < n){
        swap(a[i][j], a[i+1][j]);
        ans = max(checkCol(j), ans);
        ans = max(checkRow(i), ans);
        ans = max(checkRow(i+1), ans);
        swap(a[i][j], a[i+1][j]);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
// 50*50*2
