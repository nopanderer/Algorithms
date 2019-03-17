/**
 * 핀볼 게임
 * 5650
 */
#include<cstdio>
#include<vector>
using namespace std;
//int main(int argc, char** argv){
int N;
int a[100][100];
int ans;
int cnt;
int sx,sy;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
vector<pair<int,int> > w[11];
void go(int x, int y, int d){
  int nx = x + dx[d];
  int ny = y + dy[d];

  while(true){
    // wall
    if(nx < 0 || nx >= N || ny < 0 || ny >= N){
      cnt++;
      d = 3-d;
      nx += dx[d];
      ny += dy[d];
    }

    // start point or black hole
    else if((nx == sx && ny == sy) || (a[nx][ny] == -1)){
      if(ans < cnt){
        ans = cnt;
      }

      break;
    }

    // empty space
    else if(a[nx][ny] == 0){
      nx += dx[d];
      ny += dy[d];
    }

    // blocks
    else if(a[nx][ny] == 1){
      cnt++;
      if(d == 0 || d == 2){
        d = 3-d;
        nx += dx[d];
        ny += dy[d];
      }
      else{
        d = d-1;
        nx += dx[d];
        ny += dy[d];
      }
    }

    else if(a[nx][ny] == 2){
      cnt++;
      if(d == 2 || d == 3){
        d = 3-d;
        nx += dx[d];
        ny += dy[d];
      }
      else{
        d = d+2;
        nx += dx[d];
        ny += dy[d];
      }
    }

    else if(a[nx][ny] == 3){
      cnt++;
      if(d == 1 || d == 3){
        d = 3-d;
        nx += dx[d];
        ny += dy[d];
      }
      else{
        d = d+1;
        nx += dx[d];
        ny += dy[d];
      }
    }

    else if(a[nx][ny] == 4){
      cnt++;
      if(d == 0 || d == 1){
        d = 3-d;
        nx += dx[d];
        ny += dy[d];
      }
      else{
        d = d-2;
        nx += dx[d];
        ny += dy[d];
      }
    }

    else if(a[nx][ny] == 5){
      cnt++;
      d = 3-d;
      nx += dx[d];
      ny += dy[d];
    }

    // worm hole
    else{
      pair<int,int> w1 = w[a[nx][ny]][0];
      pair<int,int> w2 = w[a[nx][ny]][1];

      if(w1.first == nx && w1.second == ny){
        nx = w2.first + dx[d];
        ny = w2.second + dy[d];
      }
      else{
        nx = w1.first + dx[d];
        ny = w1.second + dy[d];
      }
      /*
      if(w[a[nx][ny]][0].first == nx && w[a[nx][ny]][0].second == ny){
        go(w[a[nx][ny]][1].first, w[a[nx][ny]][1].second, d);
      }
      else{
        go(w[a[nx][ny]][0].first, w[a[nx][ny]][0].second, d);
      }
      */
    }
  }
}
int main(){
	int test_case;
	int T;
  scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case){
    ans = 0;
    for(int i=0;i<=10;i++){
      w[i].clear();
    }

    scanf("%d", &N);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        scanf("%d", &a[i][j]);
        if(6 <= a[i][j] && a[i][j] <= 10){
          w[a[i][j]].push_back({i,j});
        }
      }
    }

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        for(int k=0;k<4;k++){
          if(a[i][j] == 0){
            cnt = 0;
            sx = i;
            sy = j;
            go(i, j, k);
          }
        }
      }
    }

    printf("#%d %d\n", test_case, ans);
  }

  return 0;
}
