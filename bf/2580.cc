/**
 * 스도쿠
 * 2580
 */
#include <iostream>
using namespace std;
int a[10][10];
bool c1[10][10];
bool c2[10][10];
bool c3[10][10];
bool go(int z){
  if(z==81){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<a[i][j]<<' ';
      }
      cout<<'\n';
    }
    return true;
  }
  int x = z/9, y = z%9;
  if(a[x][y] != 0){
    return go(z+1);
  }
  else{
    for(int i=1;i<10;i++){
      if(!c1[x][i] && !c2[y][i] && !c3[(x/3)*3+(y/3)][i]){
        c1[x][i] = c2[y][i] = c3[(x/3)*3+(y/3)][i] = true;
        a[x][y] = i;
        if(go(z+1)) return true;
        a[x][y] = 0;
        c1[x][i] = c2[y][i] = c3[(x/3)*3+(y/3)][i] = false;
      }
    }
  }
  return false;
}
int main(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      int num;
      cin>>num;
      a[i][j] = num;
      if(num){
        c1[i][num] = true;
        c2[j][num] = true;
        c3[(i/3)*3+(j/3)][num] = true;
      }
    }
  }
  go(0);
  
  return 0;
}
