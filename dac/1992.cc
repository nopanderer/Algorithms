/**
 * 쿼드트리
 * 1992
 */
#include <iostream>
#include <string>
using namespace std;
int N;
int a[65][65];
bool same(int x,int y,int n){
  int d = a[x][y];
  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(d != a[i][j]){
        return false;
      }
    }
  }
  return true;
}
void go(int x,int y,int n){
  int d = a[x][y];
  if(same(x,y,n)){
    cout<<d;
  }
  // split into four
  else{
    cout<<'(';
    go(x,y,n/2);
    go(x,y+n/2,n/2);
    go(x+n/2,y,n/2);
    go(x+n/2,y+n/2,n/2);
    cout<<')';
  }
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    for(int j=0;j<N;j++){
      a[i][j] = s[j]-'0';
    }
  }
  go(0,0,N);

  return 0;
}
