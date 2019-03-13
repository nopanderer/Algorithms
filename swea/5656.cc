/**
 * 벽돌 깨기
 * 5656
 */
#include<iostream>
#include<queue>
#include<cmath>

using namespace std;
int R,C,N;
int a[20][20];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ans;
void copy(int b[20][20]){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      b[i][j] = a[i][j];
    }
  }
}
void restore(int b[20][20]){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      a[i][j] = b[i][j];
    }
  }
}
void bomb(int col){
  queue<pair<int,int> > q;
  for(int i=0;i<R;i++){
    if(a[i][col] == 0){
      continue;
    }
    else if(a[i][col] == 1){
      a[i][col] = 0;
      break;
    }
    else{
      q.push({i,col});
      break;
    }
  }

  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    int len = a[x][y];
    a[x][y] = 0;
    for(int i=1;i<len;i++){
      for(int j=0;j<4;j++){
        int nx = x + i * dx[j];
        int ny = y + i * dy[j];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C){
          continue;
        }
        if(a[nx][ny] == 0){
          continue;
        }
        if(a[nx][ny] == 1){
          a[nx][ny] = 0;
        }
        else{
          q.push({nx,ny});
        }
      }
    }
  }
}
void down(){
  for(int i=0;i<C;i++){
    for(int j=R-2;j>=0;j--){
      if(a[j][i] != 0 && a[j+1][i] == 0){
        int k = j+1;
        for(;k<R;k++){
          if(a[k][i] == 0){
            continue;
          }
          else{
            break;
          }
        }
        a[k-1][i] = a[j][i];
        a[j][i] = 0;
      }
    }
  }
}
void print(){
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}
int count(){
  int cnt = 0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(a[i][j]){
        cnt++;
      }
    }
  }
  return cnt;
}
void go(int cnt){
  if(cnt == N){
    ans = min(ans, count());
    return;
  }

  for(int i=0;i<C;i++){
    int b[20][20];
    copy(b);
    bomb(i);
    down();
    go(cnt+1);
    restore(b);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case){
    ans = 987654321;
    cin >> N >> C >> R;
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        cin >> a[i][j];
      }
    }

    go(0);

    cout << '#' << test_case << ' ';
    cout << ans << '\n';
	}
  return 0;
}
