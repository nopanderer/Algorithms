/**
 * 탈출
 * 16397
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
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n,t,g;
  int c[100000];
  queue<int> q;
  memset(c, -1 ,sizeof(c));
  cin >> n >> t >> g;
  c[n] = 0;
  q.push(n);
  while(!q.empty()){
    int now = q.front();
    q.pop();
    // A = N + 1;
    int a = now + 1;
    if(a < 100000 && c[a] == -1){
      c[a] = c[now] + 1;
      q.push(a);
    }

    // B = N * 2, then highest digit - 1
    int b = now * 2;
    if(b > 99999){
      continue;
    }
    string tmp = to_string(b);
    if(tmp.size() > 1){
      tmp[0] = tmp[0] - 1;
      b = stoi(tmp);
    }
    else{
      b = b - 1;
    }
    if(b < 100000 && c[b] == -1){
      c[b] = c[now] + 1;
      q.push(b);
    }
  }

  if(c[g] == -1 || c[g] > t){
    cout << "ANG\n";
  }
  else{
    cout << c[g] << '\n';
  }

  return 0;
}
