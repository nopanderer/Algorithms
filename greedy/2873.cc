/**
 * 롤러코스터
 * 2873
 */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
  int R,C;
  int a[1001][1001];
  string ans = "";
  cin>>R>>C;
  int min=987654321;
  int x,y;
  int ax=0, ay=0;
  int bx=R-1,by=C-1;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin>>a[i][j];
    }
  }
  if(R%2 != 0){
    for(int i=0;i<R;i++){
      for(int j=0;j<C-1;j++){
        if(i%2 == 0){
          ans += 'R';
        }
        else{
          ans += 'L';
        }
      }
      if(i != R-1){
        ans += 'D';
      }
    }
  }
  else if(R%2 == 0 && C%2 != 0){
    for(int i=0;i<C;i++){
      for(int j=0;j<R-1;j++){
        if(i%2 == 0){
          ans += 'D';
        }
        else{
          ans += 'U';
        }
      }
      if(i != C-1){
        ans += 'R';
      }
    }
  }
  else{
    // cannot visit all blocks
    // 1. find minimum block
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        if((i+j)%2 != 0 && a[i][j] < min){
          min = a[i][j];
          x = i;
          y = j;
        }
      }
    }
    // 2. find the path
    // 2.1 Check all columns
    string sa="";
    string sb="";
    while(bx-ax > 1){
      if(ax/2 < x/2){
        for(int i=0;i<C-1;i++){
          sa += 'R';
        }
        sa += 'D';
        for(int i=0;i<C-1;i++){
          sa += 'L';
        }
        sa += 'D';
        ax += 2;
      }
      if(x/2 < bx/2){
        for(int i=0;i<C-1;i++){
          sb += 'R';
        }
        sb += 'D';
        for(int i=0;i<C-1;i++){
          sb += 'L';
        }
        sb += 'D';
        bx -= 2;
      }
    }
    // 2.2 Check all rows
    while(by-ay > 1){
      if(ay/2 < y/2){
        sa += 'D';
        sa += 'R';
        sa += 'U';
        sa += 'R';
        ay += 2;
      }
      if(y/2 < by/2){
        sb += 'D';
        sb += 'R';
        sb += 'U';
        sb += 'R';
        by -= 2;
      }
    }
    if(x == ax) sa += "DR";
    else sa += "RD";
    reverse(sb.begin(),sb.end());
    ans = sa + sb;
  }
  cout<<ans<<'\n';

  return 0;
}
