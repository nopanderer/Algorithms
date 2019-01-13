/**
 * 별 찍기 - 11
 * 2448
 */
#include <iostream>
using namespace std;
int N;
char a[7000][7000];
void star(int x,int y,int n){
  if(n==3){
    a[x][y] = '*';
    a[x+1][y-1] = '*';
    a[x+1][y] = ' ';
    a[x+1][y+1] = '*';
    a[x+2][y-2] = '*';
    a[x+2][y-1] = '*';
    a[x+2][y] = '*';
    a[x+2][y+1] = '*';
    a[x+2][y+2] = '*';
  }
  else{
    star(x,y,n/2);
    star(x+n/2,y-n/2,n/2);
    star(x+n/2,y+n/2,n/2);
  }
}
int main(){
  cin>>N;
  star(0,N-1,N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N*2-1;j++){
      if(a[i][j] == 0){
        cout<<' ';
      }
      else{
        cout<<a[i][j];
      }
    }
    cout<<'\n';
  }
  return 0;
}
