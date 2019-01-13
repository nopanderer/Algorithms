/**
 * 별 찍기 - 10
 * 2447
 */
#include <iostream>
using namespace std;
int N;
char a[9*9*9*9][9*9*9*9];
void star(int x,int y,int n){
  if(n == 1){
    a[x][y] = '*';
  }
  else{
    for(int i=x+n/3;i<x+n/3+n/3;i++){
      for(int j=y+n/3;j<y+n/3+n/3;j++){
        a[i][j] = ' ';
      }
    }
    star(x,y,n/3);
    star(x,y+n/3,n/3);
    star(x,y+n/3+n/3,n/3);
    star(x+n/3,y,n/3);
    star(x+n/3,y+n/3+n/3,n/3);
    star(x+n/3+n/3,y,n/3);
    star(x+n/3+n/3,y+n/3,n/3);
    star(x+n/3+n/3,y+n/3+n/3,n/3);
  }
}
int main(){
  cin>>N;
  star(0,0,N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<a[i][j];
    }
    cout<<'\n';
  }

  return 0;
}
