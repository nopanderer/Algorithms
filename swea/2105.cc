/**
 * 디저트 카페
 * 2105
 */
#include<cstdio>
#include<cstring>
using namespace std;
int N;
int a[21][21];
int c[101];
int ans, cnt;
int sx, sy;
bool check(int x, int y){
  if(x < 0 || x >= N || y < 0 || y >= N){
    return false;
  }
  return true;
}
void go(int x, int y, int dir){
  cnt++;
  c[a[x][y]]++;

  // base case
  if(dir == 4 && sx == x && sy == y){
    if(ans < cnt - 1){
      ans = cnt - 1;
    }
  }

  else{
    if(dir == 0){
      if(check(x+1, y+1) && !c[a[x+1][y+1]]){
        go(x+1, y+1, 1);
      }
    }

    else if(dir == 1){
      if(check(x+1, y+1) && !c[a[x+1][y+1]]){
        go(x+1, y+1, 1);
      }
      if(check(x+1, y-1) && !c[a[x+1][y-1]]){
        go(x+1, y-1, 2);
      }
    }

    else if(dir == 2){
      if(check(x+1, y-1) && !c[a[x+1][y-1]]){
        go(x+1, y-1, 2);
      }
      if(check(x-1, y-1) && !c[a[x-1][y-1]]){
        go(x-1, y-1, 3);
      }
    }

    else if(dir == 3){
      if(check(x-1, y-1) && !c[a[x-1][y-1]]){
        go(x-1, y-1, 3);
      }
      if(sx == x-1 && sy == y+1){
        go(x-1, y+1, 4);
      }
      else{
        if(check(x-1, y+1) && !c[a[x-1][y+1]]){
          go(x-1, y+1, 4);
        }
      }
    }

    else{
      if(sx == x-1 && sy == y+1){
        go(x-1, y+1, 4);
      }
      else{
        if(check(x-1, y+1) && !c[a[x-1][y+1]]){
          go(x-1, y+1, 4);
        }
      }
    }
  }
  cnt--;
  c[a[x][y]]--;
}
//int main(int argc, char** argv){
int main(){
	int test_case;
	int T;
  scanf("%d",&T);
	for(test_case = 1; test_case <= T; ++test_case){
    memset(c, 0, sizeof(c));
    ans = -1;
    cnt = 0;

    scanf("%d",&N);
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        scanf("%d",&a[i][j]);
      }
    }

    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        sx = i;
        sy = j;
        go(i, j, 0);
      }
    }

    printf("#%d %d\n", test_case, ans);
  }

  return 0;
}
