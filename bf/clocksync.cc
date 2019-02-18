/**
 * 시계 맞추기
 * clocksync
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
int swtch[10][10] = {{0,1,2,-1},
                    {3,7,9,11,-1},
                    {4,10,14,15,-1},
                    {0,4,5,6,7,-1},
                    {6,7,8,10,12,-1},
                    {0,2,14,15,-1},
                    {3,14,15,-1},
                    {4,5,7,14,15,-1},
                    {1,2,3,4,5,-1},
                    {3,4,5,9,13,-1}};
int c;
int a[16];
bool check[10];
int solve(int idx){
  if(idx == 10){
    for(int i=0;i<16;i++){
      if(a[i] != 12){
        return 9999;
      }
    }
    return 0;
  }
  int ret = 9999;
  for(int i=0;i<4;i++){
    ret = min(ret, i + solve(idx+1));
    for(int j=0;j<10;j++){
      int next = swtch[idx][j];
      if(next == -1)
        break;
      a[next] += 3;
      if(a[next] == 15){
        a[next] = 3;
      }
    }
  }
  return ret;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> c;
  while(c--){
    for(int i=0;i<16;i++){
      cin >> a[i];
    }
    int ans = solve(0);
    if(ans == 9999){
      cout << "-1\n";
    }
    else{
      cout << ans << '\n';
    }
  }

  return 0;
}
// 각 스위치는 최대 3번까지 누를 수 있음 (4번째부터는 원래대로 돌아옴)
// 안누르고 넘어가던지 1,2,3번 누르던지 총 4개의 옵션
// 전체 스위치 10개에 대해서 시간복잡도 = O(4^10)
