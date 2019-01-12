/**
 * 종이의 개수
 * 1780
 */
#include <iostream>
using namespace std;
int N;
int a[5000][5000];
int cnt[3];
void paper(int x,int y,int n){
  bool same = true;
  int target = a[x][y];
  for(int i=x;i<x+n && same;i++){
    for(int j=y;j<y+n;j++){
      if(a[i][j] != target){
        same = false;
        break;
      }
    }
  }
  if(same){
    cnt[target+1]++;
  }
  else{
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        paper(x+i*(n/3),y+j*(n/3),n/3);
      }
    }
  }
}
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>a[i][j];
    }
  }
  paper(0,0,N);
  for(int i=0;i<3;i++){
    cout<<cnt[i]<<'\n';
  }

  return 0;
}
