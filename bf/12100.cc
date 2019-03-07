/**
 * 2048 (Easy)
 * 12100
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
int a[20][20];
int ans;
void print(){
  cout << '\n';
  cout << '\n';
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
void copy(int tmp[][20]){
  // copy
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      tmp[i][j] = a[i][j];
    }
  }
}
void restore(int tmp[][20]){
  // restore
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      a[i][j] = tmp[i][j];
    }
  }
}
void go(int d){
  if(d == 5){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(ans < a[i][j]){
          ans = a[i][j];
        }
      }
    }
    return;
  }
  int tmp[20][20];

  copy(tmp);
  queue<int> q;
  // left
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a[i][j] != 0){
        q.push(a[i][j]);
        a[i][j] = 0;
      }
    }
    int idx = 0;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      if(a[i][idx] == 0){
        a[i][idx] = x;
      }
      else if(a[i][idx] == x){
        a[i][idx] = 2*x;
        idx++;
      }
      else{
        idx++;
        a[i][idx] = x;
      }
    }
  }
  go(d+1);
  restore(tmp);

  // right
  for(int i=0;i<N;i++){
    for(int j=N-1;j>=0;j--){
      if(a[i][j] != 0){
        q.push(a[i][j]);
        a[i][j] = 0;
      }
    }
    int idx = N-1;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      if(a[i][idx] == 0){
        a[i][idx] = x;
      }
      else if(a[i][idx] == x){
        a[i][idx] = 2*x;
        idx--;
      }
      else{
        idx--;
        a[i][idx] = x;
      }
    }
  }
  go(d+1);
  restore(tmp);
  
  // down
  for(int i=0;i<N;i++){
    for(int j=N-1;j>=0;j--){
      if(a[j][i] != 0){
        q.push(a[j][i]);
        a[j][i] = 0;
      }
    }
    int idx = N-1;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      if(a[idx][i] == 0){
        a[idx][i] = x;
      }
      else if(a[idx][i] == x){
        a[idx][i] = 2*x;
        idx--;
      }
      else{
        idx--;
        a[idx][i] = x;
      }
    }
  }
  go(d+1);
  restore(tmp);

  // up
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(a[j][i] != 0){
        q.push(a[j][i]);
        a[j][i] = 0;
      }
    }
    int idx = 0;
    while(!q.empty()){
      int x = q.front();
      q.pop();
      if(a[idx][i] == 0){
        a[idx][i] = x;
      }
      else if(a[idx][i] == x){
        a[idx][i] = 2*x;
        idx++;
      }
      else{
        idx++;
        a[idx][i] = x;
      }
    }
  }
  go(d+1);
  restore(tmp);
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

  go(0);
  cout << ans << '\n';

  return 0;
}
