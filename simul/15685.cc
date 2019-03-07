/**
 * 드래곤 커브
 * 15685
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
int x,y,d,g;
int a[101][101];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  while(N--){
    cin >> x >> y >> d >> g;
    vector<int> order;
    order.push_back(d);
    while(g--){
      for(int i=order.size()-1;i>=0;i--){
        order.push_back((order[i]+1)%4);
      }
    }
    a[x][y] = 1;
    for(auto &o : order){
      switch(o){
        case 0:
          x++;
          break;
        case 1:
          y--;
          break;
        case 2:
          x--;
          break;
        case 3:
          y++;
          break;
      }
      a[x][y] = 1;
    }
  }
  int ans = 0;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]){
        ans++;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
