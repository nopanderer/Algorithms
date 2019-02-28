/**
 * 멀티탭 스케줄링
 * 1700
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
int N,K;
int a[101];
int c[101];
int ans;
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i=0;i<K;i++){
    cin >> a[i];
  }

  for(int i=0;i<K;i++){
    bool found = false;
    for(int j=0;j<N;j++){
      if(a[i] == c[j]){
        found = true;
        break;
      }
    }
    if(found){
      continue;
    }
    for(int j=0;j<N;j++){
      if(c[j] == 0){
        c[j] = a[i];
        found = true;
        break;
      }
    }
    if(found){
      continue;
    }
    int swap;
    int val = -1;
    for(int j=0;j<N;j++){
      int tmp = 0;
      for(int k=i+1;k<K && c[j] != a[k];k++){
        tmp++;
      }
      if(tmp > val){
        swap = j;
        val = tmp;
      }
    }
    ans++;
    c[swap] = a[i];
  }

  cout << ans << '\n';

  return 0;
}

