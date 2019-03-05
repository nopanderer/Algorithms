/**
 * 테트로미노
 * 14500
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
int N,M;
int a[501][501];
int dx[19][4] = {
  {0,0,0,0},
  {0,1,2,3},
  {0,0,1,1},
  {0,1,2,2},
  {0,1,2,2},
  {0,1,1,1},
  {0,1,1,1},
  {0,0,1,2},
  {0,0,1,2},
  {0,0,0,1},
  {0,0,0,1},
  {0,1,1,2},
  {0,1,1,2},
  {0,0,1,1},
  {0,0,1,1},
  {0,0,0,1},
  {0,1,1,2},
  {0,1,1,2},
  {0,1,1,1},
};
int dy[19][4] = {
  // ****
  {0,1,2,3},
  // *
  // *
  // *
  // *
  {0,0,0,0},
  // **
  // **
  {0,1,0,1},
  // *
  // *
  // **
  {0,0,0,1},
  //  *
  //  *
  // **
  {1,1,0,1},
  //   *
  // ***
  {2,0,1,2},
  // *
  // ***
  {0,0,1,2},
  // **
  //  *
  //  *
  {0,1,1,1},
  // **
  // *
  // *
  {0,1,0,0},
  // ***
  // *
  {0,1,2,0},
  // ***
  //   *
  {0,1,2,2},
  // *
  // **
  //  *
  {0,0,1,1},
  //  *
  // **
  // *
  {1,0,1,0},
  //  **
  // **
  {1,2,0,1},
  // **
  //  **
  {0,1,1,2},
  // ***
  //  *
  {0,1,2,1},
  //  *
  // **
  //  *
  {1,0,1,1},
  // *
  // **
  // *
  {0,0,1,0},
  //  *
  // ***
  {1,0,1,2},
};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> a[i][j];
    }
  }
  int ans = 0;
  int sum = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      for(int k=0;k<19;k++){
        sum = 0;
        for(int l=0;l<4;l++){
          int nx = i + dx[k][l];
          int ny = j + dy[k][l];
          if(0 <= nx && nx < N && 0 <= ny && ny < M){
            sum += a[nx][ny];
          }
        }
        if(ans < sum){
          ans = sum;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
