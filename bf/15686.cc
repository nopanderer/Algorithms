/**
 * 치킨 배달
 * 15686
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N,M;
int a[51][51];
bool c[51][51];
vector<pair<int,int>> home;
vector<pair<int,int>> chicken;
int ans = 987654321;
void go(int cnt, int x, int y){
  if(cnt == M){
    int sum = 0;
    for(auto &h : home){
      int d = 987654321;
      for(auto &ch : chicken){
        if(c[ch.first][ch.second]){
          int tmp = abs(h.first - ch.first) + abs(h.second - ch.second);
          if(d > tmp){
            d = tmp;
          }
        }
      }
      sum += d;
    }
    if(ans > sum){
      ans = sum;
    }
    
    return;
  }


  int j = y;
  for(int i=x;i<N;i++){
    for(;j<N;j++){
      if(a[i][j] == 2 && c[i][j] == false){
        c[i][j] = true;
        go(cnt + 1, i, j);
        c[i][j] = false;
      }
    }
    j = 0;
  }
}
int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> a[i][j];
      if(a[i][j] == 1){
        home.push_back({i,j});
      }
      else if(a[i][j] == 2){
        chicken.push_back({i,j});
      }
    }
  }
  go(0,0,0);

  cout << ans << '\n';

  return 0;
}
