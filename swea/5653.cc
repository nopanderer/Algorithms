/**
 * 줄기세포배양
 * 5653
 */
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
struct Cell{
  int x;
  int y;
  int life;
  int time;
};
bool cmp(const Cell &c1, const Cell &c2){
  return c1.life > c2.life;
}
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N,M,K;
int a[500][500];
//int main(int argc, char** argv)
int main(){
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
    cin >> N >> M >> K;

    memset(a, 0, sizeof(a));
    queue<Cell> q;

    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        int x = 500/2 + i;
        int y = 500/2 + j;
        cin >> a[x][y];
        if(a[x][y]){
          q.push({x,y,a[x][y],0});
        }
      }
    }

    for(int k=1;k<=K;k++){
      vector<Cell> alive;
      vector<Cell> spawn;
      while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int life = q.front().life;
        int time = q.front().time;
        q.pop();
        if(k == time + life + 1){
          // spawn
          spawn.push_back({x,y,life,time});
        }
        if(k == time + life * 2){
          // dead
          continue;
        }
        else{
          alive.push_back({x,y,life,time});
        }
      }
      if(!spawn.empty()){
        // spawn
        sort(spawn.begin(), spawn.end(), cmp);
        for(int i=0;i<(int)spawn.size();i++){
          int x = spawn[i].x;
          int y = spawn[i].y;
          int life = spawn[i].life;
          int time = spawn[i].time;
          for(int j=0;j<4;j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(a[nx][ny] == 0){
              a[nx][ny] = life;
              alive.push_back({nx, ny, life, k});
            }
          }
        }
      }
      // alive to queue
      for(int i=0;i<(int)alive.size();i++){
        q.push({alive[i].x, alive[i].y, alive[i].life, alive[i].time});
      }
    }
      cout << '#' << test_case << ' ' << q.size() << '\n';

	}
  return 0;
}
