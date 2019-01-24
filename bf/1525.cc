/**
 * 퍼즐
 * 1525
 */
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
using namespace std;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int main(){
  int start = 0;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      int tmp;
      cin>>tmp;
      if(tmp == 0) tmp = 9;
      start = start*10 + tmp; // 2d arr to 1d
    }
  }
  queue<int> q;
  map<int,int> dist;
  dist[start] = 0;
  q.push(start);
  while(!q.empty()){
    int now_num = q.front();
    string now = to_string(now_num);
    q.pop();
    int z = now.find('9');
    int x = z/3;
    int y = z%3;
    for(int i=0;i<4;i++){
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(0<=nx && nx<3 && 0<=ny && ny<3){
        string next = now;
        swap(next[x*3+y],next[nx*3+ny]);
        int num = stoi(next);
        if(dist.count(num) == 0){
          dist[num] = dist[now_num] + 1;
          q.push(num);
        }
      }
    }
  }
  if(dist.count(123456789) == 0){
    cout<<"-1\n";
  }
  else{
    cout<<dist[123456789]<<'\n';
  }
  
  return 0;
}
