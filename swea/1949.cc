/**
 * 등산로 조성
 * 1949
 */
#include<cstdio>
#include<cstring>
using namespace std;
int N,K;
int a[8][8];
bool c[8][8];
int ans,cnt;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool flag = false;
void go(int x, int y, int apex){
  cnt++;
  c[x][y] = true;
  bool gone = false;

  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    // boundary
    if(nx < 0 || nx >= N || ny < 0 || ny >= N){
      continue;
    }
    // already visited
    if(c[nx][ny]){
      continue;
    }
    // can go
    if(a[nx][ny] < apex){
      gone = true;
      go(nx, ny, a[nx][ny]);
    }
    else if(!flag){
      for(int k=1;k<=K;k++){
        a[nx][ny] -= k;
        if(a[nx][ny] < apex){
          flag = true;
          gone = true;
          go(nx, ny, a[nx][ny]);
          flag = false;
        }
        a[nx][ny] += k;
      }
    }
  }
  
  if(!gone){
    if(ans < cnt){
      ans = cnt;
    }
  }

  cnt--;
  c[x][y] = false;
}
int main(){
	int test_case;
	int T;
  scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case){
    ans = 0;
    cnt = 0;
    memset(c, 0, sizeof(c));
    flag = false;

    scanf("%d %d\n",&N,&K);
    int apex = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        scanf("%d",&a[i][j]);
        if(a[i][j] > apex){
          apex = a[i][j];
        }
      }
    }

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(apex == a[i][j]){
          go(i, j, apex);
        }
      }
    }

    printf("#%d %d\n", test_case, ans);
  }

  return 0;
}
