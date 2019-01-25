/**
 * N-Queen
 * 9663
 */
#include <iostream>
using namespace std;
int n;
int ans;
bool a[15][15];
bool check(int row, int col){
  int r,c;
  // | case
  for(int i=0;i<row;i++){
    if(a[i][col]) return true;
  }
  // \ case
  r = row-1, c = col-1;
  while(r >= 0 && c >= 0){
    if(a[r][c]) return true;
    r--,c--;
  }
  // / case
  r = row-1, c = col+1;
  while(r >= 0 && c < n){
    if(a[r][c]) return true;
    r--,c++;
  }
  return false;
}
void go(int row){
  if(row == n){
    ans++;
    return;
  }
  for(int col=0;col<n;col++){
    a[row][col] = true;
    if(!check(row,col)){
      go(row+1);
    }
    a[row][col] = false;
  }
}
int main(){
  cin>>n;
  go(0);
  cout<<ans<<'\n';
  
  return 0;
}
