/**
 * 감시
 * 15683
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct CCTV{
  int x,y;
  int num;
  int dir;
};
int N,M;
int a[9][9];
int check[9][9];
vector<CCTV> c;
int ans = 987654321;
void toWest(int x, int y){
  while(true){
    y++;
    if(0 <= y && y < M){
      if(a[x][y] != 6){
        check[x][y] = 1;
      }
      else{
        break;
      }
    }
    else{
      break;
    }
  }
}
void toEast(int x, int y){
  while(true){
    y--;
    if(0 <= y && y < M){
      if(a[x][y] != 6){
        check[x][y] = 1;
      }
      else{
        break;
      }
    }
    else{
      break;
    }
  }
}
void toNorth(int x, int y){
  while(true){
    x--;
    if(0 <= x && x < N){
      if(a[x][y] != 6){
        check[x][y] = 1;
      }
      else{
        break;
      }
    }
    else{
      break;
    }
  }
}
void toSouth(int x, int y){
  while(true){
    x++;
    if(0 <= x && x < N){
      if(a[x][y] != 6){
        check[x][y] = 1;
      }
      else{
        break;
      }
    }
    else{
      break;
    }
  }
}
int cntSpace(){
  memset(check,0,sizeof(check));
  // cctv on
  for(auto &p : c){
    switch(p.num){
      case 1:
        if(p.dir == 0){
          toWest(p.x,p.y);
        }
        else if(p.dir == 1){
          toEast(p.x,p.y);
        }
        else if(p.dir == 2){
          toNorth(p.x,p.y);
        }
        else{
          toSouth(p.x,p.y);
        }
        break;
      case 2:
        if(p.dir == 0){
          toWest(p.x, p.y);
          toEast(p.x, p.y);
        }
        else{
          toNorth(p.x, p.y);
          toSouth(p.x, p.y);
        }
        break;
      case 3:
        if(p.dir == 0){
          toNorth(p.x, p.y);
          toEast(p.x, p.y);
        }
        else if(p.dir == 1){
          toEast(p.x, p.y);
          toSouth(p.x, p.y);
        }
        else if(p.dir == 2){
          toSouth(p.x, p.y);
          toWest(p.x, p.y);
        }
        else{
          toWest(p.x, p.y);
          toNorth(p.x, p.y);
        }
        break;
      case 4:
        if(p.dir == 0){
          toWest(p.x, p.y);
          toNorth(p.x, p.y);
          toEast(p.x, p.y);
        }
        else if(p.dir == 1){
          toNorth(p.x, p.y);
          toEast(p.x, p.y);
          toSouth(p.x, p.y);
        }
        else if(p.dir == 2){
          toEast(p.x, p.y);
          toSouth(p.x, p.y);
          toWest(p.x, p.y);
        }
        else{
          toSouth(p.x, p.y);
          toWest(p.x, p.y);
          toNorth(p.x, p.y);
        }
        break;
      case 5:
        toEast(p.x, p.y);
        toSouth(p.x, p.y);
        toWest(p.x, p.y);
        toNorth(p.x, p.y);
        break;
    }
  }


  // check the space
  int cnt = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(a[i][j] == 0 && check[i][j] == 0){
        cnt++;
      }
    }
  }
  return cnt;
}
void go(int idx){
  if(idx == c.size()){
    int cnt = cntSpace();
    if(ans > cnt){
      ans = cnt;
    }
    return;
  }
  switch(c[idx].num){
    case 1:
      c[idx].dir = 0;
      go(idx + 1);
      c[idx].dir = 1;
      go(idx + 1);
      c[idx].dir = 2;
      go(idx + 1);
      c[idx].dir = 3;
      go(idx + 1);
      break;
    case 2:
      c[idx].dir = 0;
      go(idx + 1);
      c[idx].dir = 1;
      go(idx + 1);
      break;
    case 3:
      c[idx].dir = 0;
      go(idx + 1);
      c[idx].dir = 1;
      go(idx + 1);
      c[idx].dir = 2;
      go(idx + 1);
      c[idx].dir = 3;
      go(idx + 1);
      break;
    case 4:
      c[idx].dir = 0;
      go(idx + 1);
      c[idx].dir = 1;
      go(idx + 1);
      c[idx].dir = 2;
      go(idx + 1);
      c[idx].dir = 3;
      go(idx + 1);
      break;
    case 5:
      go(idx + 1);
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> a[i][j];
      if(a[i][j] != 0 && a[i][j] != 6){
        c.push_back({i,j,a[i][j],-1});
      }
    }
  }

  go(0);

  cout << ans << '\n';

  return 0;
}
