/**
 * 뱀
 * 3190
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
struct Turn{
  int x,y,d;
  Turn(int x,int y,int d){
    this->x = x;
    this->y = y;
    this->d = d;
  }
};
int N, K, L;
int board[101][101];
char dir[10001];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i=0;i<K;i++){
    int x,y;
    cin >> x >> y;
    board[x][y] = 2;
  }
  cin >> L;
  for(int i=0;i<L;i++){
    int x;
    char d;
    cin >> x >> d;
    dir[x] = d;
  }

  int headX = 1;
  int headY = 1;
  int tailX = 1;
  int tailY = 1;
  int headD = 1;
  int tailD = 1;
  int time = 0;
  queue<Turn> q;
  board[headX][headY] = 1;
  while(true){
    time++;
    headX += dx[headD];
    headY += dy[headD];
    // collision check
    if(board[headX][headY] == 1 || headX < 1 || headX > N || headY < 1 || headY > N){
      break;
    }
    // apple
    if(board[headX][headY] == 2){
      board[headX][headY] = 1;
    }
    // no apple
    else{
      board[headX][headY] = 1;
      board[tailX][tailY] = 0;
      tailX += dx[tailD];
      tailY += dy[tailD];
    }
    // head turn
    if(dir[time] == 'L'){
      headD--;
      if(headD < 0){
        headD = 3;
      }
      q.push(Turn(headX, headY, headD));
    }
    if(dir[time] == 'D'){
      headD++;
      if(headD > 3){
        headD = 0;
      }
      q.push(Turn(headX, headY, headD));
    }
    // tail turn
    if(!q.empty() && tailX == q.front().x && tailY == q.front().y){
      tailD = q.front().d;
      q.pop();
    }
  }

  cout << time << '\n';

  return 0;
}
