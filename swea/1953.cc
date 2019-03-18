/**
 * 탈주범 검거
 * 1953
 */
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int N,M,R,C,L;
int ans;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int a[50][50];
int c[50][50];
void go(int x, int y, int d, queue<pair<int,int> > &q){
  int nx = x + dx[d];
  int ny = y + dy[d];

  // boundary
  if(nx < 0 || nx >= N || ny < 0 || ny >= M){
    return;
  }

  // not tunnel
  if(a[nx][ny] == 0){
    return;
  }

  // visited?
  if(c[nx][ny] != 0){
    return;
  }

  int next = a[nx][ny];

  if(d == 0){
    if(next == 1 || next == 2 || next == 5 || next == 6){
      c[nx][ny] = c[x][y] + 1;
      q.push({nx,ny});
    }
  }
  else if(d == 1){
    if(next == 1 || next == 2 || next == 4 || next == 7){
      c[nx][ny] = c[x][y] + 1;
      q.push({nx,ny});
    }
  }
  else if(d == 2){
    if(next == 1 || next == 3 || next == 4 || next == 5){
      c[nx][ny] = c[x][y] + 1;
      q.push({nx,ny});
    }
  }
  else if(d == 3){
    if(next == 1 || next == 3 || next == 6 || next == 7){
      c[nx][ny] = c[x][y] + 1;
      q.push({nx,ny});
    }
  }
}
void solve(int x, int y){
  c[x][y] = 1;
  queue<pair<int,int> > q;
  q.push({x,y});

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    if(c[x][y] == L){
      break;
    }

    int cur = a[x][y];

    if(cur == 1){
      go(x, y, 0, q);
      go(x, y, 1, q);
      go(x, y, 2, q);
      go(x, y, 3, q);
    }
      
    else if(cur == 2){
      go(x, y, 0, q);
      go(x, y, 1, q);
    }

    else if(cur == 3){
      go(x, y, 2, q);
      go(x, y, 3, q);
    }

    else if(cur == 4){
      go(x, y, 0, q);
      go(x, y, 3, q);
    }

    else if(cur == 5){
      go(x, y, 1, q);
      go(x, y, 3, q);
    }

    else if(cur == 6){
      go(x, y, 1, q);
      go(x, y, 2, q);
    }

    else if(cur == 7){
      go(x, y, 0, q);
      go(x, y, 2, q);
    }
  }
}
int main(){
	int test_case;
	int T;
  scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case){
    memset(c, 0, sizeof(c));
    ans = 0;

    scanf("%d %d %d %d %d",&N,&M,&R,&C,&L);
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        scanf("%d",&a[i][j]);
      }
    }

    solve(R,C);

    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(c[i][j]){
          ans++;
        }
      }
    }

    printf("#%d %d\n",test_case,ans);

  }
  return 0;
}
