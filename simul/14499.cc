/**
 * 주사위 굴리기
 * 14499
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
int N,M,x,y,K;
int a[21][21];
int dice[7];
int ndice[7];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
bool check(int x, int y){
  return (0 <= x && x < N && 0 <= y && y < M);
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> x >> y >> K;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> a[i][j];
    }
  }
  while(K--){
    int dir;
    cin >> dir;
    dir--;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(check(nx,ny) == false){
      continue;
    }
    // EAST
    if(dir == 0){
      ndice[3] = dice[1];
      ndice[6] = dice[3];
      ndice[4] = dice[6];
      ndice[1] = dice[4];
      ndice[2] = dice[2];
      ndice[5] = dice[5];
    }
    // WEST
    else if(dir == 1){
      ndice[4] = dice[1];
      ndice[1] = dice[3];
      ndice[3] = dice[6];
      ndice[6] = dice[4];
      ndice[2] = dice[2];
      ndice[5] = dice[5];
    }
    // NORTH
    else if(dir == 2){
      ndice[2] = dice[1];
      ndice[6] = dice[2];
      ndice[1] = dice[5];
      ndice[5] = dice[6];
      ndice[3] = dice[3];
      ndice[4] = dice[4];
    }
    // SOUTH
    else if(dir == 3){
      ndice[5] = dice[1];
      ndice[1] = dice[2];
      ndice[6] = dice[5];
      ndice[2] = dice[6];
      ndice[3] = dice[3];
      ndice[4] = dice[4];
    }

    if(a[nx][ny] == 0){
      a[nx][ny] = ndice[6];
    }
    else{
      ndice[6] = a[nx][ny];
      a[nx][ny] = 0;
    }
    for(int i=1;i<=6;i++){
      dice[i] = ndice[i];
    }
    cout << dice[1] << '\n';
    x = nx;
    y = ny;
  }

  return 0;
}
