/**
 * 상범 빌딩
 * 6593
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
int a[31][31][31];
int c[31][31][31];
int dl[] = {-1,1,0,0,0,0};
int dr[] = {0,0,0,0,-1,1};
int dc[] = {0,0,-1,1,0,0};
int L,R,C;
int s1,s2,s3;
int e1,e2,e3;
struct Point{
  int x,y,z;
  Point(int a, int b, int c){
    x = a;
    y = b;
    z = c;
  }
};
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while(true){
    cin >> L >> R >> C;
    if(L == 0 && R == 0 && C == 0){
      break;
    }
    memset(c, -1, sizeof(c));
    memset(a, 0, sizeof(a));
    for(int l=0;l<L;l++){
      for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
          char tmp;
          cin >> tmp;
          if(tmp == '.' || tmp == 'S' || tmp == 'E'){
            a[l][r][c] = 1;
          }
          if(tmp == 'S'){
            s1 = l;
            s2 = r;
            s3 = c;
          }
          if(tmp == 'E'){
            e1 = l;
            e2 = r;
            e3 = c;
          }
        }
      }
    }
    queue<Point> q;
    c[s1][s2][s3] = 0;
    q.push(Point(s1,s2,s3));
    while(!q.empty()){
      Point now = q.front();
      int x = now.x;
      int y = now.y;
      int z = now.z;
      q.pop();
      for(int i=0;i<6;i++){
        int nx = x + dl[i];
        int ny = y + dr[i];
        int nz = z + dc[i];
        if(0 <= nx && nx < L && 0 <= ny && ny < R && 0 <= nz && nz < C){
          if(a[nx][ny][nz] == 1 && c[nx][ny][nz] == -1){
            c[nx][ny][nz] = c[x][y][z] + 1;
            q.push(Point(nx,ny,nz));
          }
        }
      }
    }

    if(c[e1][e2][e3] == -1){
      cout << "Trapped!\n";
    }
    else{
      cout << "Escaped in " << c[e1][e2][e3] << " minute(s).\n";
    }
    
  }

  return 0;
}
