/**
 * 알파벳
 * 1987
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int R,C;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int go(int x, int y, vector<string> &a, vector<bool> &c){
  int ans = 0;
  for(int i=0;i<4;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(0<=nx && nx<R && 0<=ny && ny<C){
      if(c[a[nx][ny]-'A'] == false){
        c[a[nx][ny]-'A'] = true;
        int next = go(nx,ny,a,c);
        if(next > ans) ans = next;
        c[a[nx][ny]-'A'] = false;
      }
    }
  }
  return ans+1;
}
int main(){
  cin>>R>>C;
  vector<string> a(R);
  vector<bool> c(26);
  for(int i=0;i<R;i++){
    cin>>a[i];
  }
  c[a[0][0]-'A'] = true;
  cout<<go(0,0,a,c)<<'\n';

  return 0;
}

